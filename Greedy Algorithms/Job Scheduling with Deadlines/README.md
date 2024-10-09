**Job Scheduling with Deadlines**

### Description

This program solves the Job Scheduling with Deadlines problem using a greedy approach. The goal is to select and schedule jobs in such a way that the total profit is maximized, considering that each job has a deadline and a profit associated with it. The program finds the best schedule for a given set of jobs while adhering to their deadlines and ensuring that no two jobs overlap.

### Structures

**Job**

A structure to represent a job with its ID, deadline, and profit.

**Members**:

- char id: The unique identifier for the job (e.g., 'a', 'b', 'c').

- int deadline: The maximum time by which the job must be completed.

- int profit: The profit gained if the job is completed before or on its deadline.

### Functions

1. int compare(const void *a, const void *b)

A function to compare two jobs based on their profit values, used for sorting the jobs in descending order of profit.

**Returns**:

- A negative value if the profit of the first job is greater than the profit of the second (for sorting in descending order).

- Zero if they have equal profits.

- A positive value if the profit of the first job is less than that of the second.

2. int findMaxDeadline(Job jobs[], int n)

A function to find the maximum deadline among all the given jobs.

**Returns**:

The maximum deadline value.

3. void jobScheduling(Job jobs[], int n)

The main function that performs the job scheduling. It arranges the jobs in such a way that the total profit is maximized, while adhering to the deadlines of each job.

**Details**:

1. Sort Jobs:

Sorts all given jobs in descending order of profit using the compare() function.

2. Initialize Time Slots:

Creates an array of slots to keep track of free time slots up to the maximum deadline.

3. Place Jobs in Slots:

Iterates through the sorted jobs and tries to place each job in the latest possible free slot before its deadline.

4. Calculate Total Profit:

Calculates the total profit by summing up the profits of all scheduled jobs.

5. Output:

Prints the job sequence and total profit for the scheduled jobs.

### Main Function

Details:

- Defines an array of jobs and initializes each job with its ID, deadline, and profit.

- Prompts the user to enter the number of jobs (n).

- Calls the jobScheduling function to schedule jobs and maximize profit.

- Displays the scheduled jobs and the total profit.

### Memory Management

The program uses fixed-size arrays and does not employ dynamic memory allocation, so no special memory management is required.


### Example

**Input**:

Number of Jobs: 5

JobID Deadline Profit
a     2       100
b     1       19
c     2       27
d     1       25
e     3       15


**Output**:

Scheduled Jobs: a c e

Total Profit: 142


### Time Complexity

The time complexity of the job scheduling algorithm is **O(n log n)** due to sorting the jobs by their profit. Scheduling the jobs has a complexity of O(n * d), where d is the maximum deadline. 

Thus, the overall time complexity is **O(n log n + n * d)**.