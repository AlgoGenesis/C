# Aggressive cows problem on binary search

# Problem Description

You are given an array consisting of n integers which denote the position of a stall.You are also given an integer k which denotes the number of aggressive cows.You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

# Input format:

The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 , k=3 stalls = [1 2 4 8 9]

Output:3

Explanation:

The first cow can be placed at stalls[0], the second cow can be placed at stalls[2] and the third cow can be placed at stalls[3]. The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

Example 2:

Input:
n=5, k=3 stalls = [10 1 2 7 5]

Output: 4

Explanation:

The first cow can be placed at stalls[0],the second cow can be placed at stalls[1] and the third cow can be placed at stalls[4].The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.



# Problem Definition

The problem states that we will be given n stalls in the form of an array and K cows to place in that stall, we need to place them in such a way that the minimum distance between them is largest possible.

# Approach

We will try to find the minimum possible distance between any 2 cows and then we can find the largest distance among them.

# Conditions

There will be minimum of 2 cows always in the problem to get the minimum distance between them.

Now we want the minimum and maximum possible range to find distance
-> The minimum distance will be 1 because if there are 2 cows then we can place them at a distance of 1.
-> Maximum possible distance between them will be difference between minimum element in the array and maximum element in the array.

ex: [1,2,4,8,9] => 1 - 9 => 8

So now we have got our range which is sorted then we can apply BINARY SEARCH on the range.

range will be [1,2,3,4,5,6,7,8]

low = 1 and high = 8
mid = (low+high)/2 = mid will be at 4

Now we will check if using mid is it possible to place 3 cows such that the minimum distance is the largest possible.
Upon calculating we found that it is not possible to place 3 cows at a distance of 4 for above example so if 4 is not possible answer then definitely numbers greater than 4 will not be an answer.

hence will be put end = mid-1.

If it is possible answer then we will take an answer variable and store mid in that. ans = mid

So now we have got an answer now we will find more larger values by moving to right side for that we can put low = mid+1.

# pseudo code

low/start = 1, end/high = (max ele in arr - min ele in arr)
while(low <= high){

    mid = low + (high-low)/2
    ans = -1

    if(isPossible(mid)){
        ans = mid
        low = mid+1
    }else{
        high = mid-1
    }
}
return ans


lets see how we can find if mid is a possible answer?

step 1: Is to sort the given array because randomly we will not be able to know the distance by placing the cows.
step 2: we will start by taking cow = 1 and lastStallPos = arr[0] because will place first cow at first element of array and mid value for now will be 4.

# Pseudo code for isPossible function

sort(arr)
cows = 1 , lastStallPos = arr[0]
for(int i = 1; i<n i++>){
    if(arr[i]-lastStallPos >= mid){
        cows++
        lastStallPos = arr[i]
    }
    if(cows == k) return true
}
return false


# Time complexity and Space complexity

# T.C => O(NlogN) for sorting and O(log(range)*N)
# S.C => O(1)