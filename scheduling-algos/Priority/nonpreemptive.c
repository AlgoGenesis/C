#include<stdio.h>
//non preemptive 
void sort(int n, int at[], int bt[], int p[]){
    int i, j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(p[j] > p[j + 1]){
                int temp = p[j]; 
                p[j] = p[j + 1];
                p[j + 1] = temp;
                temp = at[j]; 
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j]; 
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n, i, j, at[100], bt[100], p[100];
    int wt[100], st[100], ft[100];
    printf("Enter n:");
    scanf("%d", &n);
    printf("AT BT P\n");
    for(i = 0 ; i < n ; i++){
        scanf("%d%d%d", &at[i], &bt[i], &p[i]);
    }
    sort(n, at, bt, p);
    float sum_wait = 0;
    for(i = 0 ; i < n ; i++){
    if(i == 0){
        st[i] = at[i];
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
    }
    else{
        st[i] = ft[i - 1];
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
    }}
    printf("p AT BT WT\n");
    for(i = 0 ; i < n ; i++){
        printf("%d %d %d %d %d\n", p[i], at[i], bt[i], wt[i]);
        sum_wait += wt[i];
    }
    float avg = sum_wait / n;
    printf("Average Value : %f\n", avg);
}