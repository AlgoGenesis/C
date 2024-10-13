#include <stdio.h>
#include <stdlib.h>
typedef struct Jobs {
    char id;     
    int dead;    
    int profit;  
} Jobs;
int compare(const void* a, const void* b) {
    Jobs* temp1 = (Jobs*)a;
    Jobs* temp2 = (Jobs*)b;
    return (temp2->profit - temp1->profit);
}
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Jobs arr[n];
    printf("Enter job details (id, deadline, profit) for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &arr[i].id, &arr[i].dead, &arr[i].profit);
    }
    printf("Following is the maximum profit sequence of Jobs: \n");
    qsort(arr, n, sizeof(Jobs), compare);
    int result[n]; 
    int slot[n];    
    for (int i = 0; i < n; i++)
        slot[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i] == 1)
            printf("%c ", arr[result[i]].id);
    return 0;
}
