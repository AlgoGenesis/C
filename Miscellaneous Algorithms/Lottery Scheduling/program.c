#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a process
struct Process {
    int pid;          // Process ID
    int burst_time;   // CPU burst time
    int tickets;      // Number of tickets (priority)
};

// Function to perform lottery scheduling
void lotteryScheduling(struct Process processes[], int n) {
    int total_tickets = 0;
    int time = 0;

    // Calculate total number of tickets
    for (int i = 0; i < n; i++) {
        total_tickets += processes[i].tickets;
    }

    srand(time(NULL));  // Seed for random number generation

    while (n > 0) {
        // Draw a winning ticket
        int winning_ticket = rand() % total_tickets + 1;
        int ticket_counter = 0;
        int chosen_index = -1;

        // Find the process with the winning ticket
        for (int i = 0; i < n; i++) {
            ticket_counter += processes[i].tickets;
            if (ticket_counter >= winning_ticket) {
                chosen_index = i;
                break;
            }
        }

        // Execute the chosen process
        printf("Process %d is selected with burst time %d\n", processes[chosen_index].pid, processes[chosen_index].burst_time);
        time += processes[chosen_index].burst_time;
        printf("Process %d completed at time %d\n", processes[chosen_index].pid, time);

        // Update total tickets and remove the process from the list
        total_tickets -= processes[chosen_index].tickets;
        
        // Shift remaining processes
        for (int i = chosen_index; i < n - 1; i++) {
            processes[i] = processes[i + 1];
        }
        n--;  // Reduce the number of processes
    }
}

int main() {
    struct Process processes[] = {
        {1, 5, 10},
        {2, 3, 20},
        {3, 7, 5},
        {4, 4, 15}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Lottery Scheduling:\n");
    lotteryScheduling(processes, n);

    return 0;
}
