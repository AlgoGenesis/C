#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  
    }

     
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", arr + i);  
    }
 
    printf("You entered:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, *(arr + i)); // Dereferencing pointer to get value
    }

    // Free the allocated memory
    free(arr);
    return 0;
}
