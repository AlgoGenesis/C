## Smallest Window Covering All Characters

### Problem Statement:

- Given a string s and a string t, your task is to find the smallest substring in s that contains all the characters of t, including duplicates. If there is no such substring, return an empty string.
If there are multiple substrings with the same length, return the one that appears first.

Example:

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"

### Algorithm / Intuition:

- Sliding Window Technique:
    We can solve this problem using the sliding window approach where we maintain two pointers, left and right, that define the current window of the substring in s.

- Character Frequency Count:
    We need to keep track of how many characters from t are still missing in the current window. This can be done using a frequency map or counter for the characters in t.
    A second map is used to store the frequency of characters in the current window of s.

- Expand and Contract the Window:
    Expand the window by moving the right pointer to include more characters from s until the window contains all characters of t.
    Once the window contains all characters, move the left pointer to minimize the window size while still satisfying the requirement that all characters in t are present.

- Optimized Search:
    Every time a valid window is found (i.e., a substring that contains all characters of t), we check its length. If it's the smallest one found so far, we update our result.
    Continue this process until the right pointer has traversed the entire string s.

- Handling Edge Cases:
    If s is shorter than t, return an empty string.
    If no valid window is found by the end of the loop, return an empty string.
    Handle cases with repeated characters and different frequencies.

### Approach:

- Frequency Map: Create a frequency map for the characters in t.
- Two Pointers: Use two pointers (left and right) to create a sliding window over s.
- Window Check: Expand the window by moving right and check if the window contains all characters of t.
- Minimization: When a valid window is found, try to minimize its size by moving left.
- Result Update: Track the smallest valid window found and return it.

### Complexity Analysis:

- Time Complexity:
    O(N), where N is the length of string s.
    Reason: In the worst case, each character in s is visited twice, once by right and once by left, making this a linear time algorithm.

- Space Complexity:
    O(M), where M is the number of unique characters in t.
    Reason: We are using two maps, one for t and one for the window in s. These maps have a size proportional to the number of unique characters in t.Smallest Window Covering All Characters
