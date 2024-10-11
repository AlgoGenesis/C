# Single Hashing 

## Description

Single hashing with quadratic probing is an open addressing technique used in hash tables to handle collisions. When a collision occurs (i.e., two keys are hashed to the same index in the hash table), quadratic probing helps resolve it by using a sequence of quadratic intervals to find the next available slot.

In quadratic probing, the hash function is supplemented with a probing function that computes a new index by adding quadratic offsets from the original hashed index. This technique reduces the clustering of collisions compared to linear probing.

### Problem Definition

The primary problem in hash tables is dealing with collisions, which occur when multiple keys are hashed to the same index. Quadratic probing is a strategy for finding alternative positions in the table when a collision happens, minimizing the chances of forming clusters of keys.

Given a hash table with a fixed size, we need to:

Insert new key-value pairs while handling collisions efficiently.

Search for a given key and retrieve its associated value.

Remove a key-value pair if necessary.

Ensure that the hash table remains efficient as the load factor (ratio of occupied slots to total slots) increases.

### Algorithm Overview

Step 1: Hash Function
Use a simple hash function, such as h(k) = k % table_size, where k is the key, and table_size is the size of the hash table.

Step 2: Quadratic Probing
If a collision occurs at index h(k), use the quadratic probing function to find the next available slot. The probing sequence is defined as:

h'(k, i) = (h(k) + i^2) % table_size

Where:

h(k) is the initial hashed index.

i is the probe number (starting from 0 for the first probe).

table_size is the size of the hash table.


The probe sequence starts with checking index h(k) and continues with indices (h(k) + 1^2) % table_size, (h(k) + 2^2) % table_size, and so on until an empty slot is found.

Step 3: Insert Operation

1. Hash the key using the hash function: index = h(k).


2. If the slot at index is empty, insert the key-value pair.


3. If a collision occurs, apply quadratic probing using the formula above until an empty slot is found.


4. Insert the key-value pair at the available index.



Step 4: Search Operation

1. Hash the key using the hash function: index = h(k).


2. If the key is found at the index, return the value.


3. If there is a collision (the key is not found), apply quadratic probing to search the subsequent indices until the key is found or an empty slot is encountered (indicating the key is not in the table).



Step 5: Delete Operation

1. Hash the key using the hash function: index = h(k).


2. Apply quadratic probing to locate the key.


3. Mark the slot as deleted or empty once the key is found.


### Time Complexity

The time complexity of operations in single hashing with quadratic probing depends on the load factor (α = number of filled slots / total table size). Here's a breakdown:

Insertion:

Best case: O(1) (no collision).

Average case: O(1 / (1 - α)) due to quadratic probing.

Worst case: O(n) if the table is nearly full or all possible probe indices are occupied.


Search:

Best case: O(1) (no collision).

Average case: O(1 / (1 - α)).

Worst case: O(n), particularly when there is a high load factor and many collisions.


Deletion:

Best case: O(1) (no collision).

Average case: O(1 / (1 - α)).

Worst case: O(n), depending on the distribution of elements and the load factor.

