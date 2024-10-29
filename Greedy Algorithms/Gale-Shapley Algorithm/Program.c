#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int n; // Number of men/women
int men[MAX], women[MAX]; // Array to store the final matches
int preferenceMen[MAX][MAX], preferenceWomen[MAX][MAX]; // Preference lists
bool freeMen[MAX]; // Status of men (free or engaged)
int nextProposal[MAX]; // Next proposal index for each man

// Function to check if woman prefers man1 over man2
bool prefers(int woman, int man1, int man2) {
    for (int i = 0; i < n; i++) {
        if (preferenceWomen[woman][i] == man1) return true;
        if (preferenceWomen[woman][i] == man2) return false;
    }
    return false; // Should not reach here
}

// Function to implement the Gale-Shapley algorithm
void stableMarriage() {
    for (int i = 0; i < n; i++) {
        freeMen[i] = true; // All men are initially free
        nextProposal[i] = 0; // Initialize next proposal index
    }

    int freeCount = n; // Number of free men

    while (freeCount > 0) {
        int m;
        for (m = 0; m < n; m++) {
            if (freeMen[m]) break; // Find a free man
        }

        int w = preferenceMen[m][nextProposal[m]]; // Get the next woman to propose to
        nextProposal[m]++; // Move to the next woman for next proposal

        if (women[w] == -1) { // If woman is free
            women[w] = m; // Engage man and woman
            men[m] = w; // Update man's engagement
            freeMen[m] = false; // Mark man as not free
            freeCount--; // Decrease free count
        } else { // If woman is already engaged
            int m1 = women[w]; // Current engagement
            if (prefers(w, m, m1)) { // If woman prefers new man
                women[w] = m; // Engage new man
                men[m] = w; // Update man's engagement
                freeMen[m] = false; // Mark new man as not free
                freeMen[m1] = true; // Old man becomes free
            }
        }
    }
}

int main() {
    printf("Enter the number of men/women: ");
    scanf("%d", &n);

    printf("Enter preferences of men (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("Man %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &preferenceMen[i][j]);
        }
    }

    printf("Enter preferences of women (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("Woman %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &preferenceWomen[i][j]);
        }
    }

    // Initialize women to -1 (indicating free)
    for (int i = 0; i < n; i++) {
        women[i] = -1;
    }

    stableMarriage();

    printf("\nEngagements:\n");
    for (int i = 0; i < n; i++) {
        printf("Man %d is engaged to Woman %d\n", i, men[i]);
    }

    return 0;
}
