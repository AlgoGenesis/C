#include <stdio.h>  
#include <conio.h>  
  
int main ()  
{  
    // declare integer variables  
    int n, sum_of_digits;  
   
    scanf (" %d", &n); // get the number  
    
    while (n > 0 || sum_of_digits > 9) 
       { 
       sum_of_digits=0;
           if (n == 0) 
           { 
               n = sum_of_digits; 
               sum_of_digits = 0; 
           } 
           sum_of_digits += n % 10; 
           n /= 10; 
       }
    
    if ( sum_of_digits == 1)  
    {  
        printf ("Magic Number");  
    }  
    else  
    {  
        printf ("Not Magic Number");  
    }  
    return 0;  
      
}  
