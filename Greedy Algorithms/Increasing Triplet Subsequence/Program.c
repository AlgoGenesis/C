#include <stdio.h>
#include <stdbool.h>

// Function to check for an increasing triplet subsequence in the given array
bool increasingTriplet(int* nums, int n) 
{
    // If the length of the array is less than 3, an increasing triplet cannot exist
    if (n < 3) return false;

    // Initialize the prefix minimum with the first element
    int prefixMin = nums[0];
    // Declare an array to store the maximum elements from the right side
    int suffixMax[n];

    // Set the last element of suffixMax to the last element of the input array
    suffixMax[n - 1] = nums[n - 1];

    // Calculate the suffixMax array by iterating from the end of the array
    for (int i = n - 2; i >= 0; i--) 
    {
        // Store the maximum value between the current element and the next suffixMax
        suffixMax[i] = (suffixMax[i + 1] > nums[i]) ? suffixMax[i + 1] : nums[i];
    }

    // Iterate from the second element to the second-to-last element
    for (int i = 1; i < n - 1; i++) 
    {
        // Check if there exists a prefix min less than the current element and a suffix max greater than the current element
        if (prefixMin < nums[i] && suffixMax[i] > nums[i]) 
        {
            return true; // Triplet found
        }
        // Update the prefixMin to the minimum of itself and the current element
        prefixMin = (prefixMin < nums[i]) ? prefixMin : nums[i];
    }

    // Return false if no increasing triplet subsequence is found
    return false;
}

// Main function to test the increasingTriplet function
int main() 
{
    int n;

    // Prompt the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Check for valid array size
    if (n < 3) {
        printf("Array must have at least 3 elements to find an increasing triplet.\n");
        return 1; // Exit with error code
    }

    int nums[n];

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array (space-separated):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &nums[i]);
    }

    // Call the function to check for an increasing triplet subsequence
    bool result = increasingTriplet(nums, n);

    if (result) 
    {
        printf("An increasing triplet subsequence exists in the array.\n");
    } 
    else 
    {
        printf("No increasing triplet subsequence exists in the array.\n");
    }

    return 0; 
}
