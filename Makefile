# Compiler settings
CC = gcc
CFLAGS = -std=c11 -MMD -MP
CPPFLAGS = -Iinclude
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -lraylib

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_FILE = sim

# Source, object, and dependency files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

# Output executable
EXECUTABLE = $(BUILD_DIR)/$(BIN_FILE)

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Linking the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compiling source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Include the dependency files
-include $(DEPS)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(DEPS)

.PHONY: all clean
