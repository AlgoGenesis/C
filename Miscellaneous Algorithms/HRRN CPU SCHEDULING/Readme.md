The Highest Response Ratio Next (HRRN) scheduling algorithm is a non-preemptive scheduling algorithm used in operating systems for process management. It is designed to reduce the average waiting time and improve overall efficiency. The key feature of HRRN is that it schedules the process with the highest response ratio first, which is calculated as:

Response Ratio= (Waiting Time+Burst Time)/Burst Time


Where:

1.Waiting Time is the time the process has been waiting in the queue.
2.Burst Time is the estimated execution time of the process.

Understanding the Formula:

1.If a process has been waiting for a long time, its waiting time becomes large, increasing the response ratio and its priority.
2.If a process has a short burst time, it also gets a higher response ratio relative to its burst time, promoting shorter processes as well.

This formula balances between short and long processes, allowing processes with both high burst times and long waiting times to get scheduled without starving others.

Key Characteristics of HRRN:

1.Non-Preemptive: Once a process starts execution, it cannot be interrupted until it completes.
2.Dynamic Priority Adjustment: Each process's priority is adjusted dynamically based on its waiting time and burst time, making it fairer than some other scheduling algorithms.
3.Starvation Reduction: By increasing the response ratio over time, processes that have been waiting for a long period will eventually get scheduled, preventing them from being starved indefinitely.

Working of HRRN Scheduling Algorithm:

1.Arrival and Sorting: When a new set of processes arrive, they are sorted by arrival time to ensure that they are handled in the correct sequence.
2.Response Ratio Calculation: For each process that has arrived and is waiting, the response ratio is calculated.
3.Selection of Process: The process with the highest response ratio is selected to execute next.
4.Execution: The selected process is executed completely (non-preemptively), updating the current time.
5.Re-calculation: After the completion of each process, the response ratio is re-calculated for the remaining waiting processes.

Time Complexity
The complexity of HRRN largely depends on two factors:

Sorting the processes initially by arrival time: O(n^2) of O(nlogn)
Calculating response ratios and selecting the process with the highest ratio at each scheduling step: O(n^2)
overal time complexity-O(n^2)
Space Complexity
The algorithm uses an array of structs to store process details:

Space complexity: 
O(n), where 
n is the number of processes.

Pros and Cons of HRRN
Pros:

1.Fairly distributes CPU time among processes.
2.Reduces waiting time and turnaround time compared to FCFS and SJF.
3.Prevents starvation effectively.
Cons:

1.It is more complex than simpler algorithms like FCFS and SJF.
2.Requires periodic calculation of response ratios, increasing computational overhead.
3.The HRRN scheduling algorithm is highly efficient in scenarios where fairness is essential, and the system needs to manage both short and long processes equitably without risking starvation.

​
