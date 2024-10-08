# Double Hashing

## Description

Double hashing is a collision resolution technique used in hash tables. It works by using two hash functions to compute two different hash values for a given key. The first hash function is used to compute the initial hash value, and the second hash function is used to compute the step size for the probing sequence.

Double hashing has the ability to have a low collision rate, as it uses two hash functions to compute the hash value and the step size.

### Problem Definition

Hash collisions occur when multiple keys map to the same index. Double hashing minimizes collisions by using a secondary hash function to calculate probe sequences, ensuring efficient key-value insertion, searching, and deletion.

### Algorithm Overview

1. Hash Functions:

h1(k) = k % table_size (primary hash).

h2(k) = prime - (k % prime) (secondary hash).



2. Probing:

When a collision occurs, use:

index = (h1(k) + i * h2(k)) % table_size

i is the probe number.



3. Operations:

Insert: Probe using the second hash function until an empty slot is found.

Search: Probe until the key is found or an empty slot is encountered.

Delete: Mark the key as deleted after locating it through probing.


### Time Complexity

Best case (no collision): O(1).

Average case: O(1 / (1 - α)), where α is the load factor.

Worst case: O(n) when the table is nearly full or highly congested.