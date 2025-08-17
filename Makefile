CXX = gcc
CXXFLAGS = -Wall -Wextra -Iinclude

# For debugging
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -g -O0

TARGET = main
BUILD_DIR = build
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Build target
all: $(TARGET)

# Build with AddressSanitzier
asan: CXXFLAGS += $(ASAN_FLAGS)
asan: LDFLAGS += $(ASAN_FLAGS)
asan: clean $(TARGET)

# Linker command
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile src files into the build directory
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean target
clean:
	rm -f src/*.o $(TARGET)
