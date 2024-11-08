## SUBDOMAIN VISIT COUNT

# Problem Description
You are given a list of strings cpdomains, where each string is formatted as "count domain", meaning that the count number of visits occurred to the given domain. The domain can have subdomains, and you need to count the number of visits for each subdomain as well.

# Example
Input:
["9001 discuss.leetcode.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]

Output:
[
  "9511 com",
  "9001 leetcode.com",
  "50 yahoo.com",
  "1 mail.com",
  "5 org",
  "5 wiki.org",
  "1 intel.mail.com"
]

# Solution Approach
Parse the Input: For each entry in cpdomains, split the string into the count and the domain.
Count Visits: Use a map (or hash table) to keep track of the visit counts for each domain and its subdomains.
Iterate Over Domains: For each domain, split it into subdomains. For example, discuss.leetcode.com can be split into:
discuss.leetcode.com
leetcode.com
com
Update the Counts: For each subdomain, update the visit count in the map.
Format the Output: Convert the map into the required output format.


# Time and Space Complexity
The  time and space complexity involves:

Storing the counts for each unique subdomain. The maximum number of unique subdomains can be at most ( O(n \cdot m) ) if every entry has a unique subdomain structure.
Additionally, we need space for the input data, which is ( O(n) ).
Thus, the overall space complexity is:

Worst-case: ( O(n \cdot m) )