#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000
#define MAX_Q 100000

// Structure for each query
typedef struct {
    int L, R, idx;
} Query;

int n, q;
int arr[MAX_N];
Query queries[MAX_Q];
int answer[MAX_Q];
int current_answer = 0;
int freq[1000001];

// Comparator function to sort queries by Mo's ordering
int compare(const void *a, const void *b) {
    Query *q1 = (Query *)a;
    Query *q2 = (Query *)b;
    int block1 = q1->L / (int)sqrt(n);
    int block2 = q2->L / (int)sqrt(n);
    if (block1 != block2) {
        return block1 - block2;
    }
    return (block1 & 1) ? (q1->R - q2->R) : (q2->R - q1->R);
}

// Function to add element at index pos
void add(int pos) {
    current_answer += arr[pos];
}

// Function to remove element at index pos
void remove(int pos) {
    current_answer -= arr[pos];
}

// Mo's Algorithm to answer all queries
void mo_algorithm() {
    int currentL = 0, currentR = -1;
    for (int i = 0; i < q; i++) {
        int L = queries[i].L;
        int R = queries[i].R;

        // Adjust the left boundary
        while (currentL < L) {
            remove(currentL);
            currentL++;
        }
        while (currentL > L) {
            currentL--;
            add(currentL);
        }

        // Adjust the right boundary
        while (currentR < R) {
            currentR++;
            add(currentR);
        }
        while (currentR > R) {
            remove(currentR);
            currentR--;
        }

        // Store the answer for this query
        answer[queries[i].idx] = current_answer;
    }
}

int main() {
    // Input array size and elements
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input number of queries and their ranges
    printf("Enter the number of queries: ");
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].L--;  // Convert to zero-based indexing
        queries[i].R--;
        queries[i].idx = i;
    }

    // Sort queries according to Mo's ordering
    qsort(queries, q, sizeof(Query), compare);

    // Execute Mo's Algorithm
    mo_algorithm();

    // Output the answers for each query
    printf("Query Results:\n");
    for (int i = 0; i < q; i++) {
        printf("Query %d: %d\n", i + 1, answer[i]);
    }

    return 0;
}
