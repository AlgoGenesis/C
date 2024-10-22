#include <stdio.h>
#include <string.h>

// Sliding window (brute force) approach to find the first occurrence of a substring
int slidingWindowSearch(char* haystack, char* needle) {
    int n = strlen(haystack);  // Length of the haystack
    int m = strlen(needle);    // Length of the needle

    // If needle is longer than haystack, it cannot be found
    if (m > n) {
        return -1;
    }

    // Slide the window over the haystack
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Check if needle matches the current window in the haystack
        for (j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        // If needle matches
        if (j == m) {
            return i; // Return the index of the first occurrence
        }
    }

    // Return -1 if no match is found
    return -1;
}

int main() {
    char haystack[] = "hello world";
    char needle[] = "world";

    int result = slidingWindowSearch(haystack, needle);
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
