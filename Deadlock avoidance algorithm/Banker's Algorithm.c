#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

// Function to check if the system is in a safe state
bool isSafe(int processes, int resources, int max[MAX_PROCESSES][MAX_RESOURCES],
            int allocation[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES]) {

    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    // Initialize work to available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    // Find a safe sequence
    while (count < processes) {
        bool found = false;
        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < resources; r++) {
                    if (max[p][r] - allocation[p][r] > work[r]) {
                        canAllocate = false;
                        break;
                    }
                }

                // If a process can be allocated
                if (canAllocate) {
                    for (int r = 0; r < resources; r++) {
                        work[r] += allocation[p][r];
                    }
                    safeSequence[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        // If no process can be allocated, then system is not in a safe state
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    // Print safe sequence
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < processes; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int processes, resources;
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];

    // Input the number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    // Input the Max matrix
    printf("Enter the Max matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input the Allocation matrix
    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input the Available resources
    printf("Enter the Available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    // Check if the system is in a safe state
    isSafe(processes, resources, max, allocation, available);

    return 0;
}
