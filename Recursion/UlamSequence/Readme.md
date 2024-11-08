## Ulam Sequence Generation 

### Problem Description

The **Ulam sequence** is a well-known sequence in mathematics defined by the following rules:

1. The sequence starts with the numbers **1** and  **2** .
2. Each subsequent number in the sequence is the smallest integer that can be expressed as the sum of two distinct earlier numbers in exactly one way.

 **Objective** : The goal is to generate the Ulam sequence up to a given maximum value using a recursive approach.

**Requirements**

1. **Input** :

* An integer `maxN` (where maxN≥1) that specifies the maximum value for which the Ulam sequence should be generated.
* The program should prompt the user to enter this value.

    2.**Output** :

* The program should print the Ulam sequence starting from **1** and  **2** , and include all Ulam numbers up to the specified maximum value `maxN`.

## Does the problem have small constraints?

 **Input Constraints** :

* The input `maxN` should ideally be a positive integer, as Ulam numbers start from **1** and  **2** .
* A reasonable upper limit for `maxN` could be set to prevent excessive computation and potential stack overflow due to recursion.

**Small Constraints** :

* For small values of `maxN` (e.g., 1 to 20), the problem is manageable and allows for a straightforward recursive implementation without significant performance concerns.
* The recursive nature of the problem may lead to slower execution times as `maxN` increases, primarily due to the increasing number of checks needed to validate Ulam numbers.

 **Recommended Upper Bound** :

* You might want to define an upper bound for `maxN`, such as **100** or  **200** , to ensure that the recursive approach remains efficient and does not lead to stack overflow or excessive computation time.
* If the program needs to handle larger values (e.g., 1000 or more), an iterative approach or memoization techniques should be considered to improve performance.

## Solution Approach

The objective is to generate the Ulam sequence up to a given maximum value (`maxN`). The sequence starts with the numbers **1** and  **2** , and each subsequent number must be the smallest integer that can be expressed as the sum of two distinct earlier numbers in exactly one way.

1. **Understanding Ulam Sequence Generation**

* Initial Elements : The sequence begins with **1** and  **2** .
* New Number Generation : To find the next Ulam number, we need to:
* Check sums of all pairs of existing Ulam numbers.
* Count how many times each sum can be formed.
* Select the smallest sum that can be expressed in exactly one way.

#### 2. Function Breakdown

The solution consists of the following functions:

1. **`isUlam(int n, int ulam[], int size)`** :

* **Purpose** : To check if a number `n` can be added to the Ulam sequence.
* **Logic** :
  * Iterate through pairs of Ulam numbers.
  * Count occurrences of sums in a hashmap or array.
  * Return true if `n` can be expressed as a sum in exactly one way.

    2.**`generateUlam(int current, int maxN, int ulam[], int *size)`** :

* **Purpose** : To recursively generate Ulam numbers starting from a given `current` number.
* **Logic** :

  * Base Case: If `current > maxN`, stop the recursion.
  * If `isUlam(current, ulam, *size)` returns true, add `current` to the Ulam array.
  * Increment the size of the Ulam array.
  * Make a recursive call with `current + 1`.

#### 3. Overall Process

1. **Initialization** :

* Start with an array to hold Ulam numbers, initialized with **1** and  **2** .
* Initialize the size of the Ulam array to 2

   2 . **Recursive Generation** :

* Call the `generateUlam` function starting from  **3** .
* This function will fill the Ulam array until the maximum value is reached.

   3.**Output** :

* After generating the Ulam sequence, print the elements stored in the Ulam array.

### **Implementation Steps**

1. **Input Handling** : Prompt the user to enter the maximum value for the Ulam sequence.
2. **Ulam Sequence Generation** :

* Use recursion to explore potential Ulam numbers.
* Validate each candidate using the `isUlam` function.

3. **Printing the Result** : After completion, display the generated Ulam sequence.

## Complexity

The **time complexity** of the recursive Ulam sequence generation is approximately O(k^3)**,** where `k` is the number of Ulam numbers generated up to `maxN`. This is because, for each new Ulam number, we check all pairs of previously generated numbers, leading to quadratic checks at each step, and we make recursive calls for each number up to `maxN`.

The **space complexity** is O(k+maxN), where `k` accounts for storing the Ulam numbers and `maxN` represents the depth of the recursion stack. While this approach works for small constraints, it becomes inefficient for large values of `maxN`.
