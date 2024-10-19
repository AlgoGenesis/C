#include <stdio.h>  
#include <stdlib.h>  
  
int* booth_multiplication(int* m, int* q, int n) {  
    int* product = (int*) malloc(2 * n * sizeof(int));   
    for (int i = 0; i < 2 * n; i++) {  
        product[i] = 0;   
    }  
  
    int* a = (int*) malloc(n * sizeof(int));   
    for (int i = 0; i < n; i++) {  
        a[i] = 0;   
    }  
  
    int q0 = 0;   
    for (int i = 0; i < n; i++) {  
        if (q0 == 0 && q[n-1] == 1) {   
            for (int j = 0; j < n; j++) {  
                if (a[j] == 0) {   
                    a[j] = m[j];  
                }  
                else {   
                    a[j] = ~m[j] + 1;  
                }  
            }  
        }  
        else if (q0 == 1 && q[n-1] == 0) { // Case 2: q0 = 1, q[n-1] = 0  
            for (int j = 0; j < n; j++) {  
                if (a[j] == 0) {   
                    a[j] = ~m[j] + 1;  
                }  
                else {   
                    a[j] = m[j];  
                }  
            }  
        }  
        q0 = q[n-1];  
        for (int j = n-1; j > 0; j--) {  
            q[j] = q[j-1];  
            a[j] = a[j-1];  
        }  
        q[0] = a[0];  
    }  
  
    for (int i = 0; i < n; i++) {  
        product[i] = a[i];  
    }  
  
    free(a);   
    return product;  
}  