#include <stdio.h>
#include <stdlib.h>

// Structure to hold each process's details
struct Process {
    int id, bt, at, priority, start, comp;
};

// Function to calculate the response time of each process
int* find_response(struct Process* input, int n) {
    int* rt = (int*)malloc(n * sizeof(int)); // Array to hold response times
    for (int i = 0; i < n; i++) {
        rt[i] = abs(input[i].start - input[i].at); // Response time = start time - arrival time
    }
    return rt;
}

// Function to calculate the turnaround time of each process
int* find_tat(struct Process* input, int n) {
    int* tat = (int*)malloc(n * sizeof(int)); // Array to hold turnaround times
    for (int i = 0; i < n; i++) {
        tat[i] = abs(input[i].comp - input[i].at); // Turnaround time = completion time - arrival time
    }
    return tat;
}

// Function to calculate the waiting time of each process
int* find_wt(struct Process* input, int* tat, int n) {
    int* wt = (int*)malloc(n * sizeof(int)); // Array to hold waiting times
    for (int i = 0; i < n; i++) {
        wt[i] = abs(tat[i] - input[i].bt); // Waiting time = turnaround time - burst time
    }
    return wt;
}

// Comparison function for sorting processes by arrival time and priority (higher priority first)
int comp(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    if (p1->at == p2->at) {
        return p2->priority - p1->priority; // If arrival times are equal, sort by priority (higher priority first)
    }
    return p1->at - p2->at; // Otherwise, sort by arrival time
}

// Function to schedule the processes based on priority
void schedule(struct Process* input, int n) {
    qsort(input, n, sizeof(struct Process), comp); // Sort processes by arrival time and priority
    int last_comp = 0; // Tracks the completion time of the last scheduled process
    
    for (int i = 0; i < n; i++) {
        input[i].start = last_comp; // Start time of current process is the last process's completion time
        input[i].comp = last_comp + input[i].bt; // Completion time = start time + burst time
        last_comp = input[i].comp; // Update last completion time
    }
}

int main() {
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    struct Process* input = (struct Process*)malloc(n * sizeof(struct Process)); // Array to hold process data
    for (int i = 0; i < n; i++) {
        printf("Enter the id, burst time, arrival time, and priority of process %d:\n", i + 1);
        scanf("%d %d %d %d", &input[i].id, &input[i].bt, &input[i].at, &input[i].priority); // Input process details
    }

    schedule(input, n); // Schedule processes based on arrival time and priority
    int* response = find_response(input, n); // Calculate response times
    int* turntime = find_tat(input, n); // Calculate turnaround times
    int* waittime = find_wt(input, turntime, n); // Calculate waiting times
    
    // Print table headers with appropriate column spacing
    printf("%8s %8s %8s %8s %8s %12s %10s %12s %8s\n", "Process", "Burst", "Arrival", "Priority", "Start", "Completion", "Response", "Turn Around", "Waiting");
    
    // Print each process's details in the formatted table
    for (int i = 0; i < n; i++) {
        printf("%8s%d %8d %8d %8d %8d %12d %10d %12d %8d\n",
               "P", input[i].id, input[i].bt, input[i].at, input[i].priority,
               input[i].start, input[i].comp, response[i],
               turntime[i], waittime[i]);
    }

    // Free dynamically allocated memory
    free(input);
    free(response);
    free(turntime);
    free(waittime);
    return 0;
}
