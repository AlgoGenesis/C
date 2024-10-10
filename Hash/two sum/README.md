## Two Sum : Check if a pair with given sum exists in Array

### Problem Statement:

- Given an array of integers arr[] and an integer target.

- Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

- Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

```
Examples:

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.
```

### Approach(using Hashing):

- Intuition: Basically, in the previous approach we selected one element and then searched for the other one using a loop. Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists. Thus we can trim down the time complexity of the problem.

- And for the second variant, we will store the element along will its index in the HashMap. Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.

### Approach:

- The steps are as follows:

- We will select the element of the array one by one using a loop(say i).
- Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
- If that element exists, then we will return “YES” for the first variant or we will return the current index i.e. i, and the index of the element found using map i.e. mp[target-arr[i]].
- If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
- Finally, if we are out of the loop, that means there is no such pair whose sum is equal to the target. In this case, we will return either “NO” or {-1, -1} as per the variant of the question.

```
Dry Run: Given array, nums = [2,3,1,4], target = 4

Note: Here x denotes the currently selected element.

For index 0, x = 2, and currently map is empty.
We try to find if target – x = 4 – 2 = 2 is present in the map or not.
For now, 2 does not exist on the map.
And we store the index of element 2. i.e., mp[2] = 0,

For index 1, x = 3
We try to find if target – x = 4  – 3 = 1 is present in the map or not.
For now, 1 does not exist on the map.
And we store the index of element 3. i.e., mp[3] = 1,

For index 2, x = 1
We try to find if target – i = 4  – 1 = 3 is present in the map or not. 3 exists in the map, so we store index 2 and the value stored for key 3 in the map and break the loop. And return [1,2].
```
