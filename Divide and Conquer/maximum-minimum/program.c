#include<stdio.h>
// Structure to hold both minimum and maximum values
struct data{
	int min; 
	int max;
};
struct data DAC_Min_Max(int a[],int i,int j)     // Function to find minimum and maximum using Divide and Conquer approach
{
	int mid;
	struct data mm,mm1,mm2; 	// Declare variables to hold min/max values for subarrays
	// Case 1: If there is only one element in the array
	if(i==j){			
		mm.max=a[i];
		mm.min=a[i];
		return mm;
	}
	// Case 2: If there are only two elements
	else if(i==j-1){	
		if(a[i]<a[j]){	// Compare the two elements and set min/max accordingly
		mm.max=a[j];
		mm.min=a[i];
		}
		else{
		mm.max=a[i];
		mm.min=a[j];
		}
	return mm;	// Return the result
	}
	 // Case 3: More than two elements, so divide the array
	mid=(i+j)/2;
	mm1=DAC_Min_Max(a,i,mid);	// Recursively find min/max in the left subarray
	mm2=DAC_Min_Max(a,mid+1,j);	// Recursively find min/max in the left subarray
	 // Compare the results from left and right subarrays to find the overall min and max
	if(mm1.max<mm2.max)
		mm.max=mm2.max;
	else
		mm.max=mm1.max;
	if(mm1.min<mm2.min)
		mm.min=mm1.min;
	else
		mm.min=mm2.min;
	return mm;	// Return the final result for the current subarray
}
int main(){
    int n, a[50], i;
    struct data MinMax;	// Declare a structure to hold the final min and max values
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    MinMax = DAC_Min_Max(a, 0, n-1); 	
    // Call the function to find min and max values using Divide and Conquer
    printf("The maximum value is: %d\n", MinMax.max);
    printf("The minimum value is: %d", MinMax.min);
    return 0;
}	
