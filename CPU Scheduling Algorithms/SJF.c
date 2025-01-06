#include <stdio.h>
#include <stdlib.h>

// Structure to hold each process's details
struct Process {
    int id, bt, at, start, comp, wt, tat;
};

// Function to calculate the turnaround time of each process
void find_tat(struct Process* input, int n) {
    for (int i = 0; i < n; i++) {
        input[i].tat = input[i].comp - input[i].at; // Turnaround time = completion time - arrival time
    }
}

// Function to calculate the waiting time of each process
void find_wt(struct Process* input, int n) {
    for (int i = 0; i < n; i++) {
        input[i].wt = input[i].tat - input[i].bt; // Waiting time = turnaround time - burst time
    }
}

// Comparison function for sorting processes by burst time and arrival time
int comp(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;

    // If burst times are equal, sort by arrival time
    if (p1->bt == p2->bt)
        return p1->at - p2->at; // If burst times are the same, sort by arrival time

    return p1->bt - p2->bt; // Sort by burst time otherwise
}

// Function to schedule the processes and determine their start and completion times
void schedule(struct Process* input, int n) {
    qsort(input, n, sizeof(struct Process), comp); // Sort processes by burst time

    int last_comp = 0; // Tracks the completion time of the last scheduled process
    
    for (int i = 0; i < n; i++) {
        if (input[i].at > last_comp) {
            input[i].start = input[i].at; // If the process arrives after the last one finishes
        } else {
            input[i].start = last_comp; // Otherwise, it starts right after the last process
        }

        input[i].comp = input[i].start + input[i].bt; // Completion time = start time + burst time
        last_comp = input[i].comp; // Update last completion time
    }
}

int main() {
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    struct Process* input = (struct Process*)malloc(n * sizeof(struct Process)); // Array to hold process data
    for (int i = 0; i < n; i++) {
        printf("Enter the id, burst time and arrival time of process %d:\n", i + 1);
        scanf("%d %d %d", &input[i].id, &input[i].bt, &input[i].at); // Input process details
    }

    schedule(input, n); // Schedule processes based on burst time
    find_tat(input, n); // Calculate turnaround times
    find_wt(input, n); // Calculate waiting times
    
    // Print table headers with appropriate column spacing
    printf("%8s %8s %8s %8s %12s %10s %12s %8s\n", "Process", "Burst", "Arrival", "Start", "Completion", "Turn Around", "Waiting");
    
    // Print each process's details in the formatted table
    for (int i = 0; i < n; i++) {
        printf("%8s%d %8d %8d %8d %12d %10d %12d %8d\n",
               "P", input[i].id, input[i].bt, input[i].at,
               input[i].start, input[i].comp,
               input[i].tat, input[i].wt);
    }

    // Free dynamically allocated memory
    free(input);
    return 0;
}
