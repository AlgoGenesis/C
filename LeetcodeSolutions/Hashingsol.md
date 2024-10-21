# LeetCode - Hash Tables | Solutions
* **Note**: 
  * :heavy_check_mark: means **MUST DO (i.e., very important, typical, or good) problems** that should definitely be familiar with
  * :wavy_dash: means problems that are less typical
  * :green_book: means **EASY problems** as defined by LeetCode
  * :orange_book: means **MEDIUM problems** as defined by LeetCode
  * :closed_book: means **HARD problems** as defined by LeetCode

---

## Important Problems

:heavy_check_mark: :green_book: [1. Two Sum](https://leetcode.com/problems/two-sum/): <key, val> = <number, its index in nums> (using **enumerate(list)**)

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        # <key, val> = <number, its index in nums>
        hash_map = {}
        
        for idx, val in enumerate(nums):
            key = target - val
            
            if key in hash_map:
                return [hash_map[key], idx]
            else:
                hash_map[val] = idx
```

---

:heavy_check_mark: :orange_book: [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/): <key, val> = <char, index it is last seen> (**Sliding Window & Two Pointers**)

```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/347818/Python3%3A-sliding-window-O(N)-with-explanation
        
        seen = {}
        l = 0
        output = 0
        
        for r in range(len(s)):
            """
            If s[r] not in seen, we can keep increasing the window size by moving right pointer
            """
            if s[r] not in seen:
                output = max(output,r-l+1) # take current window size and compare with max
            """
            There are two cases if s[r] in seen:
            case1: s[r] is inside the current window, we need to change the window by moving left pointer to seen[s[r]] + 1.
            case2: s[r] is not inside the current window, we can keep increase the window
            """
            else:
                if seen[s[r]] < l: # outside of current window, keep increasing window
                    output = max(output,r-l+1) # take current window size and compare with max
                else:
                    l = seen[s[r]] + 1 # inside current window, move left pointer to seen[s[r]] + 1
           
            seen[s[r]] = r
            
        return output
```

---

:heavy_check_mark: :orange_book: [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/): <key, val> = <hash array for 26 letters, words belonging to this hash> (using **collections.defaultdict(list)**)

```
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/group-anagrams/discuss/19202/5-line-Python-solution-easy-to-understand/262771
        
        hmap = collections.defaultdict(list)
        
        for this_str in strs:

            # hash map for the 26 letters
            array = [0] * 26
            
            for letter in this_str:
                array[ord(letter) - ord('a')] += 1
                
            # array/list not hashable, so change to tuple
            hmap[tuple(array)].append(this_str)

        return hmap.values()
```

---

:heavy_check_mark: :green_book: [290. Word Pattern](https://leetcode.com/problems/word-pattern/): (creating a **hashed pattern list** for an input)

```
class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        
        # Hash the pattern
        hashed_pattern1, seen, counter, mapping = [], set(), 0, {}
        
        for char in pattern:
            if char not in seen:
                seen.add(char)
                mapping[char] = counter
                counter += 1
        
        for char in pattern:
            hashed_pattern1.append(mapping[char])
        
        # Hash the string

        word_list = s.split(' ')
        
        hashed_pattern2, seen, counter, mapping = [], set(), 0, {}
        
        for word in word_list:
            if word not in seen:
                seen.add(word)
                mapping[word] = counter
                counter += 1
        
        for word in word_list:
            hashed_pattern2.append(mapping[word])
            
        return hashed_pattern1 == hashed_pattern2
```

---

:heavy_check_mark: :green_book: [350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/): (using **Counter()**)

```
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        counts = Counter(nums1)
        result = []
        
        for num in nums2:
            if counts[num] > 0:
                result.append(num)
                counts[num] -= 1
                
        return result
```

---

:heavy_check_mark: :orange_book: [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/): (**hashed pattern list & two pointers & sliding window**)

```
class Solution(object):
    
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """

        # Take a look at this: 
        # https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/1738052/A-very-deep-EXPLANATION-oror-Solved-without-using-HashTable
        
        if len(s) < len(p):
            return None

        hash_s, hash_p, result = [0] * 26, [0] * 26, []
        
        # hash the [p]
        for char in p:
            hash_p[ord(char) - ord('a')] += 1
        
        # hash the first substring
        for char in s[:len(p)]:
            hash_s[ord(char) - ord('a')] += 1
        
        # if first substring is an anagram, record its starting position
        if hash_s == hash_p:
            result.append(0)
        
        for left_ptr in range(1, len(s) - len(p) + 1):
            right_ptr = left_ptr + len(p) - 1
            hash_s[ord(s[left_ptr-1]) - ord('a')] -= 1 # remove one frequency of char to the left of left_ptr
            hash_s[ord(s[right_ptr]) - ord('a')] += 1 # add one frequency of char at right_ptr
            
            if hash_s == hash_p:
                result.append(left_ptr)
        
        return result
```

---

:heavy_check_mark: :orange_book: [525. Contiguous Array](https://leetcode.com/problems/contiguous-array/): <key, val> = <count, index at which this count is reached> (**prefix sum**)

```
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/contiguous-array/discuss/99655/Python-O(n)-Solution-with-Visual-Explanation
        
        count = 0
        max_length = 0
        table = {0: -1} # <key, val> = <count, last index that we reached this count>
        
        for index, num in enumerate(nums):
            if num == 0:
                count -= 1
            else:
                count += 1
            
            if count in table: # from last time we reached this count (see visualization in reference link)
                # since we equal number of 0 and 1, we will reach the same count as before
                max_length = max(max_length, index - table[count])
            else:
                table[count] = index
        
        return max_length
```

---

:heavy_check_mark: :orange_book: [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/): <key, val> = <prefix sum, frequency> (using **prefix sum & defaultdict(int) / Counter()**)

```
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # the empty subarray has a sum of 0
        # <key, val> = <sum, frequency>
        count, total = Counter({0: 1}), 0
        
        presum = 0
        
        for num in nums:
            presum += num
            total += count[presum - k]
            count[presum] += 1

        return total
```

---

:heavy_check_mark: :green_book: [594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/): <key, val> = <number, frequency> (using **Counter()**)

```
class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if len(nums) == 1:
            return 0
        
        if len(nums) == 2:
            return 2 if abs(nums[0] - nums[1]) == 1 else 0
        
        # Reference solution:
        # https://leetcode.com/problems/longest-harmonious-subsequence/discuss/103534/Python-Straightforward-with-Explanation
        
        count = collections.Counter(nums)
        ans = 0
        
        # find the frequency of each number and it incremented by 1, then take maximum possible
        for x in count:
            if x+1 in count:
                ans = max(ans, count[x] + count[x+1])
        return ans
```

---

:heavy_check_mark: :closed_book: [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/): a very clever way of using index to record frequency, using input list as extra memory

```
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # This is O(NlogN) not O(N)
        # A better solution: 
        # https://leetcode.com/problems/first-missing-positive/discuss/17080/Python-O(1)-space-O(n)-time-solution-with-explanation/312951
        
#         nums.sort()
#         missing = 1
        
#         for num in nums:
#             if num < missing:
#                 continue
#             elif num == missing:
#                 missing += 1
#             else:
#                 return missing
#         return missing

        """
        For nums with length n, the possible result is in the range of
        [1 : n + 1], we want to know the smallest integer in the range 
        of [1 : n] that is not in nums, if [1 : n] are all in nums,
        the result is n + 1
        
        So those numbers not in [1 : n] are not useful and we can just
        change them to be 0
        
        Then we go through nums, if nums[i] is in the range of 
        [1 : n], we use index (nums[i] - 1) to record that we have
        seen nums[i] by adding n + 1 to nums[nums[i] - 1]
        
        Finally we just need to find the first index i for which 
        nums[i] is less than n + 1 (which means we never met number
        i + 1 so we did not add n + 1 to nums[i])
        """

        # Solution according to: https://www.youtube.com/watch?v=8g78yfzMlao
        
        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] = 0
                
        # Our solution must be in [1, len(nums)], or len(nums) + 1 if all numbers present
        # For each number in nums, map it to index [number - 1] to indicate its existence
        # To do so, we change the number at [number - 1] as negative (to indicate it exists in nums)
        # Since we already changed all negative numbers to 0, we don't worry about original negative numbers
        # Each time we check a number in nums, we take absolute value so that the sign does not interfere
        # If number at the index is 0, we need to change it to -(len + 1)
        # because [len + 1] is the worst / greatest solution possible, its index [len] is out of bound
            
        for i in range(len(nums)):
            val = abs(nums[i])
            if 1 <= val <= len(nums):
                if nums[val - 1] > 0:
                    nums[val - 1] *= -1
                elif nums[val - 1] == 0:
                    nums[val - 1] = -1 * (len(nums) + 1)
                
        # Finally we check each possible solution, go to its mapped index [i - 1]
        # If the value there is non-negative then this solution did not appear in the nums
        # So we return it as the smallest missing positive integer
        
        for i in range(1, len(nums) + 1): # check all possible solutions in range
            if nums[i - 1] >= 0: # it is not present in the nums
                return i
            
        # If all solutions present, then the smallest missing positive integer is the next integer after the max of nums
        return len(nums) + 1 
```

---

:heavy_check_mark: :green_book: [1636. Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/): (my solution **sorting defaultdict(int) by key using sorted(dict.items())**)

```
class Solution(object):
    def frequencySort(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        if len(nums) == 1:
            return nums
        
        cnt = Counter(nums)
        dictionary = defaultdict(list)
        sorted_array = []
        
        for key, val in cnt.items():
            dictionary[val] += [key] * val
        
        s = sorted(dictionary.items()) # sorting defaultdict by key (i.e., frequency)

        for freq, vals in s:
            vals.sort(reverse = True)
            sorted_array += vals
        
        return sorted_array
```

---

:heavy_check_mark: :orange_book: [1679. Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/): (a clever way using **Counter()**)

```
class Solution(object):
    def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        # Refrence solution
        # https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1022699/Python-Short-Counter-solution-%2B-Oneliner-explained
        
        cnt = Counter(nums)
        result = 0
        
        for val in cnt:
            result += min(cnt[val], cnt[k-val])
            
        return result // 2 # counting each pair twice
```

---

## Supplemental Problems

:wavy_dash: :orange_book: [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/): <key, val> = <original node, its copy>

:wavy_dash: :orange_book: [187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/): <key, val> = <substring, frequency> (using **Counter()**)

:wavy_dash: :green_book: [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/): <key, val> = <char, the order in which it appeared in string>

:wavy_dash: :green_book: [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/): <key, val> = <num, frequency> (using **Counter()**)

:wavy_dash: :green_book: [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/): <key, val> = <num, list of its appearance positions>

:wavy_dash: :green_book: [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/): <key, val> = <char, its appearance frequency>

:wavy_dash: :orange_book: [299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/): (using **Counter()**)

:wavy_dash: :orange_book: [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/): (using **Counter() & counter.most_frequent(k)**)

:wavy_dash: :green_book: [349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/): (using **Set()**)

:wavy_dash: :green_book: [387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/): (using **Counter()**)

:wavy_dash: :green_book: [389. Find the Difference](https://leetcode.com/problems/find-the-difference/): (hashing the ASCII of letters)

:wavy_dash: :green_book: [409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/): **Palindrome** - should have at most one odd occurrence (using **Counter()**)

:wavy_dash: :orange_book: [447. Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/): <key, val> = <distance, number of pairs of points with that distance in-between> (using **Counter()**)

:wavy_dash: :orange_book: [451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/): (using **Counter()**)

:wavy_dash: :orange_book: [454. 4Sum II](https://leetcode.com/problems/4sum-ii/): (using **Counter()**)

:wavy_dash: :orange_book: [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/): (using **Counter() & DFS Tree Search**)

:wavy_dash: :orange_book: [554. Brick Wall](https://leetcode.com/problems/brick-wall/): <key, val> = <index of brick edge, frequency> (using **Counter()**)

:wavy_dash: :green_book: [645. Set Mismatch](https://leetcode.com/problems/set-mismatch/): (using **Counter() & Set()**)

:wavy_dash: :orange_book: [957. Prison Cells After N Days](https://leetcode.com/problems/prison-cells-after-n-days/): requires loop finding, non-trivial, saving all patterns inside dictionary (using **dictionary**)

:wavy_dash: :orange_book: [970. Powerful Integers](https://leetcode.com/problems/powerful-integers/)

:wavy_dash: :green_book: [1002. Find Common Characters](https://leetcode.com/problems/find-common-characters/): (my solution using **hashed pattern list**)

:wavy_dash: :green_book: [1160. Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/): (my solution using **Counter()**)

:wavy_dash: :green_book: [1189. Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/): (my solution using **hashed pattern list**)

:wavy_dash: :green_book: [1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/): (using **defaultdict(int)**)

:wavy_dash: :green_book: [1365. How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/): (using **defaultdict(int)**)

:wavy_dash: :green_book: [1539. Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/): can be solved using binary search in O(logN) (using **defaultdict(int)**)