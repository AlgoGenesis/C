#include<stdio.h>
//preemptive
int main(){
    int n, at[100], bt[100], p[100], pn[100], i, j, k, done, min_pt, min_i, temp[100], wt[100];
    printf("Enter number of processes :");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%d%d%d", &at[i], &bt[i], &p[i]);
        pn[i] = i+1;
        temp[i] = bt[i];
    }
    done = 0;
    int time = 0;
    while(done < n){
        min_pt = 10000;
        min_i = -1;
        for(i = 0 ; i < n ; i++){
            if(at[i] <= time && temp[i] > 0 && min_pt > p[i]){
                min_pt = p[i];
                min_i = i;
            }
        }
        if(min_i == -1){
            time++;
            continue;
        }
        time++;
        temp[min_i]--;
        if(temp[min_pt] == 0){
            wt[min_i] = time -at[min_i] - bt[min_i];
            printf("%d %d %d %d %d \n", pn[min_i], at[min_i], bt[min_i], wt[min_i]);
            done++;
        }

    }
    float sum = 0;
    for(i = 0 ; i < n ; i++){
        sum += wt[i];
    }
    printf("Avg : %f", sum / n);
}