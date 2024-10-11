#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 100000  // Maximum number of elements in the array
#define MAXQ 100000  // Maximum number of queries


// note that here both the elements in the array and in the no of queries must be eqal.
int arr[MAXN];       // Array of elements
int freq[MAXN];      // Frequency of each element in the current range
int result[MAXQ];    // Results for each query
int current_answer;  // Current number of distinct elements


typedef struct {
    int L, R, idx;                                       
} Query;                              // we are defining a strcuture which would info about the Queries 

// sort queries 
int mo_compare(const void* a, const void* b) {
    Query* query1 = (Query*)a;
    Query* query2 = (Query*)b;
    
    int blockSize = (int)sqrt(MAXN);
    int block1 = query1->L / blockSize;
    int block2 = query2->L / blockSize;

    if (block1 != block2)
        return block1 - block2;
    
    return query1->R - query2->R;
}


void add(int x) {
    freq[x]++;
    if (freq[x] == 1) {
        current_answer++;  // if (found)-> distinct element found
    }
}


void remove_element(int x) {
    if (freq[x] > 0) {  // Ensure the frequency is positive before removing
        if (freq[x] == 1) {
            current_answer--;  // Element is no longer in the range
        }
        freq[x]--;
    }
}



int main() {
    int n, q;  // n for elements and q for the queries.
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter number of queries: ");
    scanf("%d", &q);
    
    Query queries[MAXQ];  
    
    for (int i = 0; i < q; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        queries[i].L = L - 1;  // Convert to 0-based indexing
        queries[i].R = R - 1;
        queries[i].idx = i;    // Store query index
    }
    
    // Sort queries using Mo's order
    qsort(queries, q, sizeof(Query), mo_compare);
    
    // Initialize the current range to empty
    int currentL = 0, currentR = -1;
    current_answer = 0;
    
    // Process each query
    for (int i = 0; i < q; i++) {
        int L = queries[i].L;
        int R = queries[i].R;
        
        // Extend the range to the right
        while (currentR < R) {
            currentR++;
            add(arr[currentR]);
        }
        
        // Shrink the range from the right
        while (currentR > R) {
            remove_element(arr[currentR]);
            currentR--;
        }
        
        // Extend the range to the left
        while (currentL > L) {
            currentL--;
            add(arr[currentL]);
        }
        
        // Shrink the range from the left
        while (currentL < L) {
            remove_element(arr[currentL]);
            currentL++;
        }
        
        // Store the result for this query
        result[queries[i].idx] = current_answer;
    }
    
    // Output the results for all queries
    for (int i = 0; i < q; i++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}
