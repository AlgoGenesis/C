This program simulates Lottery Scheduling, a CPU scheduling algorithm that allocates CPU time to processes based on "lottery tickets." Each process is assigned a certain number of tickets, which reflects its priority or share of CPU time. Processes with more tickets have a higher chance of winning the "lottery" and being selected to run.

Key Components
Process Structure:

The Process structure represents each process, holding:
pid: the process ID, a unique identifier.
burst_time: the time required by the process to complete.
tickets: the number of lottery tickets (or the process priority).
lotteryScheduling Function:

Total Ticket Calculation: Calculates the total number of tickets available across all processes.
Winning Ticket Selection: Chooses a random ticket number between 1 and total_tickets using rand(), simulating a lottery draw.
Process Selection: Finds the process that "owns" the winning ticket based on cumulative ticket counts.
Execution Simulation: The chosen process is "executed" by adding its burst time to a time counter, simulating the passage of time in a real CPU.
Process Removal: After a process completes, it's removed from the list, and the array of processes is adjusted to fill in the gap.
Main Function:

Initializes an array of processes with different burst times and ticket counts.
Calls the lotteryScheduling function to simulate the scheduling and outputs which process is selected in each iteration, along with the total completion time for each process.



Pros and Cons of Lottery Scheduling
Lottery Scheduling is an interesting, probabilistic approach to CPU scheduling, offering both advantages and disadvantages. Here’s a breakdown:

Pros
Fairness:

Lottery scheduling can provide a fair share of CPU time, as each process has a chance of being selected proportional to its number of tickets. This probabilistic fairness avoids the strict hierarchy found in priority scheduling.
Flexible Prioritization:

Adjusting process priorities is simple; increasing or decreasing a process’s tickets directly affects its likelihood of execution. This makes it easy to dynamically adjust priorities without complex mechanisms.
Reduced Starvation:

Unlike priority-based scheduling, which can lead to starvation of low-priority processes, lottery scheduling gives all processes a chance to execute, even those with fewer tickets, thus reducing the likelihood of starvation.
Simple Implementation:

The algorithm is straightforward to implement as it primarily relies on random selection within a ticket range. This simplicity can make it a practical choice for certain applications, especially in experimental and academic settings.
Cons
Randomness and Variability:

The probabilistic nature can result in variability; a process with few tickets may win multiple times in a row, or a high-priority process might not win as often as expected. This can lead to inconsistent response times.
Not Suitable for Real-Time Systems:

Lottery scheduling isn’t ideal for systems with strict deadlines, as the randomness of selection doesn’t guarantee timely execution. Real-time applications need predictable and deterministic scheduling.
Lack of Precise Control:

Since scheduling is based on randomness, there is less control over exact scheduling order, which can be a drawback in systems where process order and predictability are important.
Overhead in Random Ticket Selection:

Frequent generation of random numbers and counting through tickets can add overhead, especially as the number of processes and tickets grows. This overhead can impact performance in systems with many processes.
Potential for Starvation (Rare Cases):

Although rare, there's still a small chance that a process with very few tickets could be "unlucky" and go unselected for extended periods, particularly in systems with a wide disparity in ticket counts.
