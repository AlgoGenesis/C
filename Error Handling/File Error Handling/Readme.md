 # Error Handling in C

## Problem Statement
In C programming, handling errors efficiently is crucial for creating robust and reliable software. Without proper error handling, programs can crash or behave unpredictably when encountering unexpected conditions, such as invalid input, division by zero, or file access errors. The challenge is to implement a consistent and effective way to handle errors, especially in scenarios where system calls or functions return error codes.

### Key Objectives:
- Handle errors using return values and `errno`.
- Ensure the program can recover from or handle errors gracefully, without crashing.
- Provide informative error messages to users for debugging and understanding issues.

## Example

Here's an example that shows how to handle division by zero and file access errors in C using `errno` and return values:

```c
#include <stdio.h>
#include <errno.h>

int divide(int a, int b) {
    if (b == 0) {
        errno = EDOM; // Set the error number for domain error (divide by zero)
        return -1;
    }
    return a / b;
}

void check_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
    } else {
        printf("File opened successfully.\n");
        fclose(file);
    }
}

int main() {
    int result = divide(10, 0);
    if (result == -1) {
        perror("Division Error");
    }

    check_file("non_existent_file.txt");
    return 0;
}

```

## Expected Output:
Division Error: Numerical argument out of domain
Error opening file: No such file or directory



### Time Complexity

- **Division Error Handling (`divide` function)**: O(1)  
  Since it's a simple check and operation, the time complexity is constant.
  
- **File Checking (`check_file` function)**: O(1) for an immediate error or failure to open the file, but it could be O(n) where `n` is the size of the file in cases of file operations, such as reading or writing.

### Conclusion
This solution provides a simple yet effective way to handle errors in C, utilizing return values and the `errno` variable to manage both program and system-level errors. This approach ensures that programs can handle errors without abrupt crashes, leading to more robust applications.
