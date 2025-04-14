# Compiler and flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11

# Directories
OBJECT_DIR := obj

# Source and object files
SRCS := $(wildcard *.cpp)
OBJECTS := $(SRCS:%.cpp=$(OBJECT_DIR)/%.o)

# Target binary
TARGET := calculator

# Print info
$(info SRCS: $(SRCS))
$(info OBJECTS: $(OBJECTS))

# Default target
all: $(TARGET)

# Ensure object directory exists
$(OBJECT_DIR):
	mkdir -p $@

# Link target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files
$(OBJECT_DIR)/%.o: %.cpp | $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJECT_DIR) $(TARGET)
