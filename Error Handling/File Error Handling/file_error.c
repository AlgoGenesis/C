#include <stdio.h>
#include <errno.h>
#include <string.h>  // for strerror()
#include <stdlib.h>  // for exit()

void check_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        // If file can't be opened, print error using errno
        printf("Error opening file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    // Process the file
    printf("File '%s' opened successfully.\n", filename);
    
    // Close the file
    if (fclose(file) != 0) {
        // Handle fclose() error
        printf("Error closing file '%s': %s\n", filename, strerror(errno));
    } else {
        printf("File '%s' closed successfully.\n", filename);
    }
}

int divide(int a, int b) {
    if (b == 0) {
        // Return an error value for divide by zero
        errno = EDOM;  // Set errno to indicate a domain error
        return -1;
    }
    return a / b;
}

int main() {
    // Example of file error handling
    check_file("nonexistentfile.txt");  // This will trigger an error

    // Example of return value-based error handling
    int result = divide(10, 0);
    if (result == -1 && errno == EDOM) {
        printf("Division error: %s\n", strerror(errno));
    } else {
        printf("Division result: %d\n", result);
    }

    return 0;
}
