# LeetCode - Linked List | Solutions
- **Language**: all solutions in **Python 3**
- **Implementation**: ideas taken from various sources, organized and coded by me
- **Problem Search**: use "Ctrl + F" to search for problem ID
---

## 1. UTMOST MUST DO Problems - Base Problems:

### 1. Cycle Detection and Finding (usually with Slow / Fast Pointers)

:heavy_check_mark: :green_book: [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/): (either using **slow/fast pointers** or a clever way of node deletion)

- **Clever way of changing element to None after traversal**

```
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        # Sample Solution: clever way of changing element to None after traversal
        # https://leetcode.com/problems/linked-list-cycle/discuss/44494/Except-ionally-fast-Python/240672
        
        while head:
            if head.val == None:
                return True
            head.val = None
            head = head.next
        return False
```

- **Using slow/fast pointers (as in Study Guide)**

```
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if not head:
            return False
    
        slow, fast = head, head # both starting from head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        
        return False
```

---

:heavy_check_mark: :orange_book: [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/): (using **slow/fast pointers**)

```
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        slow = fast = head
        
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                break
                
        else: # if not (fast and fast.next): return None
            return None
        
        while head != slow:
            head, slow = head.next, slow.next
            
        return head
```

---

### 2. Miscellaneous Problems with Slow / Fast Pointers

:heavy_check_mark: :green_book: [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/): (**Slow/Fast Pointers to divide list & reversing linked list**)

```
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/palindrome-linked-list/discuss/64500/11-lines-12-with-restore-O(n)-time-O(1)-space
        
        # rev records the first half, need to set the same structure as fast, slow, hence later we have rev.next
        rev = None

        # initially slow and fast are the same, starting from head
        slow = fast = head

        while fast and fast.next:
            # fast traverses faster and moves to the end of the list if the length is odd
            fast = fast.next.next

            # take it as a tuple being assigned (rev, rev.next, slow) = (slow, rev, slow.next), 
            # hence the re-assignment of slow would not affect rev (rev = slow)
            
            # "rev, rev.next, slow = slow, rev, slow.next" is equivalent to:
            temp1 = slow
            temp2 = rev
            temp3 = slow.next
            rev = temp1 # current rev is the same as slow
            rev.next = temp2 # next of rev is the previous rev
            slow = temp3 # slow moves one step further

        # When fast reaches the end or past the end, the slow will reach the middle or past the middle
        if fast:
            # fast is exactly at the end, move slow one step further for comparison (cross middle one)
            slow = slow.next

        # compare the reversed first half with the second half
        while rev and rev.val == slow.val:
            slow = slow.next
            rev = rev.next

        # if equivalent then rev become None, return True; otherwise return False 
        return not rev
```

---


:heavy_check_mark: :green_book: [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/): (**Slow/Fast Pointers for cycle detection & concatenating lists**)

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49798/Concise-python-code-with-comments/182352

        # Concatenate list A and list B, if there's an intersection, there's a loop, so we need to find the start of the loop if there's any:

        if not headA or not headB: return None

        # Concatenate A and B
        last = headA
        while last.next: last = last.next
        last.next = headB

        # Find the start of the loop
        fast = slow = headA
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast: # If there is a loop
                break
        else: # there is no loop -> there is no intersection
            last.next = None # Retain lists' original structures
            return None
        
        while headA != slow:
            slow, headA = slow.next, headA.next
        last.next = None # Retain lists' original structures
        
        return headA
```

---


:heavy_check_mark: :orange_book: [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/): (**Slow/Fast Pointers for finding N-th node from end of list**)

```
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8802/3-short-Python-solutions
        
        fast = slow = head
        
        for _ in range(n):
            fast = fast.next
            
        # Removing first element of list (n = number of nodes)
        if not fast:
            return head.next
        
        # fast and slow will have a distance of n nodes
        # so when fast reaches the end node, slow reaches the n-th node before the end node
        # which is very quite clever
        
        while fast.next:
            fast = fast.next
            slow = slow.next
            
        slow.next = slow.next.next # remove slow.next node
        
        return head
```

---

:heavy_check_mark: :orange_book: [148. Sort List](https://leetcode.com/problems/sort-list/): (using **Merge Sort & Slow/Fast Pointers for dividing the list**)

```
class Solution(object):
    # Reference Solution:
    # https://leetcode.com/problems/sort-list/discuss/46711/Python-easy-to-understand-merge-sort-solution/604660
        
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if not head.next:
            return head
        
        # cut the list into two halves
        
        slow, fast = head, head.next
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            
        second = slow.next # slow points to the last node of the first half
        slow.next = None # seperating the two halves
        
        l = self.sortList(head)
        r = self.sortList(second)
        
        return self.merge(l, r)
        
    def merge(self, l, r):
        # merge two lists in ascending order
            
        if l is None:
            return r
        elif r is None:
            return l
            
        dummy = ListNode(0)
        head = dummy

        while l and r:
            if l.val <= r.val:
                head.next = l
                l = l.next
            else:
                head.next = r
                r = r.next
            head = head.next

        head.next = l if r is None else r
        return dummy.next
```

---

### 3. Miscellaneous Problems with Dummy Nodes & Double Pointers & Etc.

:heavy_check_mark: :orange_book: [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/): (**Dummy Nodes** with a super helpful **visual guide**)

```
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # Reference Solution:
        
        # https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1774318/Python3-I-HATE-LINKED-LISTS-shDsh-Not-Explained/1268978
        # For visual guide: https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1775033/swapping-nodes-not-just-the-values-visual-explanation-well-explained-c
        
        dummy = ListNode(None, head)
        prev, cur = dummy, head
        
        while cur and cur.next:
            prev.next = cur.next
            cur.next = prev.next.next
            prev.next.next = cur
            # prev, cur = cur, cur.next
            prev = cur
            cur = cur.next
            
        return dummy.next
```

---

:heavy_check_mark: :green_book: [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/):

```
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # YouTube Tutorial:
        # https://youtu.be/XDO6I8jxHtA
        
        if not head:
            return None
        
        if not head.next:
            return head
        
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
            
        return prev
```

---

:heavy_check_mark: :green_book: [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

```
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        
        if not head:
            return None
        if not head.next:
            return head if head.val != val else None
        
        prev, curr = head, head.next
        
        while curr:
            if curr.val == val: # delete curr node
                prev.next = curr.next
                curr = curr.next
            else:
                curr = curr.next
                prev = prev.next
                
        # Check the first element (cause we skipped it with the curr = head.next)
        if head.val == val:
            head = head.next
        
        return head
    
        # We can also use a dummy node:
        # https://leetcode.com/problems/remove-linked-list-elements/discuss/158651/Simple-Python-solution-with-explanation-(single-pointer-dummy-head).
```

---

:heavy_check_mark: :orange_book: [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/): (**Double Pointers**, one for odd elements and one for even elements)

```
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # idea: filter out list of odd nodes and list of even nodes, then merge
        
        if not head:
            return None
        if not head.next:
            return head
        
        odd = head # Both of them point at the first node of the target linked list
        even = head.next # doesn't matter even there's only one node in the linked list (even will become None)
        eHead = even # We have to keep where the even-node list starts
        
        while even and even.next: # won't get in the loop at first if there's only one node in the linked list
            # both even and even.next are necessary condition because even might point to None, which has no attribute 'next'
            # AND, why these two, small discussion by myself as below
            odd.next = odd.next.next
            even.next = even.next.next
            # After these two ops, odd/even still points at its original place
            # Therefore, we move them to the next node repectively
            odd = odd.next
            even = even.next
            
        odd.next = eHead # the odd pointer currently points at the last node of the odd-node list
        
        return head # We keep the start of the odd-node list in the first of our code
```

---

:wavy_dash: :orange_book: [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/): (**Double Pointers**, one for each linked list)

```
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        
        first_ptr, second_ptr = l1, l2
        carry_over = 0
        
        first_len, second_len = 0, 0
        while first_ptr:
            first_len += 1
            first_ptr = first_ptr.next
        while second_ptr:
            second_len += 1
            second_ptr = second_ptr.next
        
        if first_len < second_len:
            l1, l2 = l2, l1
        
        # Now l1 is always the longer linked list
        first_ptr, second_ptr = l1, l2
        
        while first_ptr or second_ptr:
                                  
            if second_ptr:
                value = (first_ptr.val + second_ptr.val + carry_over) % 10 
                carry_over = (first_ptr.val + second_ptr.val + carry_over) // 10
                first_ptr.val = value
                
                if not first_ptr.next and carry_over != 0:
                    # We need an extra node for extra digit
                    new = ListNode(carry_over)
                    first_ptr.next = new
                    break
                else:
                    first_ptr = first_ptr.next
                    second_ptr = second_ptr.next
                                    
            else:
                value = (first_ptr.val + carry_over) % 10
                carry_over = (first_ptr.val + carry_over) // 10
                first_ptr.val = value
                
                if not first_ptr.next and carry_over != 0:
                    # We need an extra node for extra digit
                    new = ListNode(carry_over)
                    first_ptr.next = new
                    break
                else:
                    first_ptr = first_ptr.next
            
        return l1
```

---

:wavy_dash: :green_book: [237. Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/): A very down-voted trick question, BUT it seems to be a popular interview question

```
class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # Replace the node with the value of the node after it
        # And then skip the next node
        # BUT we are leaving the next node hanging there, possible memory leak
        # SO this is kind of a trick question (that's why there are so many downvotes)
        
        node.val = node.next.val
        node.next = node.next.next
```

---

:wavy_dash: :orange_book: [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/): (**Dictionary** to create the copy)

```
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        
        # Reference Solution:
        # https://leetcode.com/problems/copy-list-with-random-pointer/discuss/373694/Python3-Dictionary
        
        if head is None: return None
        
        # build mapping of original node to it's copy
        mapping = {}
        cur = head
        
        while cur:
            mapping[cur] = Node(cur.val, None, None)
            cur = cur.next
        cur = head
        
        while cur:
            if cur.next:
                mapping[cur].next = mapping[cur.next]
            if cur.random:
                mapping[cur].random = mapping[cur.random]
            cur = cur.next
        return mapping[head]
        
        # Another Reference Solution:
        # https://leetcode.com/problems/copy-list-with-random-pointer/discuss/373694/Python3-Dictionary
```

---

:wavy_dash: :closed_book: [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/): (**DFS - Preorder Traversal** to serialize the binary tree)

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    
    # Reference Solution:
    # https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/396124/Python-very-easy-to-understand-recursive-preorder-with-comments
    # Simplification by : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/396124/Python-very-easy-to-understand-recursive-preorder-with-comments/1099960
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        
        # take care of base cases
        # if a node is empty, add 'x' to string
        # you can set 'x' to any mark as you want
        
        if not root: return '#'
        
        # preoder(Root->left->right)
        # ex,
        #     1
        #    / \
        #   2   3
        #      / \
        #     4   5 
        # 
        # return (1, (2, 'x', 'x'), (3, (4, 'x', 'x'), (5, 'x', 'x')))
        # if you look at the return statement very closely, it is actually very intuitive
        # for value 1, you have 2 as left child and 3 as right child
        # for value 2, you have 'x'(None) as left child and 'x'(None) as right child which indicates it is a leaf node
        
        def dfs(root):
            if not root:
                return ["#"]
            return [str(root.val)] + dfs(root.left) + dfs(root.right)
        
        return ",".join(dfs(root))
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        #######################INTUITION#########################
        # The initial data string will be something like below:
        # (1, (2, 'x', 'x'), (3, (4, 'x', 'x'), (5, 'x', 'x')))
        # if you loop through string: 
        # 1                                 -> this is node value
        # (2, 'x', 'x')                     -> this is node left
        # (3, (4, 'x', 'x'), (5, 'x', 'x')) -> this is node right
        ########################################################
 
        def rdeserialize(queue):
            """ a recursive helper function for deserialization."""
            if queue[0] == '#':
                queue.pop(0)
                return None
                
            # reconstruct tree node (value, left, right)
            root = TreeNode(queue[0])
            queue.pop(0)
            root.left = rdeserialize(queue)
            root.right = rdeserialize(queue)
            return root
    
        queue = data.split(',')
        
        return rdeserialize(queue)
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
```

---