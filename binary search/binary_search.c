#include <stdio.h>
#include <conio.h>

int main()
{
    
    int a,i,target;
    printf("How many elements you want to add:");
    scanf("%d",&a);
    int arr[a];
    for(i=0;i<a;i++){
        printf("Enter your %d element:\n",i + 1);
        scanf("%d",&arr[i]);
    }
    printf("which no. you want find:");
    scanf("%d",&target);
    int begin = 0;
    int end = a;
    int mid_pos,mid_val;
    
    while(begin < end){
        mid_pos = (begin+end)/2;
        mid_val = arr[mid_pos];
        if(mid_val < target){
            begin = mid_pos + 1;
        }
        else if(mid_val > target){
            end = mid_pos - 1;
        }
        else if(mid_val == target){
            printf("we have found your value at %d",mid_pos);
            break;
        }
        
        
    }
    if(mid_val != target){
        printf("sorry we do not find your value in this list");
    }

    return 0;
}