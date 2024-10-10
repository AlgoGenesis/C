//First Come First Serve

#include<stdio.h>

void sort(int at[], int bt[], int p[], int n){
    int temp, i;
    for(i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(at[j] > at[j + 1]){
                temp = at[j];
                at[j + 1] = at[j];
                at[j] = temp;
                temp = bt[j];
                bt[j + 1] = bt[j];
                bt[j] = temp;
                temp = p[j];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the numebr of process :");
    scanf("%d", &n);
    int at[100], bt[100], wt[100], p[100];
    printf("Enter AT, BT, WT");
    for (int i = 0 ; i < n ; i++){
        scanf("%d%d", &at[i], &bt[i]);
        p[i] = i + 1;
    }
    sort(at, bt, p, n);
    int time = 0;
    wt[0] = 0;
    float sum =  0; 
  //  sort(at, bt, p, n);
    for(int i = 0 ; i < n ; i++){
        wt[i] = time - at[i];
        time = time + bt[i];
    }
    printf("P\tAT\tBT\tWT\n");
    for(int i = 0 ;  i< n ; i++){
        printf("%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i]);
    sum = sum + wt[i];
    }
    float avg = sum / n;
    printf("The required average : %f", avg);
}