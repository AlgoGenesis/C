#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100000
#define MAXQ 100000

typedef struct {
    int l, r, idx;
} Query;

int arr[MAXN];
Query queries[MAXQ];
long long answers[MAXQ];

// Comparison function for sorting queries
int compare(const void *a, const void *b) {
    Query *q1 = (Query *)a;
    Query *q2 = (Query *)b;
    int block_size = sqrt(MAXN);
    if (q1->l / block_size != q2->l / block_size)
        return (q1->l / block_size) - (q2->l / block_size);
    return q1->r - q2->r;
}

// Function to add an element to the current range
void add(int idx, long long *current_sum) {
    *current_sum += arr[idx];
}

// Function to remove an element from the current range
void remove(int idx, long long *current_sum) {
    *current_sum -= arr[idx];
}

// Main function to process the queries
void processQueries(int n, int q) {
    long long current_sum = 0;
    int current_l = 0, current_r = -1;

    for (int i = 0; i < q; i++) {
        int l = queries[i].l;
        int r = queries[i].r;

        // Adjust the current range to the desired range [l, r]
        while (current_r < r) {
            current_r++;
            add(current_r, &current_sum);
        }
        while (current_r > r) {
            remove(current_r, &current_sum);
            current_r--;
        }
        while (current_l < l) {
            remove(current_l, &current_sum);
            current_l++;
        }
        while (current_l > l) {
            current_l--;
            add(current_l, &current_sum);
        }

        // Store the answer for the current query
        answers[queries[i].idx] = current_sum;
    }
}

int main() {
    int n, q;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the number of queries
    printf("Enter the number of queries: ");
    scanf("%d", &q);
    printf("Enter the queries (l r):\n");
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &queries[i].l, &queries[i].r);
        queries[i].idx = i; // Store the original index
    }

    // Sort the queries
    qsort(queries, q, sizeof(Query), compare);

    // Process the queries
    processQueries(n, q);

    // Output the results
    printf("Results of the queries:\n");
    for (int i = 0; i < q; i++) {
        printf("Query %d: Sum from %d to %d is %lld\n", i + 1, queries[i].l, queries[i].r, answers[i]);
    }

    return 0;
}