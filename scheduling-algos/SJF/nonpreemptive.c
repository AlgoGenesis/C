#include<stdio.h>

//non preemptive SJF
int main(){
    int at[100], bt[100], wt[100], p[100], smallest, sum_burst = 0;
    int n, i, j, k;
    float sum_wait;
    printf("Enter number :");
    scanf("%d", &n);
    printf("Enter P, AT, BT\n");
    for(i = 0 ; i < n ; i++){
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
        sum_burst = sum_burst + bt[i];
    }
    int time = 0;
    while(time < sum_burst){
        smallest = 99;
        for(i = 0 ; i < n ; i++){
            if(at[i] <= time && bt[i] > 0 && bt[smallest] > bt[i]){
                smallest = i;
            }
        }
        wt[smallest] = time - at[smallest];
        printf("%d\t%d\t%d\t%d\n", p[smallest], at[smallest], bt[smallest], wt[smallest]);
        sum_wait = sum_wait + wt[smallest];
        time = time + bt[smallest];
        bt[smallest] = 0;
    }
    float avg = sum_wait / n;
    printf("The average waiting time : %f\n", avg);
}