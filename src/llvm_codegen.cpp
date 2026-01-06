/*
    Implementation of "llvm_codegen.hpp"
*/

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/TargetSelect.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/MC/TargetRegistry.h"

#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/Analysis/CGSCCPassManager.h"

#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/OptimizationLevel.h"

#include "llvm_codegen.hpp"

extern "C" {
    #include "semantic_types.h"
    #include "ast.h"
    #include "error_handling.h"
    #include "string_helpers.h"
    #include "decl_type.h"
}

#include <vector>
#include <memory>
#include <map>
#include <stack>
#include <string.h>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace llvm;

// Template uses T but the actual data structure will always use T*
namespace {
    template <typename T>
    class scope_stack {
        std::vector<std::map<std::string, T *>> vals;
    public:
        T *find(const std::string &name) const {
            for (int i=static_cast<int>(vals.size()-1); i>=0; i--) {
                auto it = vals[i].find(name);
                if (it != vals[i].end()) return it->second;
            }
            return nullptr;
        }

        T *operator[](const std::string &name) const {
            return find(name);
        }

        T *operator[](const char *name) const {
            std::string s(name);
            return find(s);
        }

        void push(const std::string name, T *val) {
            vals.back().emplace(std::move(name), std::move(val));
        }

        void push_scope() {
            vals.emplace_back();
        }

        void pop_scope() {
            vals.pop_back();
        }

        void print_defined() {
            for (int i=static_cast<int>(vals.size()-1); i>=0; i--) {
                std::cout << "Scope level: " << i << "\n";
                for (auto [name, val] : vals[i]) {
                    std::cout << name << "\n";
                }
            }
        }
    };
}

static std::unique_ptr<LLVMContext> context;
static std::unique_ptr<IRBuilder<>> builder;
static std::unique_ptr<Module> llvm_module;
static scope_stack<Value> named_values;
static scope_stack<BasicBlock> labels;
static std::stack<BasicBlock *> break_dest;
static std::stack<BasicBlock *> continue_dest;
static std::stack<SwitchInst *> switch_stmts;
static std::map<sem_sou_info_t *, StructType *> sem_struct_to_llvm;
static std::map<sem_sou_info_t *, StructType *> sem_union_to_llvm;

static Type *sem_type_to_llvm(sem_type_t *t);
static Value *expr_codegen(expr *e);
static void block_codegen(block_list *b);
static void stmt_codegen(stmt *s);
static void decl_codegen(decl *d, bool is_global);

static void push_scope() {
    named_values.push_scope();
    labels.push_scope();
}

static void pop_scope() {
    named_values.pop_scope();
    labels.pop_scope();
}

// Returns true if successful and false if the current block already has a terminator
// Pretty much only necessary to check if the current block ends with a return statement
static inline bool branch_to(BasicBlock *dest) {
    if (builder->GetInsertBlock()->getTerminator()) return false;
    builder->CreateBr(dest);
    return true;
}

// Converts an integer value to a boolean
static inline Value *force_bool(Value *v) {
    Type *t = v->getType();
    if (t->isIntegerTy(1)) {
        return v;
    }

    if (t->isIntegerTy()) {
        v = builder->CreateICmpNE(v, ConstantInt::get(t, 0), "condtmp");
    } else if (t->isFloatingPointTy()) {
        v = builder->CreateFCmpONE(v, ConstantFP::get(t, 0.0), "condtmp");
    } else if (t->isPointerTy()) {
        Value *nullp = ConstantPointerNull::get(cast<PointerType>(t));
        v = builder->CreateICmpNE(v, nullp, "condtmp");
    } else {
        Type *intptr = IntegerType::get(*context, llvm_module->getDataLayout().getPointerSizeInBits());
        Value *as_int = builder->CreatePtrToInt(v, intptr);
        v = builder->CreateICmpNE(as_int, ConstantInt::get(intptr, 0), "condtmp");
    }
    return v;
}

static StructType *get_or_create_struct_type(sem_type_t *sou_type) {
    if (!sou_type) return nullptr;
    if (sou_type->kind != ST_STRUCT && sou_type->kind != ST_UNION) return nullptr;

    auto it = sem_struct_to_llvm.find(sou_type->sou_info);
    if (it != sem_struct_to_llvm.end()) return it->second;
    
    StructType *llvm_struct = nullptr;
    if (sou_type->kind == ST_STRUCT) {
        std::vector<Type *> members;
        for (sem_member_t *mem = sou_type->sou_info->members; mem; mem = mem->next) {
            members.push_back(sem_type_to_llvm(mem->type));
        }

        llvm_struct = StructType::get(*context, members);
        sem_struct_to_llvm[sou_type->sou_info] = llvm_struct;
    } else {
        const DataLayout &layout = llvm_module->getDataLayout();
        Type *largest = nullptr;

        for (sem_member_t *mem = sou_type->sou_info->members; mem; mem = mem->next) {
            Type *new_type = sem_type_to_llvm(mem->type);
            if (layout.getTypeAllocSize(new_type) > layout.getTypeAllocSize(largest)) {
                largest = new_type;
            }
        }

        llvm_struct = StructType::get(*context, largest);
        sem_union_to_llvm[sou_type->sou_info] = llvm_struct;
    }
    return llvm_struct;
}

static int get_member_index_by_name(sem_sou_info_t *sou, const char *name) {
    if (!sou) return -1;
    int idx = 0;
    for (sem_member_t *m = sou->members; m; m = m->next, idx++) {
        if (m->name && name && strcmp(m->name, name) == 0) return idx;
    }
    return -1;
}

static Type *sem_type_to_llvm(sem_type_t *t) {
    if (!t) {
        write_module_to_file(*llvm_module, "llvm_error_module.ll");
    }
    assert(t);
    switch (t->kind) {
        case ST_CHAR:       return IntegerType::get(*context, 8);
        case ST_SHORT:      return IntegerType::get(*context, 16);
        case ST_INT:        return IntegerType::get(*context, 32);
        case ST_LONG:       return IntegerType::get(*context, 64);
        case ST_LL:         return IntegerType::get(*context, 64);
        case ST_BOOL:       return Type::getInt1Ty(*context);
        case ST_FLOAT:      return Type::getFloatTy(*context);
        case ST_DOUBLE:     return Type::getDoubleTy(*context);
        case ST_VOID:       return Type::getVoidTy(*context);
        case ST_POINTER:    return PointerType::get(*context, 0);
        case ST_ARRAY: {
            Type *element_type = sem_type_to_llvm(t->arr_info.element_type);
            return ArrayType::get(element_type, t->arr_info.size);
        }
        case ST_STRUCT:
        case ST_UNION: {
            assert(t->sou_info->complete);
            return get_or_create_struct_type(t);
        }
        case ST_FUNC: {
            Type *ret = sem_type_to_llvm(t->func_info.return_type);
            std::vector<Type *> params;
            for (sem_type_list_t *tl = t->func_info.params; tl; tl = tl->next) {
                params.push_back(sem_type_to_llvm(tl->type));
            }
            FunctionType *ft = FunctionType::get(ret, params, t->func_info.variadic);
            return ft;
        }
        default:
            return IntegerType::get(*context, 32);
    }
}

static Constant *constant_to_llvm(constant *c, sem_type_t *t) {
    if (t->kind == ST_FLOAT) {
        return ConstantFP::get(Type::getFloatTy(*context), c->val.f_val);
    } else if (t->kind == ST_DOUBLE) {
        return ConstantFP::get(Type::getDoubleTy(*context), c->val.d_val);
    } else if (t->kind == ST_BOOL) {
        uint64_t val = c->val.ui_val ? 1ull : 0ull;
        return ConstantInt::get(Type::getInt1Ty(*context), val, false);
    } else if (type_is_integral(t)) {
        unsigned int num_bits = 32;
        switch (t->kind) {
            case ST_CHAR:   num_bits = 8; break;
            case ST_SHORT:  num_bits = 16; break;
            case ST_INT:    num_bits = 32; break;
            case ST_LONG:   num_bits = 64; break;
            case ST_LL:     num_bits = 64; break;
            default:        num_bits = 32; break;
        }
        return ConstantInt::get(IntegerType::get(*context, num_bits), c->val.bits, t->is_signed);
    } else if (t->kind == ST_POINTER) {
        uint64_t bits = c->val.bits;
        IntegerType *int_type = IntegerType::get(*context, sizeof(intptr_t));
        ConstantInt *const_int = ConstantInt::get(int_type, bits);
        Type *ptr_type = sem_type_to_llvm(t);
        return ConstantExpr::getIntToPtr(const_int, ptr_type);
    } else {
        return ConstantInt::get(IntegerType::get(*context, 32), 0);
    }
}

static Value *expr_codegen_lvalue(expr *e) {
    if (!e) return nullptr;

    switch (e->kind) {
        case EXPR_ID: {
            Value *v = named_values[e->extra.id];
            assert(v);
            return v;
        }
        case EXPR_DEREF: {
            Value *ptr = expr_codegen(e->left);
            return ptr;
        }
        case EXPR_SUBSCRIPT: {
            Value *base = expr_codegen_lvalue(e->left);
            Value *idx = expr_codegen(e->right);
            sem_type_t *base_type = e->left->type;
            assert(base && idx);

            Type *element_type = nullptr;
            if (base_type->kind == ST_ARRAY) {
                element_type = sem_type_to_llvm(base_type->arr_info.element_type);
            } else {
                element_type = sem_type_to_llvm(base_type->ptr_target);
            }

            if (!idx->getType()->isIntegerTy(64)) {
                idx = builder->CreateIntCast(idx, IntegerType::get(*context, 64), true);
            }

            return builder->CreateInBoundsGEP(element_type, base, idx);
        }
        case EXPR_MEMBER_DOT:
        case EXPR_MEMBER_ARROW: {
            sem_type_t *sou_type = e->left->type;
            Type *t = sem_type_to_llvm(sou_type);
            Value *sou = expr_codegen_lvalue(e->left);
            if (e->left->type->kind == ST_STRUCT) {
                int idx = get_member_index_by_name(sou_type->sou_info, e->right->extra.id);
                return builder->CreateStructGEP(t, sou, idx);
            } else {
                return builder->CreateBitCast(sou, PointerType::get(*context, 0), "union.bitcast");
            }
        }
        default:
            return nullptr;
    }
}

static std::string prepare_str_literal(const char *s) {
    if (!s) return {};
    std::string out;
    size_t len = std::strlen(s);
    out.reserve(len);

    for (size_t i = 1; i<len-1;) {
        char c = s[i];
        if (c == '\\') {
            // If backslash is last char, keep it
            if (s[i+1] == '\0') {
                out.push_back('\\');
                break;
            }
            char next = s[i+1];
            switch (next) {
                case 'a': out.push_back('\a'); i += 2; break;
                case 'b': out.push_back('\b'); i += 2; break;
                case 'f': out.push_back('\f'); i += 2; break;
                case 'n': out.push_back('\n'); i += 2; break;
                case 'r': out.push_back('\r'); i += 2; break;
                case 't': out.push_back('\t'); i += 2; break;
                case 'v': out.push_back('\v'); i += 2; break;
                case '\\': out.push_back('\\'); i += 2; break;
                case '\'': out.push_back('\''); i += 2; break;
                case '\"': out.push_back('\"'); i += 2; break;
                case '?': out.push_back('\?'); i += 2; break;
                case '0': out.push_back('\0'); i += 2; break; // single '\0'
                default:
                    // Unknown escape: preserve the backslash and continue so the
                    // next character will be processed normally on the next loop.
                    out.push_back('\\');
                    ++i;
                    break;
            }
        } else {
            out.push_back(c);
            ++i;
        }
    }

    return out;
}

static Value *expr_codegen(expr *e) {
    if (!e) return nullptr;

    switch (e->kind) {
        case EXPR_CONST: {
            sem_type_t *t = e->type;
            Constant *c = constant_to_llvm(e->extra.const_val, t);
            return c;
        }
        case EXPR_STR_LITERAL: {
            std::string prepared_literal = prepare_str_literal(e->extra.str_val);
            return builder->CreateGlobalString(prepared_literal, "str_lit");
        }
        case EXPR_ID: {
            Value *addr = named_values[e->extra.id];
            assert(addr);
            if (!addr->getType()->isPointerTy()) return addr;
            
            Type *t = sem_type_to_llvm(e->type);
            
            // Arrays decay to pointers as rvalues
            if (t->isArrayTy()) {
                return addr;
            }
            
            return builder->CreateLoad(t, addr, std::string(e->extra.id));
        }

        case EXPR_CALL: {
            std::vector<Value *> args;

            Value *callee = expr_codegen_lvalue(e->left);
            FunctionType *callee_type = cast<FunctionType>(sem_type_to_llvm(e->left->type));

            assert(callee);
            assert(callee_type);

            unsigned int i = 0;
            expr *arg_node = e->right;
            expr *curr = arg_node;
            while (curr) {
                Value *arg = nullptr;
                if (i < callee_type->getNumParams()) {
                    Type *param_type = callee_type->getParamType(i);
                    if (param_type->isPointerTy()) {
                        if (
                            sem_type_to_llvm(curr->left->type)->isArrayTy() &&
                            curr->left->kind != EXPR_STR_LITERAL
                        ) {
                            arg = expr_codegen_lvalue(curr->left);
                        }
                    }
                    i++;
                }
                if (!arg) arg = expr_codegen(curr->left);
                args.push_back(arg);
                curr = curr->right;
            }

            return builder->CreateCall(callee_type, callee, args, "calltmp");
        }

        case EXPR_SUBSCRIPT:
        case EXPR_MEMBER_DOT:
        case EXPR_MEMBER_ARROW: {
            Value *addr = expr_codegen_lvalue(e);
            if (!addr) return nullptr;
            Type *t = sem_type_to_llvm(e->type);
            return builder->CreateLoad(t, addr);
        }

        case EXPR_DEREF: {
            Value *v = expr_codegen_lvalue(e->left);
            Type *t = sem_type_to_llvm(e->type);
            assert(v && t);
            t->print(outs());
            std::cout << type_to_s(e->type) << std::endl;
            return builder->CreateLoad(t, v);
        }
        case EXPR_ADDREF: {
            return expr_codegen_lvalue(e->left);
        }

        case EXPR_ASSIGN: {
            Value *lval = expr_codegen_lvalue(e->left);
            Value *rval = expr_codegen(e->right);
            assert(lval);
            assert(rval);
            Type *ltype = sem_type_to_llvm(e->left->type);
            Type *rtype = rval->getType();
            if (ltype != rtype) {
                // Cast rval to ltype
                if (ltype->isIntegerTy() && rtype->isIntegerTy()) {
                    rval = builder->CreateIntCast(rval, ltype, e->left->type->is_signed);
                } else if (ltype->isFloatingPointTy() && rtype->isFloatingPointTy()) {
                    // Adjust precision
                    if (ltype->getPrimitiveSizeInBits() < rtype->getPrimitiveSizeInBits()) {
                        rval = builder->CreateFPTrunc(rval, ltype);
                    } else {
                        rval = builder->CreateFPExt(rval, ltype);
                    }
                }
                // ???
                return nullptr;
            }
            builder->CreateStore(rval, lval);
            return rval;
        }

        // Normal binary operations
        case EXPR_ADD:
        case EXPR_SUB:
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
        case EXPR_LSHIFT:
        case EXPR_RSHIFT:
        case EXPR_BITAND:
        case EXPR_BITXOR:
        case EXPR_BITOR: {
            Value *l = expr_codegen(e->left);
            Value *r = expr_codegen(e->right);
            assert(l);
            assert(r);

            sem_type_t *t = e->type;
            if (type_is_float(t)) {
                switch (e->kind) {
                    case EXPR_ADD: return builder->CreateFAdd(l, r, "faddtmp");
                    case EXPR_SUB: return builder->CreateFSub(l, r, "fsubtmp");
                    case EXPR_MUL: return builder->CreateFMul(l, r, "fmultmp");
                    case EXPR_DIV: return builder->CreateFDiv(l, r, "fdivtmp");
                    // Wow! C doesn't have this!
                    case EXPR_MOD: return builder->CreateFRem(l, r, "fmodtmp");
                    default:;
                }
            } else if (t->kind == ST_POINTER) {
                // Handle pointer arithmetic later
            } else {
                switch (e->kind) {
                    case EXPR_ADD:  return builder->CreateAdd(l, r, "addtmp");
                    case EXPR_SUB:  return builder->CreateSub(l, r, "subtmp");
                    case EXPR_MUL:  return builder->CreateMul(l, r, "multmp");
                    case EXPR_DIV:
                        if (e->left->type->is_signed) {
                            return builder->CreateSDiv(l, r, "sdivtmp");
                        } else {
                            return builder->CreateUDiv(l, r, "udivtmp");
                        }
                    case EXPR_MOD:
                        if (e->left->type->is_signed) {
                            return builder->CreateSRem(l, r, "smodtmp");
                        } else {
                            return builder->CreateURem(l, r, "umodtmp");
                        }
                    case EXPR_LSHIFT:   return builder->CreateShl(l, r, "shltmp");
                    case EXPR_RSHIFT:
                        if (e->left->type->is_signed) {
                            return builder->CreateAShr(l, r, "ashrtmp");
                        } else {
                            return builder->CreateLShr(l, r, "lshrtmp");
                        }
                    case EXPR_BITAND:   return builder->CreateAnd(l, r, "andtmp");
                    case EXPR_BITXOR:   return builder->CreateXor(l, r, "xortmp");
                    case EXPR_BITOR:    return builder->CreateOr(l, r, "ortmp");
                    default: break; 
                }
            }
            // ???
            return nullptr;
        }

        case EXPR_LT:
        case EXPR_GT:
        case EXPR_LEQ:
        case EXPR_GEQ:
        case EXPR_EQ:
        case EXPR_NEQ: {
            Value *l = expr_codegen(e->left);
            Value *r = expr_codegen(e->right);
            assert(l);
            assert(r);

            Type *ltype = l->getType();
            Type *rtype = r->getType();

            // This technically allows you to compare pointer to float if the error is not caught
            if (ltype->isPointerTy()) {
                l = builder->CreatePtrToInt(l, IntegerType::get(*context, 64));
                ltype = l->getType();
            }
            if (rtype->isPointerTy()) {
                r = builder->CreatePtrToInt(r, IntegerType::get(*context, 64));
                rtype = r->getType();
            }

            if (ltype->isFloatingPointTy() || rtype->isFloatingPointTy()) {
                if (!ltype->isFloatingPointTy()) {
                    if (e->left->type->is_signed) {
                        l = builder->CreateSIToFP(l, rtype);
                        ltype = l->getType();
                    } else {
                        l = builder->CreateUIToFP(l, rtype);
                        ltype = l->getType();
                    }
                }
                if (!rtype->isFloatingPointTy()) {
                    if (e->right->type->is_signed) {
                        r = builder->CreateSIToFP(r, ltype);
                        rtype = r->getType();
                    } else {
                        r = builder->CreateUIToFP(r, ltype);
                        rtype = r->getType();
                    }
                }

                // Promote one of them if necessary
                if (ltype != rtype) {
                    if (ltype->getPrimitiveSizeInBits() < rtype->getPrimitiveSizeInBits()) {
                        l = builder->CreateFPExt(l, rtype, "fpext");
                        ltype = l->getType();
                    } else {
                        r = builder->CreateFPExt(r, ltype, "fpext");
                        rtype = r->getType();
                    }
                }

                CmpInst::Predicate pred = CmpInst::FCMP_FALSE;
                switch (e->kind) {
                    case EXPR_LT:   pred = CmpInst::FCMP_OLT; break;
                    case EXPR_GT:   pred = CmpInst::FCMP_OGT; break;
                    case EXPR_LEQ:  pred = CmpInst::FCMP_OLE; break;
                    case EXPR_GEQ:  pred = CmpInst::FCMP_OGE; break;
                    case EXPR_EQ:   pred = CmpInst::FCMP_OEQ; break;
                    case EXPR_NEQ:  pred = CmpInst::FCMP_ONE; break;
                    default:;
                }
                return builder->CreateFCmp(pred, l, r, "fcmp");
            } else if (ltype->isIntegerTy() && rtype->isIntegerTy()) {
                CmpInst::Predicate pred = CmpInst::ICMP_EQ;
                bool is_signed = e->left->type->is_signed;
                switch (e->kind) {
                    case EXPR_LT:   pred = is_signed ? CmpInst::ICMP_SLT : CmpInst::ICMP_ULT; break;
                    case EXPR_GT:   pred = is_signed ? CmpInst::ICMP_SGT : CmpInst::ICMP_UGT; break;
                    case EXPR_LEQ:  pred = is_signed ? CmpInst::ICMP_SLE : CmpInst::ICMP_ULE; break;
                    case EXPR_GEQ:  pred = is_signed ? CmpInst::ICMP_SGE : CmpInst::ICMP_UGE; break;
                    case EXPR_EQ:   pred = CmpInst::ICMP_EQ; break;
                    case EXPR_NEQ:  pred = CmpInst::ICMP_NE; break;
                    default:;
                }
                return builder->CreateICmp(pred, l, r, "icmp");
            }
        }

        case EXPR_LOGAND:
        case EXPR_LOGOR: {
            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *left_block = builder->GetInsertBlock();
            BasicBlock *right_block = BasicBlock::Create(*context, "logic.rhs", curr_func);
            BasicBlock *cont_block = BasicBlock::Create(*context, "logic.cont", curr_func);

            Value *l = expr_codegen(e->left);
            assert(l);
            l = force_bool(l);

            if (e->kind == EXPR_LOGAND) {
                builder->CreateCondBr(l, right_block, cont_block);
            } else {
                builder->CreateCondBr(l, cont_block, right_block);
            }

            builder->SetInsertPoint(right_block);
            Value *r = expr_codegen(e->right);
            assert(r);
            r = force_bool(r);

            builder->CreateBr(cont_block);
            builder->SetInsertPoint(cont_block);
            PHINode *phi = nullptr;
            Type *i1_type = Type::getInt1Ty(*context);
            if (e->kind == EXPR_LOGAND) {
                phi = builder->CreatePHI(i1_type, 2, "logic.and");
                phi->addIncoming(ConstantInt::get(i1_type, 0), left_block);
                phi->addIncoming(r, right_block);
            } else {
                phi = builder->CreatePHI(i1_type, 2, "logic.or");
                phi->addIncoming(ConstantInt::get(i1_type, 1), left_block);
                phi->addIncoming(r, right_block);
            }
            return phi;
        }

        case EXPR_CONDITIONAL: {
            Value *cond = expr_codegen(e->extra.conditional);
            assert(cond);
            cond = force_bool(cond);

            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *then_block = BasicBlock::Create(*context, "tern.then", curr_func);
            BasicBlock *else_block = BasicBlock::Create(*context, "tern.else", curr_func);
            BasicBlock *merge_block = BasicBlock::Create(*context, "tern.merge", curr_func);

            builder->CreateCondBr(cond, then_block, else_block);

            // Handle then block
            builder->SetInsertPoint(then_block);
            Value *then_v = expr_codegen(e->left);
            builder->CreateBr(merge_block);

            // Handle else block
            builder->SetInsertPoint(else_block);
            Value *else_v = expr_codegen(e->right);
            builder->CreateBr(merge_block);

            // Handle merge block
            builder->SetInsertPoint(merge_block);
            Type *t = sem_type_to_llvm(e->type);
            PHINode *phi = builder->CreatePHI(t, 2, "ternphi");
            phi->addIncoming(then_v, then_block);
            phi->addIncoming(else_v, else_block);
            return phi;
        }

        case EXPR_PRE_INCR:
        case EXPR_PRE_DECR:
        case EXPR_POST_INCR:
        case EXPR_POST_DECR: {
            Value *lval = expr_codegen_lvalue(e->left);
            assert(lval);

            Type *t = sem_type_to_llvm(e->left->type);
            Value *curr = builder->CreateLoad(t, lval, "incr.load");
            Value *one = nullptr;
            if (t->isIntegerTy()) {
                one = ConstantInt::get(t, 1);
            } else {
                one = ConstantFP::get(t, 1.0);
            }

            Value *updated = nullptr;
            if (e->kind == EXPR_PRE_INCR || e->kind == EXPR_POST_INCR) {
                updated = t->isFloatingPointTy() ?
                    builder->CreateFAdd(curr, one, "faddtmp") :
                    builder->CreateAdd(curr, one, "addtmp");
            } else {
                updated = t->isFloatingPointTy() ?
                    builder->CreateFSub(curr, one, "fsubtmp") :
                    builder->CreateAdd(curr, one, "subtmp");
            }

            builder->CreateStore(updated, lval);
            if (e->kind == EXPR_PRE_INCR || e->kind == EXPR_PRE_DECR) {
                return updated;
            } else {
                return curr;
            }
        }

        case EXPR_CAST: {
            Value *v = expr_codegen(e->left);
            assert(v);

            Type *from = v->getType();
            Type *to = sem_type_to_llvm(e->type);
            if (from == to) return v;

            // Float to float and int to int
            if (from->isFloatingPointTy() && to->isFloatingPointTy()) {
                if (from->getPrimitiveSizeInBits() < to->getPrimitiveSizeInBits()) {
                    return builder->CreateFPExt(v, to, "fpext");
                } else {
                    return builder->CreateFPTrunc(v, to, "fptrunc");
                }
            } else if (from->isIntegerTy() && to->isIntegerTy()) {
                return builder->CreateIntCast(v, to, e->type->is_signed, "intcast");
            }
            // int to float and float to int
            else if (from->isIntegerTy() && to->isFloatingPointTy()) {
                if (e->left->type->is_signed) {
                    return builder->CreateSIToFP(v, to, "sitofp");
                } else {
                    return builder->CreateUIToFP(v, to, "uitofp");
                }
            } else if (from->isFloatingPointTy() && to->isFloatingPointTy()) {
                if (e->type->is_signed) {
                    return builder->CreateFPToSI(v, to, "fptosi");
                } else {
                    return builder->CreateFPToUI(v, to, "fptoui");
                }
            }
            // int to ptr and ptr to int
            else if (from->isIntegerTy() && to->isPointerTy()) {
                return builder->CreateIntToPtr(v, to, "inttoptr");
            } else if (from->isPointerTy() && to->isIntegerTy()) {
                return builder->CreatePtrToInt(v, to, "ptrtoint");
            }
            // ptr to ptr, but all LLVM pointers are opaque
            else if (from->isPointerTy() && to->isPointerTy()) {
                return v;
            }

            // ???
            return nullptr;
        }

        case EXPR_LOGNOT: {
            Value *v = expr_codegen(e->left);
            assert(v);
            if (v->getType()->isIntegerTy(1)) {
                return builder->CreateNot(v, "lognot");
            } else {
                return builder->CreateICmpEQ(v, ConstantInt::get(v->getType(), 0), "lnotcmp");
            }
        }

        case EXPR_BITNOT: {
            Value *v = expr_codegen(e->left);
            assert(v);
            return builder->CreateNot(v, "bitnottmp");
        }

        case EXPR_SIZEOF_EXPR:
        case EXPR_SIZEOF_TYPE: {
            const DataLayout &layout = llvm_module->getDataLayout();
            Type *t = nullptr;
            if (e->kind == EXPR_SIZEOF_EXPR) {
                t = sem_type_to_llvm(e->left->type);
            } else {
                t = sem_type_to_llvm(e->extra.tn_type);
            }
            return ConstantInt::get(IntegerType::get(*context, 64), layout.getTypeAllocSize(t));
        }

        default: return nullptr;
    }
}

static void block_codegen(block_list *b) {
    push_scope();

    for (block_list *curr = b; curr; curr = curr->next) {
        if (curr->kind == BI_STMT) {
            stmt_codegen(curr->stmt);
        } else {
            decl_codegen(curr->decl, false);
        }
    }

    pop_scope();
}

static void stmt_codegen(stmt *s) {
    if (!s) return;
    if (builder->GetInsertBlock()->getTerminator()) return;

    switch (s->kind) {
        case STMT_EXPR:     expr_codegen(s->expr_stmt); break;
        case STMT_COMPOUND: block_codegen(s->compound_stmt.items); break;
        case STMT_IF: {
            Value *cond = expr_codegen(s->conditional_stmt.cond);
            cond = force_bool(cond);

            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *then_block = BasicBlock::Create(*context, "if.then", curr_func);
            BasicBlock *merge_block = BasicBlock::Create(*context, "if.merge", curr_func);

            if (s->conditional_stmt.else_body) {
                BasicBlock *else_block = BasicBlock::Create(*context, "if.else", curr_func);
                builder->CreateCondBr(cond, then_block, else_block);

                builder->SetInsertPoint(else_block);
                stmt_codegen(s->conditional_stmt.else_body);
                branch_to(merge_block);
            } else {
                builder->CreateCondBr(cond, then_block, merge_block);
            }

            builder->SetInsertPoint(then_block);
            stmt_codegen(s->conditional_stmt.body);
            branch_to(merge_block);
            builder->SetInsertPoint(merge_block);

            break;
        }
        case STMT_SWITCH: {
            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *end_block = BasicBlock::Create(*context, "switch.end", curr_func);

            Value *cond = expr_codegen(s->conditional_stmt.cond);
            switch_stmts.push(builder->CreateSwitch(cond, nullptr));
            break_dest.push(end_block);

            stmt_codegen(s->conditional_stmt.body);
            if (!builder->GetInsertBlock()->getTerminator()) {
                builder->CreateBr(end_block);
            }

            switch_stmts.pop();
            break_dest.pop();

            break;
        }
        case STMT_CASE:
        case STMT_DEFAULT: {
            assert(!switch_stmts.empty());

            Function *curr_func = builder->GetInsertBlock()->getParent();
            std::string name = (s->kind == STMT_CASE) ? "switch.case" : "switch.default";
            BasicBlock *dest = BasicBlock::Create(*context, name, curr_func);
            if (!builder->GetInsertBlock()->getTerminator()) {
                builder->CreateBr(dest);
            }
            builder->SetInsertPoint(dest);
            
            if (s->kind == STMT_CASE) {
                Value *condV = expr_codegen(s->case_stmt.case_expr);
                ConstantInt *condC = nullptr;
                if (auto c = cast<ConstantInt>(condV)) condC = c;
                assert(condC);

                switch_stmts.top()->addCase(condC, dest);
                stmt_codegen(s->case_stmt.result);
            } else {
                switch_stmts.top()->setDefaultDest(dest);
                stmt_codegen(s->default_stmt.result);
            }
            break;
        }
        case STMT_WHILE: {
            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *cond_block = BasicBlock::Create(*context, "while.cond", curr_func);
            BasicBlock *body_block = BasicBlock::Create(*context, "while.body", curr_func);
            BasicBlock *end_block = BasicBlock::Create(*context, "while.end", curr_func);

            builder->CreateBr(cond_block);
            builder->SetInsertPoint(cond_block);

            Value *cond = expr_codegen(s->conditional_stmt.cond);
            cond = force_bool(cond);
            builder->CreateCondBr(cond, body_block, end_block);

            builder->SetInsertPoint(body_block);
            break_dest.push(end_block);
            continue_dest.push(cond_block);
            stmt_codegen(s->conditional_stmt.body);

            branch_to(cond_block);
            builder->SetInsertPoint(end_block);
            break_dest.pop();
            continue_dest.pop();

            break;
        }
        case STMT_DO: {
            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *cond_block = BasicBlock::Create(*context, "do.while.cond", curr_func);
            BasicBlock *body_block = BasicBlock::Create(*context, "do.while.body", curr_func);
            BasicBlock *end_block = BasicBlock::Create(*context, "do.while.end", curr_func);

            builder->CreateBr(body_block);
            builder->SetInsertPoint(cond_block);

            Value *cond = expr_codegen(s->conditional_stmt.cond);
            cond = force_bool(cond);
            builder->CreateCondBr(cond, body_block, end_block);

            builder->SetInsertPoint(body_block);
            break_dest.push(end_block);
            continue_dest.push(cond_block);
            stmt_codegen(s->conditional_stmt.body);

            branch_to(cond_block);
            builder->SetInsertPoint(end_block);
            break_dest.pop();
            continue_dest.pop();
            
            break;
        }
        case STMT_FOR: {
            push_scope();

            if (s->for_stmt.kind == FOR_DECL) {
                decl_codegen(s->for_stmt.init.decl, false);
            } else {
                expr_codegen(s->for_stmt.init.expr);
            }

            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *cond_block = BasicBlock::Create(*context, "for.cond", curr_func);
            BasicBlock *body_block = BasicBlock::Create(*context, "for.body", curr_func);
            BasicBlock *incr_block = BasicBlock::Create(*context, "for.incr", curr_func);
            BasicBlock *end_block = BasicBlock::Create(*context, "for.end", curr_func);

            builder->CreateBr(cond_block);
            builder->SetInsertPoint(cond_block);

            Value *cond = expr_codegen(s->for_stmt.cond);
            cond = force_bool(cond);
            builder->CreateCondBr(cond, body_block, end_block);

            builder->SetInsertPoint(body_block);
            break_dest.push(end_block);
            continue_dest.push(incr_block);
            stmt_codegen(s->for_stmt.body);

            branch_to(incr_block);

            builder->SetInsertPoint(incr_block);
            expr_codegen(s->for_stmt.update);
            builder->CreateBr(cond_block);

            builder->SetInsertPoint(end_block);
            break_dest.pop();
            continue_dest.pop();

            pop_scope();

            break;
        }
        case STMT_LABEL: {
            Function *curr_func = builder->GetInsertBlock()->getParent();
            BasicBlock *label_block = BasicBlock::Create(*context, s->label_stmt.label, curr_func);
            std::string name(s->label_stmt.label);
            labels.push(name, label_block);

            stmt_codegen(s->label_stmt.next);
            
            break;
        }
        case STMT_GOTO: {
            BasicBlock *dest = labels[s->goto_stmt.label];
            assert(dest);
            builder->CreateBr(dest);
            break;
        }
        case STMT_CONTINUE: {
            assert(!continue_dest.empty());
            builder->CreateBr(continue_dest.top());
            break;
        }
        case STMT_BREAK: {
            assert(!break_dest.empty());
            builder->CreateBr(break_dest.top());
            break;
        }
        case STMT_RETURN: {
            Value *ret = expr_codegen(s->return_stmt.result);
            assert(ret);
            builder->CreateRet(ret);
            break;
        }
        default: {
            // STMT_PRINT_STR, STMT_PRINT_EXPR, STMT_FREE
        }
    }
}

static void decl_codegen(decl *d, bool is_global) {
    if (d->specs->storage == SC_TYPEDEF) return;

    for (init_decltr *curr = d->init_decltrs; curr; curr = curr->next) {
        sem_type_t *d_type = curr->type;
        if (!d_type) d_type = decl_type(d->specs, curr->decltr, false);
        assert(d_type);
        
        // Function declaration is guaranteed to be at file scope
        if (d_type->kind == ST_FUNC) {
            Type *ret = sem_type_to_llvm(d_type->func_info.return_type);
            std::vector<Type *> param_types;
            for (sem_type_list_t *tl = d_type->func_info.params; tl; tl = tl->next) {
                param_types.push_back(sem_type_to_llvm(tl->type));
            }
            FunctionType *ft = FunctionType::get(ret, param_types, d_type->func_info.variadic);

            GlobalValue::LinkageTypes linkage =
                (d->specs->storage == SC_STATIC) ? Function::InternalLinkage : Function::ExternalLinkage;

            Function *fn = Function::Create(
                ft, linkage, curr->decltr->id, *llvm_module
            );

            named_values.push(std::string(fn->getName()), fn);

            // Set arg names maybe?
        }
        // Regular variable declaration
        else if (!is_global) {
            Type *t = sem_type_to_llvm(curr->type);
            AllocaInst *var = builder->CreateAlloca(t, nullptr, curr->decltr->id);
            
            if (curr->init && curr->init->kind == INIT_EXPR) {
                Value *init = expr_codegen(curr->init->assignment);
                if (init) {
                    Type *var_type = sem_type_to_llvm(curr->type);
                    // If we're initializing an array with a pointer (string literal)
                    if (var_type->isArrayTy() && init->getType()->isPointerTy()) {
                        ArrayType *arr_type = cast<ArrayType>(var_type);
                        const DataLayout &layout = llvm_module->getDataLayout();
                        uint64_t size = layout.getTypeAllocSize(arr_type);
                        
                        // Use memcpy to initialize the array
                        builder->CreateMemCpy(
                            var,
                            MaybeAlign(1),
                            init,
                            MaybeAlign(1),
                            size
                        );
                    } else {
                        builder->CreateStore(init, var);
                    }
                }
            }

            std::string name(curr->decltr->id);
            named_values.push(name, var);
        }
        // Global variable declaration
        else {
            Type *t = sem_type_to_llvm(curr->type);
            Constant *init = nullptr;
            if (curr->init && curr->init->kind == INIT_EXPR) {
                expr *assignment = curr->init->assignment;
                if (assignment->kind == EXPR_CONST) {
                    init = constant_to_llvm(assignment->extra.const_val, assignment->type);
                } else if (assignment->kind == EXPR_STR_LITERAL) {
                    std::string prepared_string = prepare_str_literal(assignment->extra.str_val);
                    Constant *str_const = ConstantDataArray::getString(*context, prepared_string);

                    GlobalValue::LinkageTypes linkage =
                        (d->specs->storage == SC_STATIC) ?
                            GlobalValue::InternalLinkage :
                            GlobalValue::ExternalLinkage;

                    GlobalVariable *var = new GlobalVariable(
                        str_const->getType(),
                        curr->type->quals & TQ_CONST_MASK,
                        linkage,
                        str_const,
                        curr->decltr->id
                    );
                    llvm_module->insertGlobalVariable(var);
                    named_values.push(curr->decltr->id, var);
                    continue;
                }
            }

            GlobalValue::LinkageTypes linkage =
                (d->specs->storage == SC_STATIC) ?
                    GlobalValue::InternalLinkage :
                    GlobalValue::ExternalLinkage;

            GlobalVariable *var = new GlobalVariable(
                t,
                d_type->quals & TQ_CONST_MASK,
                linkage,
                init,
                curr->decltr->id
            );

            llvm_module->insertGlobalVariable(var);
            named_values.push(curr->decltr->id, var);
        }
    }
}

static void func_codegen(func_def *fd) {
    Function *func = llvm_module->getFunction(fd->decltr->id);
    if (!func) {
        decl *func_decl = make_normal_decl(fd->specs, make_init_decltr(fd->decltr, 0));
        func_decl->init_decltrs->type = fd->type;
        decl_codegen(func_decl, true);
        func = llvm_module->getFunction(fd->decltr->id);
    }

    assert(func);

    // Set all parameter names
    param_list *param = fd->decltr->next->func.params;
    for (auto &arg : func->args()) {
        arg.setName(param->param_decl->param_decltr->id);
        named_values.push(std::string(arg.getName()), &arg);
    }

    BasicBlock *body = BasicBlock::Create(*context, "func.entry", func);
    builder->SetInsertPoint(body);
    stmt_codegen(fd->body);

    // void functions need a return terminator
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateRet(nullptr);
    }

    if (verifyFunction(*func)) {
        // This should not happen
        std::cout << "function generation failed: that error should've been caught earlier\n";
    }
}

// Attempts to print human-readable LLVM IR to a file with the given name
// Returns true if successful and false otherwise
bool write_module_to_file(const Module &m, const std::string &filename) {
    std::error_code EC;

    raw_fd_ostream out(filename, EC, sys::fs::OF_None);
    if (EC) {
        errs() << "Error opening file '" << filename << "': " << EC.message() << "\n";
        return false;
    }

    m.print(out, nullptr);
    return true;
}

static void initialize_module() {
    context = std::make_unique<LLVMContext>();
    llvm_module = std::make_unique<Module>("C- Language Module", *context);
    builder = std::make_unique<IRBuilder<>>(*context);

    sem_struct_to_llvm.clear();
    sem_union_to_llvm.clear();

    // Other static globals are guaranteed to be empty after generate_llvm() is finished
}

std::optional<std::pair<std::unique_ptr<Module>, std::unique_ptr<LLVMContext>>>
generate_llvm(translation_unit *ast) {
    initialize_module();

    push_scope();

    for (translation_unit *curr = ast; curr; curr = curr->next) {
        if (curr->action->kind == EXT_DECL_FUNC) {
            func_codegen(curr->action->func);
        } else {
            decl_codegen(curr->action->decl, true);
        }
    }

    pop_scope();

    if (verifyModule(*llvm_module, &errs())) {
        write_module_to_file(*llvm_module, "llvm_error_module.ll");
        llvm_module.release();
        return std::nullopt;
    }

    builder.release();
    return std::optional{ std::pair(std::move(llvm_module), std::move(context)) };
}

void module_to_obj(
    Module &M,
    const std::string &filename,
    const OptimizationLevel &optimization,
    const std::string &TargetTripleStr
) {
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    std::string error;
    const Target *target = TargetRegistry::lookupTarget(TargetTripleStr, error);
    if (!target) {
        errs() << "Target lookup failed: " << error << "\n";
        return;
    }

    TargetOptions opt;
    auto cpu = "generic";
    auto features = "";
    TargetMachine *TM = target->createTargetMachine(
        TargetTripleStr,
        cpu,
        features,
        opt,
        std::optional<Reloc::Model>()
    );

    M.setTargetTriple(TM->getTargetTriple());
    M.setDataLayout(TM->createDataLayout());

    LoopAnalysisManager LAM;
    FunctionAnalysisManager FAM;
    CGSCCAnalysisManager CGAM;
    ModuleAnalysisManager MAM;

    PassBuilder PB(TM);

    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);

    ModulePassManager MPM = PB.buildPerModuleDefaultPipeline(optimization);

    MPM.run(M, MAM);

    std::error_code ec;
    raw_fd_ostream dest(filename, ec, llvm::sys::fs::OF_None);
    if (ec) {
        errs() << "Could not open file: " << ec.message() << "\n";
        return;
    }

    legacy::PassManager CodeGenPM;
    if (TM->addPassesToEmitFile(CodeGenPM, dest, nullptr, CodeGenFileType::ObjectFile)) {
        errs() << "Target does not support assembly emission\n";
        return;
    }

    CodeGenPM.run(M);
    dest.flush();
}