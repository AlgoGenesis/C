# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Source files (all .c files in the current directory)
SRC = $(wildcard *.c)

# Output executable name
OUT = $(SRC:.c=)

# Default target
all: $(OUT)

# Rule to create the executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(OUT)

# Phony targets
.PHONY: all clean
