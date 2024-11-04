# Valid Palindrome 

# Problem Statement
Check if a sentence is a palindrome or not. You can ignore white spaces and other characters to consider sentences as a palindrome.

## Solution Approach
Input Handling: The program uses fgets to read a string input from the user. This allows the input to include spaces.
Palindrome Check: The isPalindrome function checks whether the string is a palindrome by:
Ignoring non-alphanumeric characters.
Comparing characters from both ends of the string, moving towards the center.
Converting characters to lowercase to ensure the comparison is case-insensitive.
Output: After checking, it prints whether the string is a palindrome or not.


## Example
Input : str = "Too hot to hoot."
Output : Sentence is palindrome

## Time And Space Complexity
Time Complexity: O(n), where n is the length of the string, because we may have to traverse the string to filter and check for the palindrome.
Space Complexity: O(n) in the worst case if we create a new filtered string.
