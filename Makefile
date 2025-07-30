CXX = gcc
CXXFLAGS = -Wall -Iinclude

TARGET = main
BUILD_DIR = build
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Build target
all: $(TARGET)

# Debug
#$(info SRC files: $(SRC))
#$(info Object files: $(OBJ))

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

# Run target
run: $(TARGET)
	./$(TARGET)
