### Maximum-Minumum algorithm Using Divide and Conquer Approach                                  
This C program implements a divide-and-conquer algorithm to efficiently find the minimum and maximum values in an array. The algorithm recursively divides the array into smaller subarrays, computes the minimum and maximum for each subarray, and combines the results to find the overall minimum and maximum.

---
### Features
**Input:**               
The program prompts the user to enter the size of the array and its elements.

**Algorithm:**          
It uses a recursive approach to divide the array into halves, finding the min and max values in each half, and combines them to get the final results.

**Output:**        
The program prints the maximum and minimum values found in the array.

---
### Code Structure

**Struct Definition:**
struct data: A structure to hold the minimum and maximum values.

**Function:**
DAC_Min_Max(int a[], int i, int j): This function implements the divide-and-conquer algorithm. It takes an array and the indices of the subarray to be considered.

**Base Cases:**
If the subarray contains only one element, it sets both min and max to that element.
If it contains two elements, it compares them to set min and max accordingly.

**Recursive Case:**
The array is divided into two halves, and the function is called recursively for each half. The results are then combined to determine the overall min and max.

**Main Function:**
The entry point of the program where the user inputs the size and elements of the array. It calls the DAC_Min_Max function and outputs the results.

---
### Sample Input and Output:
Enter the size of the array: 5                     
Enter the elements: 3 1 4 1 5                         
The maximum value is: 5                        
The minimum value is: 1

