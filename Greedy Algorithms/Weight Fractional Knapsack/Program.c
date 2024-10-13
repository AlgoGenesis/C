#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
    double weight_value_ratio;
};

// Function to compare items based on the w/v ratio in descending order
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item1->weight_value_ratio < item2->weight_value_ratio) return 1;
    if (item1->weight_value_ratio > item2->weight_value_ratio) return -1;
    return 0;
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items by descending weight/value ratio
    qsort(items, n, sizeof(struct Item), compare);

    double total_protein = 0.0;
    int i;
    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // If the item can fit fully in the bag
            total_protein += items[i].weight;
            capacity -= items[i].weight;
        } else {
            // If the item can't fit fully, take the fraction of it
            total_protein += items[i].weight * ((double)capacity / items[i].weight);
            capacity = 0; // Bag is full
        }
    }

    return total_protein;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].weight_value_ratio = (double)items[i].weight / items[i].value;
    }

    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    double max_protein = fractionalKnapsack(items, n, capacity);
    printf("Maximum protein that can be achieved = %.2f\n", max_protein);

    return 0;
}
