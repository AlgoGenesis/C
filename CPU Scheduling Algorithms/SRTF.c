#include <stdio.h>
#include <stdlib.h>

// Structure to hold each process's details
struct Process {
    int id, bt, at, start, comp, remaining_bt;
};

// Comparison function for sorting processes by arrival time
int comp(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    if (p1->at == p2->at)
        return p1->id - p2->id; // If arrival times are the same, sort by ID
    return p1->at - p2->at; // Sort by arrival time otherwise
}

// Function to calculate the response time of each process
int* find_response(struct Process* input, int n) {
    int* rt = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        rt[i] = input[i].start - input[i].at;
    }
    return rt;
}

// Function to calculate the turnaround time of each process
int* find_tat(struct Process* input, int n) {
    int* tat = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        tat[i] = input[i].comp - input[i].at;
    }
    return tat;
}

// Function to calculate the waiting time of each process
int* find_wt(struct Process* input, int* tat, int n) {
    int* wt = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - input[i].bt;
    }
    return wt;
}

// Function to simulate the SRTF Scheduling Algorithm
void schedule(struct Process* input, int n) {
    qsort(input, n, sizeof(struct Process), comp); // Sort processes by arrival time
    
    int last_time = 0; // Keeps track of the current time
    int remaining_processes = n; // Number of remaining processes
    int completed = 0;
    
    while (completed < n) {
        int min_bt = __INT_MAX__;
        int idx = -1;
        
        // Find the process with the shortest remaining burst time
        for (int i = 0; i < n; i++) {
            if (input[i].at <= last_time && input[i].remaining_bt > 0 && input[i].remaining_bt < min_bt) {
                min_bt = input[i].remaining_bt;
                idx = i;
            }
        }
        
        if (idx != -1) {
            if (input[idx].remaining_bt == input[idx].bt) {
                input[idx].start = last_time; // Set start time for the first execution
            }
            
            // Execute the process for 1 unit of time
            input[idx].remaining_bt--;
            last_time++;
            
            // If the process is completed
            if (input[idx].remaining_bt == 0) {
                input[idx].comp = last_time; // Set completion time
                completed++;
            }
        } else {
            last_time++; // If no process is ready, increment time
        }
    }
}

// Main program to test the SRTF algorithm
int main() {
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    struct Process* input = (struct Process*)malloc(n * sizeof(struct Process)); 
    for (int i = 0; i < n; i++) {
        printf("Enter the id, burst time and arrival time of process %d:\n", i + 1);
        scanf("%d %d %d", &input[i].id, &input[i].bt, &input[i].at);
        input[i].remaining_bt = input[i].bt; // Initialize remaining burst time
    }

    schedule(input, n);
    
    int* response = find_response(input, n);
    int* turntime = find_tat(input, n);
    int* waittime = find_wt(input, turntime, n);

    printf("%8s %8s %8s %8s %12s %10s %12s %8s\n", "Process", "Burst", "Arrival", "Start", "Completion", "Response", "Turn Around", "Waiting");
    for (int i = 0; i < n; i++) {
        printf("%8s%d %8d %8d %8d %12d %10d %12d %8d\n",
               "P", input[i].id, input[i].bt, input[i].at,
               input[i].start, input[i].comp, response[i],
               turntime[i], waittime[i]);
    }

    free(input);
    free(response);
    free(turntime);
    free(waittime);
    return 0;
}
