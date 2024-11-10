#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 100
#define THRESHOLD_STAGE1 50
#define THRESHOLD_STAGE2 75
#define THRESHOLD_STAGE3 90

void generate_data(int *data, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100; // Random values between 0 and 99
    }
}

void print_data(const int *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int cascade_stage(int value, int threshold) {
    return value >= threshold;
}

void cascade_search(int *data, int size) {
    printf("Running Cascade Search...\n");

    // Stage 1: Filter based on THRESHOLD_STAGE1
    printf("Stage 1 (Threshold: %d):\n", THRESHOLD_STAGE1);
    for (int i = 0; i < size; i++) {
        if (cascade_stage(data[i], THRESHOLD_STAGE1)) {
            printf("Data[%d] = %d passed Stage 1\n", i, data[i]);

            // Stage 2: Filter based on THRESHOLD_STAGE2
            if (cascade_stage(data[i], THRESHOLD_STAGE2)) {
                printf("Data[%d] = %d passed Stage 2\n", i, data[i]);

                // Stage 3: Filter based on THRESHOLD_STAGE3
                if (cascade_stage(data[i], THRESHOLD_STAGE3)) {
                    printf("Data[%d] = %d passed Stage 3\n", i, data[i]);
                }
            }
        }
    }
}

int main() {
    int data[NUM_ELEMENTS];
    generate_data(data, NUM_ELEMENTS);

    printf("Generated Data:\n");
    print_data(data, NUM_ELEMENTS);

    cascade_search(data, NUM_ELEMENTS);

    return 0;
}
