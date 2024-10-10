#include<stdio.h>

//preemptive SJF
int main(){
    int at[100], bt[100], p[100],wt[100], smallest_burst, smallest_job, n, i, j;
    int temp[100], sum_burst = 0;
    float sum_wait = 0;
    printf("Enter the number of processes ");
    scanf("%d", &n);
    printf("P AT BT\n");
    for(i = 0 ; i < n ; i++){
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
        temp[i] = bt[i];
        sum_burst = sum_burst + bt[i];
    }
    int time = 0;
    printf("p\tAT\tBT\tWT\n");
    while(time < sum_burst){
        smallest_burst = -1;
        smallest_job = -1;
        for(i = 0 ; i < n ; i++){
            if(at[i] <= time && temp[i] > 0){
                if(smallest_job == -1 || temp[i] < smallest_burst){
                    smallest_job = i;
                    smallest_burst = temp[i];
                }
            }

        }
        if(smallest_job == -1) break;
        temp[smallest_job]--;
        time++;
        if(temp[smallest_job] == 0){
            wt[smallest_job] = time -at[smallest_job] -bt[smallest_job];
            printf("%d\t%d\t%d\t%d\n", p[smallest_job], at[smallest_job], bt[smallest_job], wt[smallest_job]);
            sum_wait += wt[smallest_job];

        }
    }
    float avg = sum_wait / n;
    printf("The average is %f", avg);
}