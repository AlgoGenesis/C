#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 8      // Total number of tasks
#define GANG_SIZE 4      // Number of tasks per gang
#define NUM_GANGS (NUM_TASKS / GANG_SIZE)

// Barrier for gang synchronization
pthread_barrier_t barrier;

// Task function
void* execute_task(void* arg) {
    int task_id = *(int*)arg;
    free(arg);

    // Synchronize at the barrier to start gang execution together
    pthread_barrier_wait(&barrier);
    printf("Task %d is executing as part of its gang\n", task_id);
    sleep(1); // Simulate task execution time

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_TASKS];
    pthread_barrier_init(&barrier, NULL, GANG_SIZE);

    int task_count = 0;
    for (int i = 0; i < NUM_GANGS; i++) {
        printf("Scheduling Gang %d\n", i + 1);

        // Create threads for each task in the gang
        for (int j = 0; j < GANG_SIZE; j++) {
            int* task_id = malloc(sizeof(int));
            *task_id = task_count;
            if (pthread_create(&threads[task_count], NULL, execute_task, task_id) != 0) {
                perror("Failed to create thread");
                return 1;
            }
            task_count++;
        }

        // Wait for all threads in the gang to complete
        for (int j = 0; j < GANG_SIZE; j++) {
            pthread_join(threads[(i * GANG_SIZE) + j], NULL);
        }
        printf("Gang %d completed\n\n", i + 1);
    }

    pthread_barrier_destroy(&barrier);
    printf("All gangs completed.\n");
    return 0;
}
