The Highest Response Ratio Next (HRRN) scheduling algorithm is a CPU scheduling technique designed to manage process execution in a way that minimizes wait times and optimizes response for both short and long processes. Unlike the First-Come, First-Served (FCFS) and Shortest Job Next (SJN) scheduling algorithms, HRRN dynamically adjusts priorities based on the current state of each process, aiming to balance fairness and efficiency.
Key Concepts of HRRN:
Response Ratio: HRRN selects the process with the highest response ratio (priority). The response ratio is calculated as:

Response Ratio=(Waiting Time+ Service Time)/Service Time

Waiting Time: The time the process has been waiting in the queue.
Service Time (also known as Burst Time): The time required by the process to complete.
A higher response ratio indicates that a process has been waiting longer and/or has a smaller burst time, giving it priority.

Non-preemptive Nature: Once a process is chosen, it runs to completion. Other processes wait until the running process finishes.

Fairness to Long and Short Jobs: By considering both waiting time and burst time, HRRN gives priority to processes that have waited longer, which can reduce the starvation problem present in some scheduling algorithms like SJN.
Steps in HRRN Scheduling:
1.Calculate the response ratio for each process that has arrived and is waiting.
2.Select the process with the highest response ratio.
3.Execute the chosen process to completion.
4.Repeat steps 1-3 until all processes have been completed.

Time Complexity
Calculating Response Ratios: For each process selection, response ratios for all waiting processes are recalculated, which takes 
O(n) time per selection.
Selection of Process with Maximum Response Ratio: Requires checking n processes
O(n) for each selection.
Thus, if there are 𝑛 processes to schedule, the overall time complexity is:

O(n^2)
This complexity arises because, in the worst case, each of the n processes requires n recalculations and selections.


Space Complexity
Since HRRN requires storing only the process information (arrival time, burst time, waiting time, and response ratio), the space complexity is:
O(n)


Advantages of HRRN
1.Reduced Starvation: HRRN minimizes starvation by favoring processes that have been waiting longer.
2.Balanced for Short and Long Jobs: Short jobs can execute quickly, while long jobs still gain priority as their waiting times increase.
3.Fairness: By factoring both waiting and burst time, HRRN is considered fairer than SJN or FCFS for varied workloads.
Disadvantages of HRRN
1.Non-Preemptive: Once a process starts, it runs to completion, potentially delaying more urgent tasks.
Time Complexity: O(n^2) complexity can be inefficient for systems with a large number of processes.
