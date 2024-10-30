#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for descending order sorting
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Helper function to check if a given number of machines can complete all tasks within max_time
int can_complete_all_tasks(int *tasks, int tasks_size, int *machines, int machine_count, int max_time) {
    int task_index = 0;
    // Iterate over the selected machines
    for (int i = 0; i < machine_count; i++) {
        int time_remaining = max_time;
        
        // Each machine takes tasks until it reaches the max time limit
        while (task_index < tasks_size && time_remaining >= (tasks[task_index] + machines[i] - 1) / machines[i]) {
            // Calculate time required by current machine for the current task
            time_remaining -= (tasks[task_index] + machines[i] - 1) / machines[i];
            task_index++;  // Move to the next task
        }
        
        // If all tasks are completed, return true (1)
        if (task_index >= tasks_size) {
            return 1;
        }
    }
    // If not all tasks could be completed, return false (0)
    return 0;
}

// Main function to find the minimum number of machines required to complete tasks within max_time
int min_machines_for_tasks(int *tasks, int tasks_size, int *machines, int machines_size, int max_time) {
    // Sort tasks in descending order
    qsort(tasks, tasks_size, sizeof(int), compare_desc);
    // Sort machines in descending order
    qsort(machines, machines_size, sizeof(int), compare_desc);

    int left = 1;  // Minimum number of machines to start with
    int right = machines_size;  // Maximum number of machines available
    int answer = -1;  // Initialize answer as -1 for cases where it's impossible

    // Perform binary search to find the minimum number of machines needed
    while (left <= right) {
        int mid = (left + right) / 2;

        // Check if mid machines can complete all tasks within max_time
        if (can_complete_all_tasks(tasks, tasks_size, machines, mid, max_time)) {
            answer = mid;  // mid machines can complete tasks within max_time
            right = mid - 1;  // Try fewer machines
        } else {
            left = mid + 1;  // Need more machines
        }
    }

    return answer;
}

int main() {
    // Example input
    int tasks[] = {10, 20, 30, 40};
    int machines[] = {5, 10, 15};
    int max_time = 20;

    // Calculate sizes of tasks and machines arrays
    int tasks_size = sizeof(tasks) / sizeof(tasks[0]);
    int machines_size = sizeof(machines) / sizeof(machines[0]);

    // Find the minimum number of machines required
    int result = min_machines_for_tasks(tasks, tasks_size, machines, machines_size, max_time);

    // Output the result
    if (result != -1) {
        printf("Minimum machines required: %d\n", result);
    } else {
        printf("It is impossible to complete all tasks within the given time.\n");
    }

    return 0;
}
