# Double Hashing

## Description

Double hashing is a collision resolution technique used in hash tables, which utilizes two hash functions. The primary hash function computes the initial hash value, while the secondary hash function calculates the step size for probing. This method effectively minimizes collisions and ensures efficient key-value insertion, searching, and deletion.

### Problem Definition

Hash collisions occur when multiple keys map to the same index. Double hashing addresses this by using a secondary hash function to determine probe sequences, reducing the chance of collisions.

### Algorithm Overview

1. **Hash Functions:**
   - Primary hash: `h1(k) = k % table_size`
   - Secondary hash: `h2(k) = prime - (k % prime)`

2. **Probing:**
   - When a collision occurs, the index is calculated as:
     ```
     index = (h1(k) + i * h2(k)) % table_size
     ```
     where `i` is the probe number.

3. **Operations:**
   - **Insert:** Probe using the second hash function until an empty slot is found.
   - **Search:** Probe until the key is found or an empty slot is encountered.
   - **Delete:** Mark the key as deleted (using a special marker) after locating it.

### Time Complexity

- **Best case (no collision):** O(1)
- **Average case:** O(1 / (1 - α)), where α is the load factor
- **Worst case:** O(n) when the table is nearly full or congested

---

## Code Update

### Changes Made

1. **Added `DELETED` Marker:**  
   Introduced a `DELETED` marker to handle lazy deletion. This ensures that previously deleted slots don't disrupt insertion and search operations.
   
2. **Improved Insertion Feedback:**  
   Now provides feedback on successful insertions or if the table is full.

3. **Handled Deleted Slots in Search:**  
   Enhanced the search function to allow probing past deleted entries for more accurate searches.

4. **Modularity and Structure:**  
   The overall structure of the code was refined to improve clarity and modularity, ensuring better readability and maintainability.

### Before:

- Deletion marked slots as `EMPTY`, disrupting search and insertion processes.
- No feedback on insert success/failure.

### After:

- **Lazy Deletion:** Marked slots as `DELETED` to allow continued probing.
- **Feedback:** Insertion provides real-time success or failure notifications.
- **Cleaner Structure:** Functions are clearer and more maintainable.

