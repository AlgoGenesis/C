# Maximum Products of two elements in an array
## How Does It Work?
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 
## Example:
### Example 1:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)(nums[2]-1) = (4-1)(5-1) = 3*4 = 12. 
### Example 2:
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
# Approach :
1. Sort the Array : Begin by sorting the array nums in ascending order. This will arrange the numbers such that the largest numbers are at the end of the array.
2. Identify the Two Largest Numbers : After sorting, the two largest numbers in the array will be at the last two indices. Specifically, the largest number will be at nums[nums.size() - 1] and the second largest will be at nums[nums.size() - 2].
3. Calculate the Product : Subtract 1 from each of these two largest numbers and then calculate their product.
# Complexity :
Time complexity : O(n*log(n))
The time complexity of this solution is O(n log n) due to the sorting operation, where n is the number of elements in the input vector.
Space complexity : O(1)
