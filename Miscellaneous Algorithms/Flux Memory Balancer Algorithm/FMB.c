#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_MEMORY 1000  // Total memory available in the system

// Define a structure for processes
typedef struct {
    int id;
    int priority;       // Lower number means higher priority
    int memoryReq;      // Memory requested by the process
    int allocatedMem;   // Memory currently allocated to the process
} Process;

// Function to perform Flux Memory Balancer (FMB)
void fluxMemoryBalancer(Process processes[], int n) {
    int totalAllocatedMemory = 0;

    // Initial memory allocation based on priority
    for (int i = 0; i < n; i++) {
        if (totalAllocatedMemory + processes[i].memoryReq <= MAX_MEMORY) {
            processes[i].allocatedMem = processes[i].memoryReq;
            totalAllocatedMemory += processes[i].allocatedMem;
        } else {
            // Allocate as much as possible if not enough memory
            processes[i].allocatedMem = MAX_MEMORY - totalAllocatedMemory;
            totalAllocatedMemory = MAX_MEMORY;
        }
    }

    // Adjust memory allocation with a flux mechanism
    for (int i = 0; i < n; i++) {
        if (totalAllocatedMemory > MAX_MEMORY) {
            for (int j = n - 1; j >= 0; j--) {
                if (processes[j].priority > processes[i].priority) {
                    int reduction = (processes[j].allocatedMem > 10) ? 10 : processes[j].allocatedMem;
                    processes[j].allocatedMem -= reduction;
                    totalAllocatedMemory -= reduction;
                    if (totalAllocatedMemory <= MAX_MEMORY) break;
                }
            }
        }
    }
}

// Function to print process details
void printProcesses(Process processes[], int n) {
    printf("ID\tPriority\tMemory Requested\tMemory Allocated\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t\t%d\n", 
            processes[i].id, processes[i].priority, 
            processes[i].memoryReq, processes[i].allocatedMem);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input details for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority and memory required for process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].memoryReq);
        processes[i].allocatedMem = 0;
    }

    // Perform Flux Memory Balancer scheduling
    fluxMemoryBalancer(processes, n);

    // Print process details
    printProcesses(processes, n);

    return 0;
}
