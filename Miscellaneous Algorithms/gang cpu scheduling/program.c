#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 5

// Task dependencies matrix
int dependencies[NUM_TASKS][NUM_TASKS] = {
    {0, 1, 1, 0, 0}, // Task 0 depends on Task 1 and 2
    {0, 0, 0, 1, 0}, // Task 1 depends on Task 3
    {0, 0, 0, 0, 1}, // Task 2 depends on Task 4
    {0, 0, 0, 0, 0}, // Task 3 has no dependencies
    {0, 0, 0, 0, 0}  // Task 4 has no dependencies
};

// Array to keep track of completed tasks
int completed[NUM_TASKS] = {0};

// Mutex lock for safe access to the completed array
pthread_mutex_t lock;

// Function to simulate a task execution
void* execute_task(void* arg) {
    int task_id = *(int*)arg;
    free(arg);

    // Check dependencies
    for (int i = 0; i < NUM_TASKS; i++) {
        if (dependencies[task_id][i] == 1) {
            while (!completed[i]) {
                usleep(100000); // Sleep for 0.1 seconds
            }
        }
    }

    // Task execution
    printf("Executing Task %d\n", task_id);
    sleep(1); // Simulate some work

    // Mark the task as completed
    pthread_mutex_lock(&lock);
    completed[task_id] = 1;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_TASKS];
    pthread_mutex_init(&lock, NULL);

    // Create threads for each task
    for (int i = 0; i < NUM_TASKS; i++) {
        int* task_id = malloc(sizeof(int));
        *task_id = i;
        if (pthread_create(&threads[i], NULL, execute_task, task_id) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all tasks to complete
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("All tasks completed.\n");

    return 0;
}
