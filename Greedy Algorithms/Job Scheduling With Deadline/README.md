### **Job Scheduling Algorithm with Deadline (Greedy Approach)**

### Problem Description:
The Job Scheduling problem is a classical optimization problem where a set of jobs needs to be scheduled such that the profit is maximized. Each job has:
- A deadline by which it must be completed.
- A profit associated with it.

Given n jobs, each with a deadline and a profit, the objective is to maximize the total profit by selecting jobs that can be completed within their deadlines.

### Approach:
The algorithm uses a greedy approach where jobs are sorted in decreasing order of their profits. We then try to schedule jobs in the latest possible time slots before their deadline, filling up the schedule greedily to maximize profit.

### Algorithm Steps:

1. Sort all jobs in descending order of profit.
2. Iterate over the sorted jobs and attempt to schedule them in the latest available time slot before their deadline.
3. Print the job sequence that maximizes the profit.

### Code Explanation:

**typedef struct Jobs:** Defines a structure Jobs to store job ID, deadline, and profit.
**compare():** Custom comparator function to sort jobs by profit in decreasing order.
**min():** Helper function to return the minimum of two integers.
**qsort():** Standard library function used to sort jobs based on the profit.
The main logic then attempts to schedule jobs in available time slots before their deadlines.

### Sample Input:

Enter the number of jobs: 4            
Enter job details (id, deadline, profit) for each job:             
Job 1: a 4 20            
Job 2: b 1 10               
Job 3: c 1 40            
Job 4: d 1 30            

### Sample Output:

Following is the maximum profit sequence of Jobs:
c d a

### Explanation of Sample:

Job c has the highest profit and is scheduled first.
Job d is scheduled next as it also has a high profit but must be done before its deadline.
Job a is scheduled because there is a remaining slot before its deadline.
Job b is not scheduled because its profit is lower, and no slots are available before its deadline.

### Time Complexity:
Sorting the jobs: Sorting n jobs based on their profit takes O(n log n) time.
Scheduling the jobs: For each job, we try to find an available slot in O(n) time. Therefore, the total time complexity for scheduling is O(n^2).

Thus, the overall time complexity is O(n log n + n^2), where n is the number of jobs.
