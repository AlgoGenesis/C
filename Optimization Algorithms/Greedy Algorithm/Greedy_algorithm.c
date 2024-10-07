#include<stdio.h>

int greedy(int denomination[], int target){
    int number=0;
    for(int i=0; target>0;i++){
        number += target/denomination[i]; //number of denominations required for denomination[i] element
        target -= target/denomination[i]*denomination[i]; //amount of value covered by the above denomination
    }
    return number;
}

int main(){
    int denomination[]={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; //denominations of INR
    int target=0; //Traget required for which denominations are to be found
    printf("Enter the amount for which denomination is required: ");
    scanf("%d", &target);
    int answer=0;
    answer = greedy(denomination, target);
    printf("The number of denominations required are: %d", answer); 

    return 0;
}