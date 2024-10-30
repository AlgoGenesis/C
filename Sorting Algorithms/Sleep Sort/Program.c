#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NUMBERS 100

// Function for the sleep sort
void* sleepSort(void* arg) {
    int number = *((int*)arg);
    // Sleep for the value of the number
    sleep(number);
    // Print the number after sleeping
    printf("%d ", number);
    return NULL;
}

int main() {
    int numbers[MAX_NUMBERS];
    int count;

    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &count);

    // Input validation
    if (count < 1 || count > MAX_NUMBERS) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    // Create threads for each number
    pthread_t threads[MAX_NUMBERS];
    for (int i = 0; i < count; i++) {
        pthread_create(&threads[i], NULL, sleepSort, (void*)&numbers[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nSorted numbers (using Sleep Sort): ");
    return 0;
}
