# Resource Allocation and Deadlock Detection Program

## Overview
This C program simulates a basic resource allocation and deadlock detection system. It allows users to allocate resources to processes and request resources on behalf of processes. Using a Depth-First Search (DFS) algorithm, it detects cycles in the resource allocation graph, signaling potential deadlocks in resource requests.

## Features
- **Resource Allocation:** Allocate resources to processes and track ownership.
- **Resource Requesting:** Processes can request additional resources if they do not currently hold them.
- **Deadlock Detection:** Detects cycles in the resource allocation graph, indicating potential deadlocks.
- **Memory Cleanup:** Frees dynamically allocated memory for processes and resources to prevent memory leaks.

## Function Descriptions
```
Allocate(int R, int P)
```

Allocates a resource (with ID R) to a process (with ID P) if neither currently exists in the system.

- **Parameters:**
  - int R - Resource ID.
  - int P - Process ID.

- **Behavior:** Checks if a process or resource with the specified ID already exists. If not, it creates and links the resource to the process.

---
```
Request(int P, int R)
```

Requests a resource (with ID R) for a process (with ID P).

- **Parameters:**
  - int P - Process ID.
  - int R - Resource ID.

- **Behavior:** Assigns the requested resource to the process. Afterward, it invokes the DetectCycle function to check if this request causes a cycle, indicating a potential deadlock. The function notifies the user if a deadlock is detected.

---

```
DetectCycle()
```

Iterates over all processes to detect cycles in the resource allocation graph.

- **Returns:** 1 if a cycle (deadlock) is detected, 0 otherwise.
- **Behavior:** Calls DFS on each process to trace resource dependencies. If any cycle is detected in the graph, it signifies a potential deadlock.

--- 

```
DFS(Process *process)
```

Performs Depth-First Search to trace through the resource allocation graph and detect cycles.

- Parameters:
    - Process *process - Pointer to the process structure to begin the DFS.
- **Returns:** 1 if a cycle is found, 0 if not.
- **Behavior:** Marks each visited process. If it revisits a marked process in the same chain, a cycle is present.

--- 

```
Cleanup()
```

Frees all dynamically allocated memory used for processes and resources.

- **Behavior:** Traverses the lists of processes and resources, freeing each node to prevent memory leaks.