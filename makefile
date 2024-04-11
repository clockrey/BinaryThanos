# Define compiler
CC=gcc

# Define compiler flags
CFLAGS=-Wall -Wextra -O2

# Define the target executable name
TARGET=check_binary

# Default target to compile the program
all: $(TARGET)

# Rule to compile the program
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIBS)

# Rule to clean up the compiled files
clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) example
