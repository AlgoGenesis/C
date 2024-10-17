#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct {
    char* transformed;
    int* original_indices;
} BWTResult;

// Function to perform the Burrows-Wheeler Transform
void burrows_wheeler_transform(const char* input, BWTResult* result) {
    int len = strlen(input);
    char* rotations[MAX_LEN];
    result->original_indices = (int*)malloc(len * sizeof(int));
    result->transformed = (char*)malloc((len + 1) * sizeof(char));

    // Generate all rotations of the input string
    for (int i = 0; i < len; i++) {
        rotations[i] = (char*)malloc((len + 1) * sizeof(char));
        for (int j = 0; j < len; j++) {
            rotations[i][j] = input[(i + j) % len];
        }
        rotations[i][len] = '\0';  // Null-terminate the string
        result->original_indices[i] = i;  // Store original indices
    }

    // Sort the rotations
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (strcmp(rotations[j], rotations[j + 1]) > 0) {
                // Swap rotations
                char* temp = rotations[j];
                rotations[j] = rotations[j + 1];
                rotations[j + 1] = temp;

                // Swap original indices
                int temp_index = result->original_indices[j];
                result->original_indices[j] = result->original_indices[j + 1];
                result->original_indices[j + 1] = temp_index;
            }
        }
    }

    // Extract the last column of the sorted rotations
    for (int i = 0; i < len; i++) {
        result->transformed[i] = rotations[i][len - 1];
    }
    result->transformed[len] = '\0';  // Null-terminate the transformed string

    // Free allocated memory for rotations
    for (int i = 0; i < len; i++) {
        free(rotations[i]);
    }
}

// Function to perform the inverse Burrows-Wheeler Transform
void inverse_burrows_wheeler_transform(BWTResult* result, char* output) {
    int len = strlen(result->transformed);
    int* count = (int*)calloc(256, sizeof(int));  // Count of characters

    // Count occurrences of each character
    for (int i = 0; i < len; i++) {
        count[(unsigned char)result->transformed[i]]++;
    }

    // Compute cumulative counts
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Build the output using the original indices
    for (int i = 0; i < len; i++) {
        int original_index = result->original_indices[i];
        output[count[(unsigned char)result->transformed[original_index]] - 1] = result->transformed[original_index];
        count[(unsigned char)result->transformed[original_index]]--;
    }
    output[len] = '\0';  // Null-terminate the output string
}

void print_bwt_result(BWTResult* result) {
    printf("Transformed: %s\n", result->transformed);
    printf("Original Indices: ");
    for (int i = 0; i < strlen(result->transformed); i++) {
        printf("%d ", result->original_indices[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_LEN];
    BWTResult result;

    printf("Enter text: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character

    burrows_wheeler_transform(input, &result);
    print_bwt_result(&result);

    char output[MAX_LEN];
    inverse_burrows_wheeler_transform(&result, output);
    printf("Reconstructed: %s\n", output);

    // Free allocated memory
    free(result.transformed);
    free(result.original_indices);
    
    return 0;
}
