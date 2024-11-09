#include <stdio.h>

// Recursive function to solve the Josephus Problem
int josephus(int n, int k) {
    // Base case: if there's only one person, they are the survivor
    if (n == 1)
        return 0;
    // Recurrence relation to find the safe position
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;

    // Get the number of people and the step count from the user
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    // Find the safe position (adjusted by +1 to match 1-based indexing)
    int position = josephus(n, k) + 1;
    printf("The safe position is %d\n", position);
    
    return 0;
}
