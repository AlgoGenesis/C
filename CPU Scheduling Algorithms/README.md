# Process Scheduling Simulation in C (First-Come, First-Serve Algorithm)

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [First-Come, First-Serve (FCFS) Algorithm](#first-come-first-serve-fcfs-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **First-Come, First-Serve (FCFS) scheduling** algorithm for processes in an operating system. In FCFS scheduling, the CPU processes requests in the order of their arrival, ensuring that each process is completed before the next begins. This code calculates and displays essential metrics like **response time**, **turnaround time**, and **waiting time** for each process.

The FCFS algorithm is a non-preemptive scheduling algorithm and is straightforward to implement, making it ideal for understanding basic process scheduling.

## Features

- **Sorts processes by arrival time** to ensure the First-Come, First-Serve order.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## First-Come, First-Serve (FCFS) Algorithm

The **FCFS** scheduling algorithm follows a non-preemptive approach where processes are served in the order of their arrival. Here’s how it works in this program:

1. **Sorting by Arrival Time**: The program first sorts all processes by their arrival times. If two processes have the same arrival time, they are further sorted by their ID.
2. **Sequential Execution**: Each process begins execution as soon as the CPU is available, based on the completion of the previous process.
3. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: When the process begins execution.
   - **Completion Time**: When the process finishes execution.
   - **Response Time**: Difference between start time and arrival time.
   - **Turnaround Time**: Difference between completion time and arrival time.
   - **Waiting Time**: Difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_response(struct Process* input, int n)`
   - Calculates the **response time** for each process.
   - Formula: **Response Time** = `start time - arrival time`

### 2. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 3. `find_wt(struct Process* input, int* tat, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 4. `schedule(struct Process* input, int n)`
   - Sorts processes by arrival time using the FCFS approach.
   - Determines **start time** and **completion time** for each process based on its burst time and order of arrival.

### 5. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by arrival time, and by ID if arrival times are equal.

## Requirements

To run this program, you need:
- A C compiler like `gcc`.
- Basic command-line skills for compiling and executing C programs.






# Process Scheduling Simulation in C (Shortest Job First Algorithm)

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Shortest Job First (SJF) Algorithm](#shortest-job-first-sjf-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **Shortest Job First (SJF) scheduling** algorithm for processes in an operating system. In SJF scheduling, the CPU selects the process with the shortest burst time first, ensuring that shorter processes are completed before longer ones. This code calculates and displays essential metrics like **response time**, **turnaround time**, and **waiting time** for each process.

The SJF algorithm is a non-preemptive scheduling algorithm and is particularly efficient when short processes need to be prioritized for faster completion.

## Features

- **Sorts processes by burst time** to ensure the Shortest Job First order.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## Shortest Job First (SJF) Algorithm

The **SJF** scheduling algorithm follows a non-preemptive approach where processes are executed based on the shortest burst time first. Here’s how it works in this program:

1. **Sorting by Burst Time**: The program first sorts all processes by their burst time. If two processes have the same burst time, they are further sorted by their arrival time.
2. **Sequential Execution**: Each process begins execution as soon as the CPU is available, based on the completion of the previous process.
3. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: When the process begins execution.
   - **Completion Time**: When the process finishes execution.
   - **Response Time**: Difference between start time and arrival time.
   - **Turnaround Time**: Difference between completion time and arrival time.
   - **Waiting Time**: Difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 2. `find_wt(struct Process* input, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 3. `schedule(struct Process* input, int n)`
   - Sorts processes by burst time using the SJF approach.
   - Determines **start time** and **completion time** for each process based on its burst time and order of execution.

### 4. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by burst time, and by arrival time if burst times are equal.

## Requirements
# Process Scheduling Simulation in C (Shortest Job First Algorithm)

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Shortest Job First (SJF) Algorithm](#shortest-job-first-sjf-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **Shortest Job First (SJF) scheduling** algorithm for processes in an operating system. In SJF scheduling, the CPU selects the process with the shortest burst time first, ensuring that shorter processes are completed before longer ones. This code calculates and displays essential metrics like **response time**, **turnaround time**, and **waiting time** for each process.

The SJF algorithm is a non-preemptive scheduling algorithm and is particularly efficient when short processes need to be prioritized for faster completion.

## Features

- **Sorts processes by burst time** to ensure the Shortest Job First order.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## Shortest Job First (SJF) Algorithm

The **SJF** scheduling algorithm follows a non-preemptive approach where processes are executed based on the shortest burst time first. Here’s how it works in this program:

1. **Sorting by Burst Time**: The program first sorts all processes by their burst time. If two processes have the same burst time, they are further sorted by their arrival time.
2. **Sequential Execution**: Each process begins execution as soon as the CPU is available, based on the completion of the previous process.
3. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: When the process begins execution.
   - **Completion Time**: When the process finishes execution.
   - **Response Time**: Difference between start time and arrival time.
   - **Turnaround Time**: Difference between completion time and arrival time.
   - **Waiting Time**: Difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 2. `find_wt(struct Process* input, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 3. `schedule(struct Process* input, int n)`
   - Sorts processes by burst time using the SJF approach.
   - Determines **start time** and **completion time** for each process based on its burst time and order of execution.

### 4. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by burst time, and by arrival time if burst times are equal.

## Requirements

To run this program, you need:
- A C compiler like `gcc`.
- Basic command-line skills for compiling and executing C programs.




# Process Scheduling Simulation in C (Shortest Remaining Time First Algorithm)

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Shortest Remaining Time First (SRTF) Algorithm](#shortest-remaining-time-first-srtf-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **Shortest Remaining Time First (SRTF) scheduling** algorithm for processes in an operating system. In SRTF scheduling, the CPU selects the process with the shortest remaining burst time first, ensuring that processes with shorter remaining burst times are executed first. If a new process arrives with a shorter burst time than the currently running process, the CPU is preempted to execute the new process.

The SRTF algorithm is a **preemptive scheduling algorithm** that is particularly efficient in reducing waiting time, as it prioritizes processes with the least remaining time.

## Features

- **Preemptive Scheduling**: The process with the shortest remaining burst time is executed first. If a new process arrives with a shorter remaining burst time than the current one, it preempts the current process.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## Shortest Remaining Time First (SRTF) Algorithm

The **SRTF** scheduling algorithm works as follows:

1. **Preemptive Execution**: The CPU always executes the process with the shortest remaining burst time. If a new process arrives with a shorter remaining burst time than the current one, the CPU is preempted, and the new process is executed.
2. **Sorting**: Initially, processes are sorted by their arrival time.
3. **Execution**: The system executes processes based on their remaining burst times. At each unit of time, it chooses the process with the shortest remaining burst time.
4. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: The time when the process starts execution.
   - **Completion Time**: The time when the process finishes execution.
   - **Response Time**: The time difference between the start time and arrival time.
   - **Turnaround Time**: The time difference between the completion time and arrival time.
   - **Waiting Time**: The time difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_response(struct Process* input, int n)`
   - Calculates the **response time** for each process.
   - Formula: **Response Time** = `start time - arrival time`

### 2. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 3. `find_wt(struct Process* input, int* tat, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 4. `schedule(struct Process* input, int n)`
   - Simulates the **Shortest Remaining Time First** scheduling.
   - The processes are sorted initially by their arrival time.
   - At each unit of time, the process with the shortest remaining burst time is executed.
   - The start and completion times for each process are calculated dynamically as processes are executed.

### 5. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by arrival time, and by ID if arrival times are equal.

## Requirements

To run this program, you need:
- A C compiler like `gcc`.
- Basic command-line skills for compiling and executing C programs.


# Process Scheduling Simulation in C (Priority Scheduling Algorithm)

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Priority Scheduling Algorithm](#priority-scheduling-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **Priority Scheduling** algorithm for processes in an operating system. In Priority Scheduling, each process is assigned a priority, and the process with the highest priority is executed first. If two processes have the same priority, the one with the earlier arrival time is executed first. This code calculates and displays essential metrics like **response time**, **turnaround time**, and **waiting time** for each process.

Priority scheduling is a **non-preemptive** scheduling algorithm, which means that once a process starts execution, it will run to completion before the next process starts.

## Features

- **Sorts processes by priority** to ensure the highest priority process is executed first.
- **Handles ties in priority** by sorting processes with equal priority by arrival time.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## Priority Scheduling Algorithm

The **Priority Scheduling** algorithm works as follows:

1. **Sorting by Priority and Arrival Time**: The program first sorts all processes by their arrival times. If two processes have the same arrival time, they are further sorted by their priority. Processes with higher priority (numerically smaller value) are executed first.
2. **Sequential Execution**: Each process begins execution as soon as the CPU is available, based on the priority and arrival order.
3. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: When the process begins execution.
   - **Completion Time**: When the process finishes execution.
   - **Response Time**: Difference between start time and arrival time.
   - **Turnaround Time**: Difference between completion time and arrival time.
   - **Waiting Time**: Difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_response(struct Process* input, int n)`
   - Calculates the **response time** for each process.
   - Formula: **Response Time** = `start time - arrival time`

### 2. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 3. `find_wt(struct Process* input, int* tat, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 4. `schedule(struct Process* input, int n)`
   - Sorts processes by arrival time and priority using the **Priority Scheduling** approach.
   - Determines **start time** and **completion time** for each process based on its priority and burst time.
   - If two processes have the same priority, they are further sorted by arrival time.

### 5. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by arrival time, and by priority if arrival times are equal.

## Requirements

To run this program, you need:
- A C compiler like `gcc`.
- Basic command-line skills for compiling and executing C programs.
