# Compiler
CC = gcc

# Compiler flags
CFLAGS = -w -g

# Target executable
TARGET = heap_overflow

# Build target
all: $(TARGET) run clean

# Compile the C program
$(TARGET): heap_overflow.c
	$(CC) $(CFLAGS) -o $(TARGET) heap_overflow.c

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
