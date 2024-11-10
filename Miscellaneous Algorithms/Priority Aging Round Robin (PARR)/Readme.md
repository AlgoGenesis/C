Overview
The Priority Aging Round Robin (PARR) algorithm is an enhanced version of the Round Robin (RR) scheduling algorithm, which incorporates priority aging to ensure that processes with lower priority eventually get executed. This algorithm is designed to combine the fairness of Round Robin with the flexibility of Priority Scheduling, preventing starvation for lower-priority processes by "aging" their priorities over time.

Round Robin (RR): Assigns a fixed time slice (or quantum) to each process in a cyclic order. It's known for its simplicity and fairness, but it does not consider process priority, which can lead to low-priority tasks being starved if high-priority tasks keep getting executed.

Priority Aging: A technique where the priority of a process gradually increases the longer it waits. This ensures that low-priority processes are eventually scheduled for execution.

How the Algorithm Works
Initialization:

Each process is assigned an initial priority.
A time quantum is set (for example, 10 ms).
Round Robin Scheduling:

The processes are placed in a queue.
In each cycle, a process is assigned a time slice (time quantum) to execute.
After each quantum, the process is moved to the back of the queue if it hasn't finished.
Priority Aging:

The priority of each process increases gradually after every cycle it waits (i.e., each time it is not executed).
The priority increment ensures that lower-priority processes get scheduled sooner as their priority increases over time.
Execution:

The process with the highest priority is given the CPU first. If two processes have the same priority, Round Robin scheduling is used to determine which process gets executed.
Once a process completes its quantum or finishes execution, it is removed from the queue.
Reordering:

After each cycle, the process queue is reordered based on the current priorities of the processes. This ensures that processes with higher priority are executed first.
Theory Behind PARR
Fairness: Like Round Robin, PARR ensures that every process gets a chance to execute for a fixed time slice, thereby preventing any one process from monopolizing the CPU.
Starvation Prevention: The priority aging mechanism prevents starvation by gradually increasing the priority of waiting processes, ensuring that lower-priority processes get executed eventually.
Dynamic Prioritization: PARR dynamically adjusts priorities, allowing the system to adapt to changing workload conditions by favoring processes that have been waiting longer or are in danger of starvation.
Time and Space Complexity
Time Complexity:
Round Robin Scheduling: Each process is executed in a cyclic manner, and a time slice is allocated to each process. Thus, for n processes, it will take O(n) time to complete one cycle, assuming the time quantum is constant.

Priority Aging: The aging process involves updating the priority of each process every time it doesn't execute. The time complexity for priority aging in each cycle is O(n) as it requires a check and update of the priority for each process.

Reordering the Queue: After each quantum, the process queue may need to be reordered based on the updated priorities. This can be done in O(n log n) time using a sorting algorithm like QuickSort or MergeSort.

Overall Time Complexity: In the worst case, the overall time complexity is O(n log n) due to the need to sort the processes by priority after each cycle.

Space Complexity:
Space Complexity: The space complexity is O(n) because the algorithm uses a queue to store n processes and their associated data (including priorities and time slices). The size of the queue remains proportional to the number of processes.

README: Priority Aging Round Robin (PARR) Algorithm
Overview
The Priority Aging Round Robin (PARR) algorithm is an enhanced version of the Round Robin (RR) scheduling algorithm, which incorporates priority aging to ensure that processes with lower priority eventually get executed. This algorithm is designed to combine the fairness of Round Robin with the flexibility of Priority Scheduling, preventing starvation for lower-priority processes by "aging" their priorities over time.

Round Robin (RR): Assigns a fixed time slice (or quantum) to each process in a cyclic order. It's known for its simplicity and fairness, but it does not consider process priority, which can lead to low-priority tasks being starved if high-priority tasks keep getting executed.

Priority Aging: A technique where the priority of a process gradually increases the longer it waits. This ensures that low-priority processes are eventually scheduled for execution.

How the Algorithm Works
Initialization:

Each process is assigned an initial priority.
A time quantum is set (for example, 10 ms).
Round Robin Scheduling:

The processes are placed in a queue.
In each cycle, a process is assigned a time slice (time quantum) to execute.
After each quantum, the process is moved to the back of the queue if it hasn't finished.
Priority Aging:

The priority of each process increases gradually after every cycle it waits (i.e., each time it is not executed).
The priority increment ensures that lower-priority processes get scheduled sooner as their priority increases over time.
Execution:

The process with the highest priority is given the CPU first. If two processes have the same priority, Round Robin scheduling is used to determine which process gets executed.
Once a process completes its quantum or finishes execution, it is removed from the queue.
Reordering:

After each cycle, the process queue is reordered based on the current priorities of the processes. This ensures that processes with higher priority are executed first.
Theory Behind PARR
Fairness: Like Round Robin, PARR ensures that every process gets a chance to execute for a fixed time slice, thereby preventing any one process from monopolizing the CPU.
Starvation Prevention: The priority aging mechanism prevents starvation by gradually increasing the priority of waiting processes, ensuring that lower-priority processes get executed eventually.
Dynamic Prioritization: PARR dynamically adjusts priorities, allowing the system to adapt to changing workload conditions by favoring processes that have been waiting longer or are in danger of starvation.
Time and Space Complexity
Time Complexity:
Round Robin Scheduling: Each process is executed in a cyclic manner, and a time slice is allocated to each process. Thus, for n processes, it will take O(n) time to complete one cycle, assuming the time quantum is constant.

Priority Aging: The aging process involves updating the priority of each process every time it doesn't execute. The time complexity for priority aging in each cycle is O(n) as it requires a check and update of the priority for each process.

Reordering the Queue: After each quantum, the process queue may need to be reordered based on the updated priorities. This can be done in O(n log n) time using a sorting algorithm like QuickSort or MergeSort.

Overall Time Complexity: In the worst case, the overall time complexity is O(n log n) due to the need to sort the processes by priority after each cycle.

Space Complexity:
Space Complexity: The space complexity is O(n) because the algorithm uses a queue to store n processes and their associated data (including priorities and time slices). The size of the queue remains proportional to the number of processes.

Key Components in the Code:
Process Structure: Each process has an id, priority, and remaining_time.
Priority Aging: The priorityAging function increases the priority of processes that have not completed execution.
Round Robin Execution: The roundRobin function simulates the Round Robin scheduling, applying the time quantum and updating the process states after each cycle.
Advantages of PARR:
Fairness: All processes are given a fair share of the CPU through Round Robin scheduling.
Prevents Starvation: The priority aging ensures that even lower-priority processes eventually get executed, preventing starvation.
Adaptability: By dynamically adjusting priorities, PARR adapts to changing system conditions and workload distributions.
Disadvantages of PARR:
Overhead: Priority aging and reordering the queue introduce some overhead, which might reduce the system's overall efficiency.
Complexity: Compared to simple Round Robin, PARR adds complexity due to priority management and dynamic adjustments.
