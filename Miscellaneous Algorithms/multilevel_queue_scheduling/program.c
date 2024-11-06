#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure to represent a process
struct Process {
    int pid;       // Process ID
    int burstTime; // Burst time
    int priority;  // Priority (1 = high, 2 = low)
    int arrivalTime; // Arrival time for Round Robin
};

// Function for FCFS Scheduling for high-priority queue
void FCFS(queue<Process> &highPriorityQueue) {
    cout << "\nExecuting High-Priority Queue (FCFS):\n";
    int time = 0;
    while (!highPriorityQueue.empty()) {
        Process p = highPriorityQueue.front();
        highPriorityQueue.pop();
        cout << "Process " << p.pid << " executed from time " << time << " to " << time + p.burstTime << endl;
        time += p.burstTime;
    }
}

// Function for Round Robin Scheduling for low-priority queue
void RoundRobin(queue<Process> &lowPriorityQueue, int timeQuantum) {
    cout << "\nExecuting Low-Priority Queue (Round Robin):\n";
    int time = 0;
    queue<Process> readyQueue = lowPriorityQueue;

    while (!readyQueue.empty()) {
        Process p = readyQueue.front();
        readyQueue.pop();

        if (p.burstTime > timeQuantum) {
            cout << "Process " << p.pid << " executed from time " << time << " to " << time + timeQuantum << endl;
            time += timeQuantum;
            p.burstTime -= timeQuantum;
            readyQueue.push(p); // Put back into queue if not finished
        } else {
            cout << "Process " << p.pid << " executed from time " << time << " to " << time + p.burstTime << endl;
            time += p.burstTime;
        }
    }
}

int main() {
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    
    // Taking process information from the user
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Process " << i + 1 << ":\n";
        processes[i].pid = i + 1; // Automatically assigning process ID
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "Priority (1 = high, 2 = low): ";
        cin >> processes[i].priority;
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
    }

    cout << "\nEnter the time quantum for Round Robin: ";
    cin >> timeQuantum;

    queue<Process> highPriorityQueue;
    queue<Process> lowPriorityQueue;

    // Sort processes into queues based on priority
    for (auto &process : processes) {
        if (process.priority == 1) {
            highPriorityQueue.push(process);
        } else {
            lowPriorityQueue.push(process);
        }
    }

    // Execute high-priority queue with FCFS
    FCFS(highPriorityQueue);

    // Execute low-priority queue with Round Robin
    RoundRobin(lowPriorityQueue, timeQuantum);

    return 0;
}
