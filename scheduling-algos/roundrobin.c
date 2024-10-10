#include<stdio.h>

int main() {
    int at[100], bt[100], wt[100], n, i, t, temp[100], timequantum, sum = 0;
    float sum_wait = 0, avg_wait;

    printf("Enter the number of processes :");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter arrival time of process %d :", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d :", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter time quantum :");
    scanf("%d", &timequantum);

    t = n;
    i = 0;

    while(t > 0) {
        if(temp[i] > 0) {
            if(temp[i] <= timequantum) {
                sum += temp[i];
                wt[i] = sum - at[i] - bt[i];
                temp[i] = 0;
                t--;
            }
            else {
                sum += timequantum;
                temp[i] -= timequantum;
            }
        }

        i = (i + 1) % n;

        // If the process has finished execution, move to the next process
        if(temp[i] == 0)
            i = (i + 1) % n;
    }

    printf("P[]\tAT\tBT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i]);
        sum_wait += wt[i];
    }

    avg_wait = sum_wait / n;
    printf("\nThe average waiting time : %f\n", avg_wait);

    return 0;
}