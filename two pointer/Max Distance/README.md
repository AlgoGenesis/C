## Problem Description   MAX DISTANCE

### Problem Statement:
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Problem Constraints
1 <= |A| <= 106
-109 <= Ai <= 109


Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).

 ### Algorithm / Intuition

  ### (Efficient): 
  - To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j. For an element arr[i], we do not need to consider arr[i] for left index if there is an element smaller than arr[i] on left side of arr[i]. Similarly, if there is a greater element on right side of arr[j] then we do not need to consider this j for the right index. So we construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left side of arr[i] including arr[i], and RMax[j] holds the greatest element on right side of arr[j] including arr[j]. After constructing these two auxiliary arrays, we traverse both of these arrays from left to right. While traversing LMin[] and RMax[] if we see that LMin[i] is greater than RMax[j], then we must move ahead in LMin[] (or do i++) because all elements on left of LMin[i] are greater than or equal to LMin[i]. Otherwise, we must move ahead in RMax[j] to look for a greater j – i value.

### Complexity
Time Complexity: O(n) 
Auxiliary Space: O(n) 