#include <stdio.h>
#include <stdlib.h>

struct Resource;

typedef struct Process {
    int id;
    struct Process *next_process; 
    struct Resource *requested_resource;
    int visited; 
} Process;

typedef struct Resource {
    int id;
    struct Resource *next_resource; 
    struct Process *allocated_process; 
} Resource; 

Process *Phead = NULL;
Resource *Rhead = NULL;

void Allocate(int R, int P);
int DFS(Process *process);
int DetectCycle();
void Request(int P, int R);
void Cleanup();


int main() {
    // Allocate(ResourceId, ProcessId);
    Allocate(1, 1);
    Allocate(2, 2);

    // Request(ProcessId, ResourceId);
    Request(1, 2);
    Request(2, 1); 

    Cleanup();
    return 0;
}

// Function to allocate a resource to a process
void Allocate(int R, int P) {
    // Check if the process with ID P already exists in the list
    Process *Ptemp = Phead;
    while (Ptemp != NULL) {
        if (Ptemp->id == P) {
            printf("Process with ID %d already exists.\n", P);
            return;
        }
        Ptemp = Ptemp->next_process;
    }

    // Check if the resource with ID R already exists in the list
    Resource *Rtemp = Rhead;
    while (Rtemp != NULL) {
        if (Rtemp->id == R) {
            printf("Resource with ID %d already exists.\n", R);
            return;
        }
        Rtemp = Rtemp->next_resource;
    }

    // Allocate memory for the new process and resource
    Process *ProcessNode = (Process *)malloc(sizeof(Process));
    Resource *ResourceNode = (Resource *)malloc(sizeof(Resource));
    if (ProcessNode == NULL || ResourceNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize the new process
    ProcessNode->id = P;
    ProcessNode->requested_resource = NULL; 
    ProcessNode->next_process = NULL;
    ProcessNode->visited = 0;

    // Initialize the new resource
    ResourceNode->id = R;
    ResourceNode->allocated_process = ProcessNode; 
    ResourceNode->next_resource = NULL;

    // Insert the process at the end of the process list
    if (Phead == NULL) {
        Phead = ProcessNode;
    } else {
        Ptemp = Phead;
        while (Ptemp->next_process != NULL) {
            Ptemp = Ptemp->next_process;
        }
        Ptemp->next_process = ProcessNode;
    }

    // Insert the resource at the end of the resource list
    if (Rhead == NULL) {
        Rhead = ResourceNode;
    } else {
        Rtemp = Rhead;
        while (Rtemp->next_resource != NULL) {
            Rtemp = Rtemp->next_resource;
        }
        Rtemp->next_resource = ResourceNode;
    }

    printf("Allocation: Resource R%d --> Process P%d\n", R, P);
}

// Function to perform DFS to detect cycles in the resource allocation graph
int DFS(Process *process) {
    // If the process is NULL, there's nothing to explore
    if (process == NULL) {
        return 0;
    }

    // If process is already visited, a cycle is detected
    if (process->visited == 1) {
        return 1; // Cycle detected
    }

    // Mark the process as visited
    process->visited = 1;

    // Recursively visit the allocated process of the requested resource
    if (process->requested_resource != NULL) {
        Process *WaitingFor = process->requested_resource->allocated_process;
        if (DFS(WaitingFor)) {
            return 1; // Cycle detected
        }
    }

    // Reset visited status before returning to allow further detection
    process->visited = 0;
    return 0; // No cycle detected
}

// Function to check for cycles in the resource allocation graph
int DetectCycle() {
    // Iterates through each process to check for cycles
    Process *current_process = Phead;
    while (current_process != NULL) {
        if (DFS(current_process)) {
            return 1; // Cycle detected
        }
        current_process = current_process->next_process;
    }
    return 0; // No cycle detected
}

// Function to request a resource for a process
void Request(int P, int R) {
    // Check if graph is empty
    if (Phead == NULL || Rhead == NULL) {
        printf("Graph is empty.\n");
        return;
    }

    // Locate the process with ID P in the list
    Process *Ptemp = Phead, *ProcessNode = NULL;
    while (Ptemp != NULL) {
        if (Ptemp->id == P) {
            ProcessNode = Ptemp;
            break;
        }
        Ptemp = Ptemp->next_process;
    }

    // Locate the resource with ID R in the list
    Resource *Rtemp = Rhead, *ResourceNode = NULL;
    while (Rtemp != NULL) {
        if (Rtemp->id == R) {
            ResourceNode = Rtemp;
            break;
        }
        Rtemp = Rtemp->next_resource;
    }

    // Check if the process exists
    if (ProcessNode == NULL) {
        printf("Process with ID %d not found.\n", P);
        return;
    }

    // Check if the resource exists
    if (ResourceNode == NULL) {
        printf("Resource with ID %d not found.\n", R);
        return;
    }

    // Check if process already has a resource request
    if (ProcessNode->requested_resource != NULL) {
        printf("Process %d already has a resource request.\n", P);
        return;
    }

    // Assign the resource to the process as its requested resource
    ProcessNode->requested_resource = ResourceNode;    
    printf("\nRequest: Process P%d --> Resource R%d\n", P, R);

    // Detect any cycles that may have formed after the request
    if (DetectCycle()) {
        printf("\nCycle detected in the resource allocation graph.\n\n");
    } else {
        printf("\nNo cycles detected in the resource allocation graph.\n\n");
    }
}

// Function to clean up memory allocated for processes and resources
void Cleanup() {
    // Free memory allocated for each process in the list
    Process *ptemp = Phead;
    while (ptemp != NULL) {
        Process *node = ptemp;
        ptemp = ptemp->next_process;
        free(node);
    }

    // Free memory allocated for each resource in the list
    Resource *Rtemp = Rhead;
    while (Rtemp != NULL) {
        Resource *node = Rtemp;
        Rtemp = Rtemp->next_resource;
        free(node);
    }
}
