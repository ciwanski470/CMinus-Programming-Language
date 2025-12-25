CXX := g++
CC	:= gcc

# LLVM
LLVM_CONFIG ?= llvm-config

LLVM_CFLAGS			:= $(shell $(LLVM_CONFIG) --cflags 2>/dev/null)
LLVM_CXXFLAGS		:= $(shell $(LLVM_CONFIG) --cxxflags 2>/dev/null)
LLVM_LDFLAGS		:= $(shell $(LLVM_CONFIG) --ldflags 2>/dev/null)
LLVM_LIBS			:= $(shell $(LLVM_CONFIG) --libs core support 2>/dev/null)
LLVM_SYSTEM_LIBS	:= $(shell $(LLVM_CONFIG) --system-libs 2>/dev/null)

INCLUDE_DIR := include
CFLAGS		:= -Wall -Wextra -I $(INCLUDE_DIR) $(LLVM_CFLAGS)
CXXFLAGS 	:= -Wall -Wextra -I $(INCLUDE_DIR) $(LLVM_CXXFLAGS)

# Dependency files
#CFLAGS		+= -MMD -MP
#CXXFLAGS	+= -MMD -MP

LDFLAGS 	:= $(LLVM_LDFLAGS)
LDLIBS		:= $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS)

# For debugging
ASAN_FLAGS := -fsanitize=address -fno-omit-frame-pointer -g -O0

BUILD_DIR 	:= build
SRC_C 		:= $(wildcard src/*.c)
SRC_CPP		:= $(wildcard src/*.cpp)
OBJ_C		:= $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_C)))
OBJ_CPP		:= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRC_CPP)))
OBJS		:= $(OBJ_C) $(OBJ_CPP)
DEPS		:= $(OBJS:.o=.d)

TARGET := main

# tests layout (single-file tests in tests/ or tests/unit/ )
TEST_DIR 		:= tests
TEST_SRC 		:= $(wildcard $(TEST_DIR)/*.c) \
            	   $(wildcard $(TEST_DIR)/unit/*.c) \
            	   $(wildcard $(TEST_DIR)/integration/*.c)
TEST_OBJ 		:= $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/tests/%.o, $(TEST_SRC))
TEST_BINARIES 	:= $(patsubst $(BUILD_DIR)/tests/%.o, $(BUILD_DIR)/tests/%, $(TEST_OBJ))

.PHONY: all test clean asan

all: $(TARGET)

# Build with AddressSanitizer
asan: CXX = clang
asan: CXXFLAGS += $(ASAN_FLAGS)
asan: LDFLAGS += $(ASAN_FLAGS)
asan: clean $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# C source rules
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# C++ source rules
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile tests into build/tests/*.o (tests get their own include dir)
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)/tests
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR)/include -c $< -o $@

# Link each test executable against the library (note: lib DOES NOT contain main.c)
$(BUILD_DIR)/tests/%: $(BUILD_DIR)/tests/%.o $(LIB) | $(BUILD_DIR)/tests
	@mkdir -p $(dir $@)
	$(CXX) $< -L$(BUILD_DIR) -lproject $(LDFLAGS) -o $@

# Create build directories if they don't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/tests:
	@mkdir -p $(BUILD_DIR)/tests

-include $(DEPS)

# Run all test binaries (stops on first failure)
test: $(TEST_BINARIES)
	@echo "Running tests..."
	@for t in $(TEST_BINARIES); do \
	  echo "-> $$t"; \
	  ./$$t || exit 1; \
	done
	@echo "All tests passed."

clean:
	rm -rf $(BUILD_DIR) $(TARGET)