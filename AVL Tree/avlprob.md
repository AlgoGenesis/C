# AVL tree problems

## 1. Insertion in an AVL Tree

### Problem:
Write a program to insert nodes into an AVL tree and maintain its balance after each insertion.

### Solution:

```python
class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
        self.height = 1

class AVLTree:
    def insert(self, root, key):
        if not root:
            return TreeNode(key)

        if key < root.val:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        balance = self.getBalance(root)

        if balance > 1 and key < root.left.val:
            return self.rightRotate(root)
        if balance < -1 and key > root.right.val:
            return self.leftRotate(root)
        if balance > 1 and key > root.left.val:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        if balance < -1 and key < root.right.val:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    def leftRotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def rightRotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def getHeight(self, root):
        if not root:
            return 0
        return root.height

    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

def preOrder(root):
    if not root:
        return
    print("{0} ".format(root.val), end="")
    preOrder(root.left)
    preOrder(root.right)

# Driver program to test above function
avl_tree = AVLTree()
root = None

numbers = [10, 20, 30, 40, 50, 25]

for number in numbers:
    root = avl_tree.insert(root, number)

# Preorder Traversal
print("Preorder traversal of the AVL tree is:")
preOrder(root)
```


## 2. Deletion in an AVL Tree
### Problem:
Write a program to delete a node from an AVL tree while maintaining the balance.

### Solution:
```
class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
        self.height = 1

class AVLTree:
    def delete(self, root, key):
        if not root:
            return root

        if key < root.val:
            root.left = self.delete(root.left, key)
        elif key > root.val:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            temp = self.getMinValueNode(root.right)
            root.val = temp.val
            root.right = self.delete(root.right, temp.val)

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))
        balance = self.getBalance(root)

        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)
        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)
        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    def leftRotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def rightRotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        return y

    def getMinValueNode(self, root):
        if root is None or root.left is None:
            return root
        return self.getMinValueNode(root.left)

    def getHeight(self, root):
        if not root:
            return 0
        return root.height

    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

def preOrder(root):
    if not root:
        return
    print("{0} ".format(root.val), end="")
    preOrder(root.left)
    preOrder(root.right)

avl_tree = AVLTree()
root = None

numbers = [9, 5, 10, 0, 6, 11, -1, 1, 2]

for number in numbers:
    root = avl_tree.insert(root, number)

print("Preorder traversal before deletion:")
preOrder(root)

key = 10
root = avl_tree.delete(root, key)

print("\nPreorder traversal after deletion of 10:")
preOrder(root)
```

# 3. Find the Height of an AVL Tree
# Problem:
Write a program to find the height of an AVL tree.

# Solution:
```
class AVLTree:
    def getHeight(self, root):
        if not root:
            return 0
        return root.height

# Example usage:
root = None
avl_tree = AVLTree()

numbers = [10, 20, 5, 6, 15, 30]

for number in numbers:
    root = avl_tree.insert(root, number)

print("Height of the AVL tree is:", avl_tree.getHeight(root))
```
## 4. Check if a Binary Tree is AVL (Balanced)
### Problem:
Write a program to check whether a binary tree is balanced (AVL).

### Solution:
```
class AVLTree:
    def isBalanced(self, root):
        if not root:
            return True

        leftHeight = self.getHeight(root.left)
        rightHeight = self.getHeight(root.right)

        if abs(leftHeight - rightHeight) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right):
            return True
        return False

    def getHeight(self, root):
        if not root:
            return 0
        return max(self.getHeight(root.left), self.getHeight(root.right)) + 1

# Example usage:
avl_tree = AVLTree()
root = None
numbers = [10, 20, 30, 40, 50]

for number in numbers:
    root = avl_tree.insert(root, number)

print("Is the tree balanced? ", avl_tree.isBalanced(root))
```
