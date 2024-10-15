#include <stdio.h>
#include <stdlib.h>

struct Resource;

typedef struct Process {
    int id;
    struct Resource *requested_resource;
    struct Process *next_process; 
    int visited; 
} Process;

typedef struct Resource {
    int id;
    struct Process *allocated_process; 
    struct Resource *next_resource; 
} Resource;

Process *Phead = NULL;
Resource *Rhead = NULL;

void Allocate(int R, int P);
int DFS(Process *process);
int DetectCycle();
void Request(int P, int R);
void Cleanup();


int main() {
    Allocate(1, 1);
    Allocate(2, 2);
    // Request(1, 2);
    Request(2, 1); 

    Cleanup();
    return 0;
}





// Function to allocate a resource to a process
void Allocate(int R, int P) {
    // Allocate a new resource to a process
    Process *Ptemp = Phead;
    while (Ptemp != NULL) {
        if (Ptemp->id == P) {
            printf("Process with ID %d already exists.\n", P);
            return;
        }
        Ptemp = Ptemp->next_process;
    }

    Resource *Rtemp = Rhead;
    while (Rtemp != NULL) {
        if (Rtemp->id == R) {
            printf("Resource with ID %d already exists.\n", R);
            return;
        }
        Rtemp = Rtemp->next_resource;
    }

    Process *ProcessNode = (Process *)malloc(sizeof(Process));
    Resource *ResourceNode = (Resource *)malloc(sizeof(Resource));
    if (ProcessNode == NULL || ResourceNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    ProcessNode->id = P;
    ProcessNode->requested_resource = NULL; 
    ProcessNode->next_process = NULL;
    ProcessNode->visited = 0;

    ResourceNode->id = R;
    ResourceNode->allocated_process = ProcessNode; 
    ResourceNode->next_resource = NULL;

    if (Phead == NULL) {
        Phead = ProcessNode;
    } else {
        Ptemp = Phead;
        while (Ptemp->next_process != NULL) {
            Ptemp = Ptemp->next_process;
        }
        Ptemp->next_process = ProcessNode;
    }

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
    // Perform Depth-First Search to detect cycles
    if (process == NULL) {
        return 0;
    }

    if (process->visited == 1) {
        return 1; // Cycle detected
    }

    process->visited = 1;

    if (process->requested_resource != NULL) {
        Process *allocated_process = process->requested_resource->allocated_process;
        if (DFS(allocated_process)) {
            return 1; // Cycle detected
        }
    }

    process->visited = 0;
    return 0; // No cycle detected
}

// Function to check for cycles in the resource allocation graph
int DetectCycle() {
    // Detect cycles by iterating through all processes
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
    // Request a resource for a specific process
    if (Phead == NULL || Rhead == NULL) {
        printf("Graph is empty.\n");
        return;
    }

    Process *Ptemp = Phead, *ProcessNode = NULL;
    while (Ptemp != NULL) {
        if (Ptemp->id == P) {
            ProcessNode = Ptemp;
            break;
        }
        Ptemp = Ptemp->next_process;
    }

    Resource *Rtemp = Rhead, *ResourceNode = NULL;
    while (Rtemp != NULL) {
        if (Rtemp->id == R) {
            ResourceNode = Rtemp;
            break;
        }
        Rtemp = Rtemp->next_resource;
    }

    if (ProcessNode == NULL) {
        printf("Process with ID %d not found.\n", P);
        return;
    }

    if (ResourceNode == NULL) {
        printf("Resource with ID %d not found.\n", R);
        return;
    }

    if (ProcessNode->requested_resource != NULL) {
        printf("Process %d already has a resource request.\n", P);
        return;
    }

    ProcessNode->requested_resource = ResourceNode;    
    printf("\nRequest: Process P%d --> Resource R%d\n", P, R);

    // Check for cycles after making the request
    if (DetectCycle()) {
        printf("Cycle detected in the resource allocation graph.\n");
    } else {
        printf("No cycles detected in the resource allocation graph.\n");
    }
}

// Function to clean up memory allocated for processes and resources
void Cleanup() {
    // Free memory allocated for processes and resources
    Process *ptemp = Phead;
    while (ptemp != NULL) {
        Process *node = ptemp;
        ptemp = ptemp->next_process;
        free(node);
    }

    Resource *Rtemp = Rhead;
    while (Rtemp != NULL) {
        Resource *node = Rtemp;
        Rtemp = Rtemp->next_resource;
        free(node);
    }
}

