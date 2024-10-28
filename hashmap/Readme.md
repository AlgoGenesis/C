# HashMap Implementation in C
This project is a simple implementation of a HashMap (or Hash Table) in C, using chaining to handle collisions.The implementation includes common HashMap operations
such as insertion, search, and deletion of key-value pairs. The chaining mechanism uses linked lists to resolve hash collisions.

## Features
Chaining-based collision handling: Handles collisions using linked lists in each bucket.
Hashing: Uses a simple modulo-based hash function.
Operations:
Insertion of key-value pairs.
Searching for a value by its key.
Deleting key-value pairs.
Memory management: Clean up memory to avoid memory leaks.

## 1. Insertion
The insertion operation involves adding a new key-value pair to the HashMap. The process is as follows:

Hashing: The key is hashed using the hash function. In this case, the hash function uses the modulo operation to map the key to a specific index in the bucket array:
The result of the hash function is the index in the bucket array where the key-value pair will be inserted.

Collision Handling: If two keys produce the same index (i.e., a collision occurs), the linked list at that bucket is extended to accommodate the new key-value pair. 
This is called chaining. Each bucket points to the head of a linked list, and new nodes are added to the end of the list if there is a collision.

Time Complexity:
Best case (no collision): O(1)
Worst case (multiple collisions): O(n) where n is the number of nodes in the linked list (in the case of a very poor hash function or many collisions).

## 2. Deletion
The deletion operation removes a key-value pair from the HashMap by:

Hashing: The key to be deleted is hashed to find the index of the bucket.
Traversal: The linked list at the bucket is traversed to find the node that contains the given key.
Removal: Once the node with the given key is found:
If it's the head of the list, the bucket is updated to point to the next node.
If it's in the middle or at the end of the list, the previous node's next pointer is updated to bypass the node to be deleted.

Memory Deallocation: The memory allocated for the deleted node is freed.

Time Complexity:
Best case: O(1) (when the key is found immediately and there's no collision)
Worst case: O(n) (when multiple nodes are in the same bucket, and the key is found at the end)

## 3. Searching
Searching for a key in the HashMap involves:

Hashing: The key to be searched is hashed to find the index of the bucket.
Traversal: The linked list at the bucket is traversed, checking each node's key. If the key is found, the corresponding value is returned;
otherwise, a value of -1 (indicating "not found") is returned.

The linked list traversal continues until either:

The key is found, or
The end of the list is reached (in which case the key doesn't exist in the HashMap).
Time Complexity:
Best case: O(1) (if the key is at the head of the list or no collision occurred)
Worst case: O(n) (if there are multiple collisions, and the key is at the end of the list)
