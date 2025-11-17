/*
    Implementation of "utility.h"
*/

#include "string_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#if SIZE_MAX == UINT64_MAX
    #define FNV_OFFSET 1469598103934665603ULL
    #define FNV_PRIME  1099511628211ULL
#elif SIZE_MAX == UINT32_MAX
    #define FNV_OFFSET 2166136261U
    #define FNV_PRIME  16777619U
#endif

size_t str_hash(const char *str, const int mod) {
    size_t hash = FNV_OFFSET;
    for (char c; (c = *str); str++) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash % mod;
}

/*
    ------- type_to_s -------
*/

// Small string-builder helpers

static char *sdup(const char *s) {
    if (!s) return NULL;
    size_t n = strlen(s) + 1;
    char *r = malloc(n);
    memcpy(r, s, n);
    return r;
}

static char *sappend(char *a, const char *b) {
    if (!b) return a;
    if (!a) return sdup(b);
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char *r = realloc(a, la + lb + 1);
    memcpy(r + la, b, lb + 1);
    return r;
}

static char *sprepend(char *a, const char *b) {
    if (!b) return a;
    if (!a) return sdup(b);
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char *r = malloc(la + lb + 1);
    memcpy(r, b, lb);
    memcpy(r + lb, a, la + 1);
    free(a);
    return r;
}

/*
    Convert qualifiers mask (on a type) into a prefix string like "const restrict "
    When used as base-type qualifiers they appear before the base type name.
    When used for pointer qualifiers it produces e.g. " const" (note leading space).
*/
static char *qualifiers_prefix(unsigned short quals) {
    // return "const restrict volatile " or NULL
    char tmp[64] = {0};
    tmp[0] = '\0';
    if (quals & TQ_CONST_MASK) strcat(tmp, "const ");
    if (quals & TQ_RESTRICT_MASK) strcat(tmp, "restrict ");
    if (quals & TQ_VOLATILE_MASK) strcat(tmp, "volatile ");
    if (tmp[0] == '\0') return NULL;
    return sdup(tmp);
}

static char *qualifiers_after_star(unsigned short quals) {
    // return " const" or NULL (leading space so we can do "*" + that)
    char tmp[64] = {0};
    int pos = 0;
    if (quals & TQ_CONST_MASK) {
        tmp[pos++] = ' ';
        strcat(tmp + pos, "const");
        pos += strlen("const");
    }
    if (quals & TQ_RESTRICT_MASK) {
        tmp[pos++] = ' ';
        strcat(tmp + pos, "restrict");
        pos += strlen("restrict");
    }
    if (quals & TQ_VOLATILE_MASK) {
        tmp[pos++] = ' ';
        strcat(tmp + pos, "volatile");
        pos += strlen("volatile");
    }
    if (pos == 0) return NULL;
    return sdup(tmp);
}

/*
    Core recursive builder: builds prefix and suffix strings.
    - prefix: holds text that goes before an identifier (e.g. "const int")
    - suffix: holds text that goes after an identifier (e.g. " *[10]" or "(int, char *)")
    After recursion, final result is prefix + " " + suffix (with some cleanup).
*/
static void build_type_repr(sem_type_t *t, char **out_prefix, char **out_suffix) {
    if (!t) {
        *out_prefix = sdup("/*unknown*/");
        *out_suffix = sdup("");
        return;
    }

    switch (t->kind) {
        case ST_POINTER: {
            // Build for target first.
            char *p = NULL, *s = NULL;
            build_type_repr(t->ptr_target, &p, &s);

            // Pointer qualifiers (appear after '*')
            char *pq = qualifiers_after_star(t->quals); // e.g. " const" or NULL

            // If there's a non-empty suffix, we must parenthesize it before inserting "*"
            if (s && s[0] != '\0') {
                // make "(existing_suffix)"
                char *wrapped = malloc(strlen(s) + 3);
                sprintf(wrapped, "(%s)", s);
                free(s);
                s = wrapped;
            }

            // Prepend "*" + pq to the suffix
            char starbuf[64];
            if (pq) {
                snprintf(starbuf, sizeof(starbuf), "*%s", pq);
            } else {
                snprintf(starbuf, sizeof(starbuf), "*");
            }
            if (s) {
                // new_suffix = starbuf + s
                char *new_s = malloc(strlen(starbuf) + strlen(s) + 1);
                strcpy(new_s, starbuf);
                strcat(new_s, s);
                free(s);
                s = new_s;
            } else {
                s = sdup(starbuf);
            }
            if (pq) free(pq);

            *out_prefix = p;
            *out_suffix = s;
            return;
        }

        case ST_ARRAY: {
            // element type, then append array suffix
            char *p = NULL, *s = NULL;
            build_type_repr(t->arr_info.element_type, &p, &s);

            // build array suffix
            char abuf[64];
            if (t->arr_info.incomplete) {
                snprintf(abuf, sizeof(abuf), "[]");
            } else {
                // print size as size_t
                snprintf(abuf, sizeof(abuf), "[%zu]", t->arr_info.size);
            }
            // append to suffix
            char *new_s = NULL;
            if (s) {
                new_s = malloc(strlen(s) + strlen(abuf) + 1);
                strcpy(new_s, s);
                strcat(new_s, abuf);
                free(s);
            } else {
                new_s = sdup(abuf);
            }

            *out_prefix = p;
            *out_suffix = new_s;
            return;
        }

        case ST_FUNC: {
            // return type and params
            char *p = NULL, *s = NULL;
            build_type_repr(t->func_info.return_type, &p, &s);

            // build params string
            if (t->func_info.params == NULL) {
                // no params -> treat as (void)
                char *params = sdup("(void)");
                // append to suffix
                char *new_s = NULL;
                if (s) {
                    new_s = malloc(strlen(s) + strlen(params) + 1);
                    strcpy(new_s, s);
                    strcat(new_s, params);
                    free(s);
                } else {
                    new_s = sdup(params);
                }
                free(params);
                *out_prefix = p;
                *out_suffix = new_s;
                return;
            } else {
                // iterate params
                // create a temporary buffer
                size_t cap = 64;
                char *plist = malloc(cap);
                plist[0] = '(';
                plist[1] = '\0';
                sem_type_list_t *cur = t->func_info.params;
                bool first = true;
                while (cur) {
                    if (!first) {
                        plist = sappend(plist, ", ");
                    }
                    first = false;
                    char *pt_prefix = NULL, *pt_suffix = NULL;
                    build_type_repr(cur->type, &pt_prefix, &pt_suffix);
                    // For printing a param type alone (no identifier) join prefix and suffix
                    // remove extraneous leading/trailing spaces
                    char *param = NULL;
                    if (pt_suffix && pt_suffix[0] != '\0') {
                        // prefix + " " + suffix
                        param = malloc(strlen(pt_prefix ? pt_prefix : "") + 1 + strlen(pt_suffix) + 1);
                        sprintf(param, "%s %s", pt_prefix ? pt_prefix : "", pt_suffix);
                    } else {
                        param = sdup(pt_prefix ? pt_prefix : "");
                    }
                    if (pt_prefix) free(pt_prefix);
                    if (pt_suffix) free(pt_suffix);

                    plist = sappend(plist, param);
                    free(param);
                    cur = cur->next;
                }
                plist = sappend(plist, ")");
                // append plist to existing suffix
                char *new_s = NULL;
                if (s) {
                    new_s = malloc(strlen(s) + strlen(plist) + 1);
                    strcpy(new_s, s);
                    strcat(new_s, plist);
                    free(s);
                } else {
                    new_s = sdup(plist);
                }
                free(plist);
                *out_prefix = p;
                *out_suffix = new_s;
                return;
            }
        }

        default: {
            // Primitive base types or struct/union/sou_info
            char *qpref = qualifiers_prefix(t->quals); // e.g., "const "
            const char *basename = "/*unknown*/";
            switch (t->kind) {
                case ST_INT:
                    if (t->is_signed) basename = "int";
                    else basename = "unsigned int";
                    break;
                case ST_SHORT:
                    if (t->is_signed) basename = "short";
                    else basename = "unsigned short";
                    break;
                case ST_LONG:
                    if (t->is_signed) basename = "long";
                    else basename = "unsigned long";
                    break;
                case ST_LL:
                    if (t->is_signed) basename = "long long";
                    else basename = "unsigned long long";
                    break;
                case ST_CHAR:
                    // choose 'char' vs 'signed char' vs 'unsigned char'
                    if (t->is_signed) basename = "signed char";
                    else basename = "unsigned char";
                    break;
                case ST_VOID:
                    basename = "void";
                    break;
                case ST_FLOAT:
                    basename = "float";
                    break;
                case ST_DOUBLE:
                    basename = "double";
                    break;
                case ST_BOOL:
                    basename = "bool";
                    break;
                case ST_STRUCT:
                    basename = "struct /*...*/";
                    break;
                case ST_UNION:
                    basename = "union /*...*/";
                    break;
                default:
                    basename = "/*unknown*/";
                    break;
            }

            // prefix = (qualifiers + base)
            size_t prelen = (qpref ? strlen(qpref) : 0) + strlen(basename) + 2;
            char *prefix = malloc(prelen);
            prefix[0] = '\0';
            if (qpref) {
                strcpy(prefix, qpref);
                strcat(prefix, basename);
            } else {
                strcpy(prefix, basename);
            }
            if (qpref) free(qpref);

            *out_prefix = prefix;
            *out_suffix = sdup("");
            return;
        } // default
    } // switch
}

// Exported function
const char *type_to_s(sem_type_t *t) {
    char *pref = NULL, *suff = NULL;
    build_type_repr(t, &pref, &suff);
    if (!pref) pref = sdup("/*unknown*/");
    if (!suff) suff = sdup("");

    // Combine prefix and suffix into single string
    // trim spaces (if suffix is empty then no trailing space)
    char *result = NULL;
    if (suff[0] == '\0') {
        result = sdup(pref);
    } else {
        // if prefix already ends with space, don't add extra
        bool need_space = true;
        size_t plen = strlen(pref);
        if (plen > 0 && pref[plen - 1] == ' ') need_space = false;
        size_t rlen = strlen(pref) + (need_space ? 1 : 0) + strlen(suff) + 1;
        result = malloc(rlen);
        result[0] = '\0';
        strcpy(result, pref);
        if (need_space) strcat(result, " ");
        strcat(result, suff);
    }

    free(pref);
    free(suff);
    return result; // caller may free()
}