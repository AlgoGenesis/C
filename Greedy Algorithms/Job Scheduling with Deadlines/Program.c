#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct Job {
    char id;        // Job Id
    int deadline;   // Deadline of job
    int profit;     // Profit if job is completed before or on deadline
} Job;

// Function to compare two jobs according to their profit
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return (jobB->profit - jobA->profit);
}

// Function to find the maximum deadline in the array of jobs
int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

// Function to schedule jobs to maximize profit
void jobScheduling(Job jobs[], int n) {
    // Step 1: Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Step 2: Find the maximum deadline
    int maxDeadline = findMaxDeadline(jobs, n);

    // Step 3: Create an array to store result (sequence of jobs)
    int slot[maxDeadline]; // Array to keep track of occupied slots
    char jobSequence[maxDeadline]; // To keep track of job ids
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = 0; // Initialize all slots as free
    }

    // Step 4: Iterate through all given jobs
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) { // Free slot found
                slot[j] = 1;    // Mark this slot as occupied
                jobSequence[j] = jobs[i].id; // Save job id in the sequence
                totalProfit += jobs[i].profit; // Add profit
                break;
            }
        }
    }

    // Step 5: Print the job sequence and total profit
    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            printf("%c ", jobSequence[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Array of jobs
    Job jobs[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Print initial job information
    printf("Job List:\n");
    printf("JobID Deadline Profit\n");
    for (int i = 0; i < n; i++) {
        printf(" %c\t%d\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    // Schedule jobs and print result
    jobScheduling(jobs, n);

    return 0;
}


// Output
/* Job List:
JobID Deadline Profit
 a    2    100
 b    1    19
 c    2    27
 d    1    25
 e    3    15

Scheduled Jobs: a c e 
Total Profit: 142
 */