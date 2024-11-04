//Objective: To find the Armstrong Number from 1 to n
//Input parameters: the value of n
//Output parameters: the armstrong numbers from 1 to n
#include<stdio.h>
#include<math.h>

//Function to calculate power of a number
int power(int number,int exponent){
    int prod=1;
    for(int i=0;i<exponent;i++){
        prod = prod*number;
    }
    return prod;
}


int main(){
    int n,num,sum,counter;
    //Taking user input for the n
    printf("Enter the value of n:");
    scanf("%d",&n);
    //Printing all the armstrong numbers
    printf("The Armstrong numbers are:\n");
    for(int i=1;i<=n;i++){
        num = i;
        sum = 0;
        counter=0;
        //Calculating the number of digits
        while(num>0){
            counter++;
            num = num/10;
        }
        num = i;
        //Evaluating whether the number in range is Armstrong or not
        if(counter>3){
            while(num>0){
                int digit = num%10;
                sum = sum+power(digit,counter);
                num=num/10;
            }
        }
        else{
            while(num>0){
                int digit = num%10;
                sum = sum+power(digit,3);
                num=num/10;
            }
        }
        //Armstrong number is number if the sum of the length number(cube i.e 3 in case of 132) of the digit
        //is equal to number
        if(sum==i){
            printf("%d ",i);
        }
    }
    return 0;
}
