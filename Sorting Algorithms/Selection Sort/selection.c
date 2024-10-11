#include<stdio.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[],int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j= i+1; j<n; j++){
            if(a[j] < a[minIdx]){
                minIdx = j;
            }
        }
        if(minIdx != i){
            swap(&a[minIdx],&a[i]);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(int i=0; i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}