// Problem Statement
// In a round-robin scheduling algorithm, tasks are executed in a circular order. Each task is given a fixed time slice, and when a task's time is up, control is passed to the next task in the list. If a task completes before its time slice expires, it can be removed from the list. 

#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a task in the circular linked list
struct Task {
    int id;                // Task identifier
    struct Task* next;     // Pointer to the next task in the list
};

// Function to create a new task
struct Task* createTask(int id) {
    struct Task* new_task = (struct Task*)malloc(sizeof(struct Task));
    new_task->id = id;
    new_task->next = NULL;
    return new_task;
}

// Function to insert a task at the end of the circular linked list
void insertTask(struct Task** head_ref, int id) {
    struct Task* new_task = createTask(id);
    
    if (*head_ref == NULL) {
        *head_ref = new_task;
        new_task->next = new_task; // Point to itself
        return;
    }
    
    struct Task* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    
    last->next = new_task;
    new_task->next = *head_ref; // Point the new task to head
}

// Function to execute tasks in a round-robin manner
void executeTasks(struct Task** head_ref, int time_slice) {
    if (*head_ref == NULL) {
        printf("No tasks to execute.\n");
        return;
    }

    struct Task* current = *head_ref;
    do {
        printf("Executing Task %d for %d seconds.\n", current->id, time_slice);
        // Simulate task completion
        current = current->next;
    } while (current != *head_ref);
}

// Function to delete a task at a specific position
void deleteTask(struct Task** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    struct Task* temp = *head_ref;
    if (position == 0) {
        // Handle deletion of the head task
        if (temp->next == *head_ref) {
            free(temp);
            *head_ref = NULL; // List becomes empty
            return;
        }
        struct Task* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        *head_ref = temp->next; // Update head
        last->next = *head_ref; // Link last to new head
        free(temp);
        return;
    }

    // Find the task before the position
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head_ref) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    if (temp == NULL || temp->next == *head_ref) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Task* to_delete = temp->next;
    temp->next = to_delete->next; // Unlink the task
    free(to_delete); // Free memory
}

// Function to display the tasks in the circular linked list
void displayTasks(struct Task* head) {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    struct Task* ptr = head;
    do {
        printf("Task %d -> ", ptr->id);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(head)\n");
}

int main() {
    struct Task* task_list = NULL;

    // Insert tasks into the circular linked list
    insertTask(&task_list, 1);
    insertTask(&task_list, 2);
    insertTask(&task_list, 3);
    insertTask(&task_list, 4);

    // Display tasks before execution
    printf("Tasks in the circular linked list:\n");
    displayTasks(task_list);

    // Execute tasks in a round-robin manner
    int time_slice = 2; // Each task gets 2 seconds
    executeTasks(&task_list, time_slice);

    // Delete a task at position 1
    deleteTask(&task_list, 1);
    printf("\nTasks after deleting task at position 1:\n");
    displayTasks(task_list);

    return 0;
}
