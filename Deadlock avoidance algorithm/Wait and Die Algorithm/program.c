#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TRANSACTIONS 5  // Maximum number of transactions
#define MAX_RESOURCES 3     // Maximum number of resources

typedef struct {
    int id;         // Transaction ID
    int timestamp;  // Transaction's timestamp (used for age comparison)
} Transaction;

typedef struct {
    bool is_locked;         // Resource lock status
    Transaction *locked_by; // Pointer to the transaction that holds the lock
} Resource;

Transaction transactions[MAX_TRANSACTIONS];
Resource resources[MAX_RESOURCES];

// Initialize transactions with unique IDs and timestamps
void initialize_transactions() {
    srand(time(NULL));
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        transactions[i].id = i + 1;
        transactions[i].timestamp = rand() % 100; // Random timestamp for demonstration
    }
}

// Initialize resources as unlocked
void initialize_resources() {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources[i].is_locked = false;
        resources[i].locked_by = NULL;
    }
}

// Function to simulate requesting a resource
void request_resource(int trans_id, int res_id) {
    Transaction *transaction = &transactions[trans_id];
    Resource *resource = &resources[res_id];

    printf("Transaction %d (Timestamp %d) requesting Resource %d\n", 
            transaction->id, transaction->timestamp, res_id);

    // If resource is not locked, grant it to the transaction
    if (!resource->is_locked) {
        resource->is_locked = true;
        resource->locked_by = transaction;
        printf("Resource %d granted to Transaction %d\n", res_id, transaction->id);
    } else {
        // If resource is locked, apply Wait-Die scheme
        Transaction *current_holder = resource->locked_by;
        
        if (transaction->timestamp < current_holder->timestamp) {
            // If transaction is older, it waits
            printf("Transaction %d waits for Resource %d held by Transaction %d\n", 
                    transaction->id, res_id, current_holder->id);
        } else {
            // If transaction is younger, it dies (abort)
            printf("Transaction %d aborted (dies) as it is younger than Transaction %d holding Resource %d\n", 
                    transaction->id, current_holder->id, res_id);
        }
    }
}

// Function to simulate transactions requesting resources
void simulate_requests() {
    request_resource(0, 1); // Transaction 1 requests Resource 2
    request_resource(1, 1); // Transaction 2 requests Resource 2 (Wait or Die based on timestamps)
    request_resource(2, 0); // Transaction 3 requests Resource 1
    request_resource(3, 1); // Transaction 4 requests Resource 2 (Wait or Die based on timestamps)
}

int main() {
    initialize_transactions();
    initialize_resources();

    printf("Simulating Wait-Die Deadlock Avoidance...\n");
    simulate_requests();

    return 0;
}
