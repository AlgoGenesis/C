#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamic memory allocation using malloc
    int *arr_malloc;
    int n_malloc = 5;
    arr_malloc = (int *)malloc(n_malloc * sizeof(int));
    if (arr_malloc == NULL) {
        printf("Memory allocation failed using malloc\n");
        return 1;
    }

    // Initialize and display values
    for (int i = 0; i < n_malloc; i++) {
        arr_malloc[i] = i + 1;
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }

    // Dynamic memory allocation using calloc
    int *arr_calloc;
    int n_calloc = 5;
    arr_calloc = (int *)calloc(n_calloc, sizeof(int));
    if (arr_calloc == NULL) {
        printf("Memory allocation failed using calloc\n");
        free(arr_malloc);  
        return 1;
    }
 
    for (int i = 0; i < n_calloc; i++) {
        printf("arr_calloc[%d] = %d\n", i, arr_calloc[i]);
    }

    // Reallocate memory
    int new_size = 10;
    arr_malloc = (int *)realloc(arr_malloc, new_size * sizeof(int));
    if (arr_malloc == NULL) {
        printf("Reallocation failed\n");
        free(arr_calloc);  
        return 1;
    }

 
    for (int i = n_malloc; i < new_size; i++) {
        arr_malloc[i] = i + 1;
    }
 
    printf("After reallocation:\n");
    for (int i = 0; i < new_size; i++) {
        printf("arr_malloc[%d] = %d\n", i, arr_malloc[i]);
    }

    
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
