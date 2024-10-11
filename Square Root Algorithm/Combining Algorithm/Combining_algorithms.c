#include <stdio.h>
#include <math.h>

// implementing combing algorithms on finding the square root of a number 

// in this Approach we basically have  two approaches 

// 1. Binary Search Phase.

// 2. Newton's Method Phase:

double combined_sqrt(double x, double precision){
    if(x<0){
        printf("No square root of negative numbers\n");
    }

    // we can implement this using binary search 

    double l;
    double h;

    if(x>=1){
        l=0;
        h=x;
    }else{
        l=x;
        h=1;
    }

    double mid;
    while((h-l)>precision){
        mid=(l+h)/2;
        if(mid*mid>x){
            h=mid;
        }else{
            l=mid;
        }
    }
    // THis is another method known as Newton's Method phase.

    double guess=(l+h)/2;
    while(fabs(guess*guess-x)>precision){
        guess=(guess+(x/guess))/2;
    }
    return guess;
}

int main(){
    double num;
    double resultt;

    double precision=0.0001;

    printf("please enter the number to find the square root :");
    scanf("%lf",&num);
    resultt=combined_sqrt(num,precision);
    if(resultt!=-1){
        printf("The square root of %lf is %lf\n",num,resultt);
    }
    return 0;
}