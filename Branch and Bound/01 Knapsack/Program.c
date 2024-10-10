#include <stdio.h>
#include <stdlib.h>

// Structure to represent an Item with weight and value
struct Item {
    float weight;
    int value;
};

// Structure to represent a node in the decision tree
struct Node {
    // level: level of node in the decision tree
    // profit: profit from root to this node
    // bound: upper bound of maximum profit in the subtree of this node
    int level, profit, bound;
    float weight;
};

// Comparison function to sort items based on value-to-weight ratio
int cmp(const void *a, const void *b) {
    double r1 = ((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = ((struct Item *)b)->value / ((struct Item *)b)->weight;
    return r1 > r2 ? -1 : 1; // Sort in descending order of value/weight
}

// Function to calculate the upper bound of profit for a given node
int bound(struct Node u, int n, int W, struct Item arr[]) {
    // If the weight exceeds the capacity of the knapsack, return 0
    if (u.weight >= W)
        return 0;

    // Initialize bound with current profit
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    // Traverse the remaining items and add them to the total weight and profit
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    // If there are remaining items, include the next item partially for the upper bound
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Branch and Bound function to solve the Knapsack problem
int knapsack(int W, struct Item arr[], int n) {
    // Sort items based on value-to-weight ratio
    qsort(arr, n, sizeof(struct Item), cmp);

    // Initialize a queue for the decision tree traversal
    struct Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;

    // Maximum profit
    int maxProfit = 0;

    // Array-based queue (to replace std::queue in C++)
    struct Node queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = u;

    // Process nodes one by one in the decision tree
    while (front < rear) {
        // Dequeue a node
        u = queue[front++];

        // If it's the root node, start from level 0
        if (u.level == -1)
            v.level = 0;
        else if (u.level == n-1) // If it is the last node, skip
            continue;
        else
            v.level = u.level + 1;

        // Taking the current item
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        // If weight is within the capacity and profit is greater than current maxProfit
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        // Calculate the upper bound of profit
        v.bound = bound(v, n, W, arr);

        // If bound is greater than maxProfit, enqueue the node for further exploration
        if (v.bound > maxProfit)
            queue[rear++] = v;

        // Without taking the current item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);

        // Enqueue this node if bound is greater than maxProfit
        if (v.bound > maxProfit)
            queue[rear++] = v;
    }

    return maxProfit;
}

// Main function to test the knapsack solver
int main() {
    int n, W;

    // Input number of items and capacity of knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    // Input each item's weight and value
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%f %d", &arr[i].weight, &arr[i].value);
    }

    // Call the knapsack solver and print the maximum profit
    printf("Maximum possible profit = %d\n", knapsack(W, arr, n));

    return 0;
}
