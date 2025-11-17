CXX = gcc
CXXFLAGS = -Wall -Wextra -Iinclude

# For debugging
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -g -O0

TARGET = main
BUILD_DIR = build
SRC = $(wildcard src/*.c)

# separate the application entrypoint from the library sources
APP_SRC = src/main.c
LIB_SRC = $(filter-out $(APP_SRC), $(SRC))

# object lists
APP_OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(APP_SRC))
LIB_OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(LIB_SRC))

# static library name
LIB = $(BUILD_DIR)/libproject.a

# tests layout (single-file tests in tests/ or tests/unit/ )
TEST_DIR = tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c) \
            $(wildcard $(TEST_DIR)/unit/*.c) \
            $(wildcard $(TEST_DIR)/integration/*.c)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/tests/%.o, $(TEST_SRC))
TEST_BINARIES = $(patsubst $(BUILD_DIR)/tests/%.o, $(BUILD_DIR)/tests/%, $(TEST_OBJ))

LDFLAGS =

.PHONY: all test clean asan

all: $(TARGET)

# Build with AddressSanitizer
asan: CXX = clang
asan: CXXFLAGS += $(ASAN_FLAGS)
asan: LDFLAGS += $(ASAN_FLAGS)
asan: clean $(TARGET)

# Build the static library from all src files except main.c
$(LIB): $(LIB_OBJ) | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

# Build the main program by linking main.o with the library
$(TARGET): $(APP_OBJ) $(LIB)
	$(CXX) $(APP_OBJ) -L$(BUILD_DIR) -lproject $(LDFLAGS) -o $(TARGET)

# Compile src files into the build directory
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
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