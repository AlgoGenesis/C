## Recursive Vose's Alias Method

### Problem Description

In probability theory and computer science, the **Alias Method** is an efficient algorithm to sample from a discrete probability distribution in constant time, after a preprocessing step. The goal of this problem is to implement **Vose's Alias Method** using recursion, to generate random samples from a given probability distribution.

The **Recursive Vose’s Alias Method** extends the classic approach by building the alias table recursively instead of using an iterative process. The alias table enables the sampling of an element in constant time, even if the probability distribution is non-uniform.

**Input:**

You are given:

* An integer `n`, which is the number of possible outcomes.
* A list of `n` probabilities, where each probability corresponds to an outcome. The probabilities are non-negative and sum up to 1.

#### Task:

1. **Construct the Alias Table Recursively** :

* Divide the probabilities into two categories: those smaller than or equal to `1/n` and those larger than `1/n`.
* Recursively set up the alias table by pairing elements from both categories.
* Store two key pieces of information for each element in the table: the probability of directly sampling the element, and the alias (an alternate element to sample in case the direct probability is not met).

1. **Sampling** :

* Use the alias table to sample an element in constant time (`O(1)`).
* Based on a random number, choose whether to sample the current element or its alias.

#### Constraints:

* The number of probabilities `n` is such that `1 <= n <= 10^5`.
* The probabilities must sum to 1. If they do not, return an error message.

#### Example : 

Enter the number of probabilities: 4
Enter the probabilities (space-separated, must sum to 1):
0.1 0.2 0.3 0.4

#### Output:

* Sampled index: 3

#### Steps to Implement:

**Input Handling** :

* Accept the number of outcomes `n`.
* Accept a list of `n` probabilities that sum to 1.

**Recursive Alias Table Construction** :

* Create two lists: `small` for probabilities ≤ `1/n`, and `large` for probabilities > `1/n`.
* Recursively process elements by adjusting the probabilities and building the alias table.

**Random Sampling** :

* For a random sample, first select an index randomly from `0` to `n-1`.
* Based on another random value, decide whether to pick the direct element or its alias.

## Does the problem have small constraints?

### Constraints:

**Number of Outcomes (`n`)** :

The problem can have `1 <= n <= 10^5` outcomes.

This is a moderate constraint, as `n` can be as large as 100,000, which means the algorithm must handle reasonably large input sizes efficiently.

**Probabilities Sum to 1** :

The probabilities must sum to exactly 1, but this can be handled easily by validating the input.

Input probabilities are real numbers, so proper handling of floating-point precision is important.

**Small Constraints:**

The preprocessing step to create the alias table (with `O(n)` time complexity) ensures the algorithm is efficient even when the number of outcomes (`n`) is large.

The actual **sampling operation** must happen in  **constant time (`O(1)`)** , which is small enough to handle numerous sampling operations quickly.

## Solution Approach

**Input Handling** :

Read the number of probabilities `n` and ensure it is valid (`n > 0`).

Read the list of probabilities and ensure they sum to `1`. If not, return an error message.

**Initialization** :

Create an alias table structure that includes:

* An array for `probabilities` (the adjusted probabilities for sampling).
* An array for `aliases` (to store the alias indices).

Initialize temporary lists for `small` and `large` probabilities.

**Categorize Probabilities** :

Iterate through the probabilities:

* If a probability is less than `1/n`, add its index to the `small` list.
* If it is greater than or equal to `1/n`, add its index to the `large` list.

**Build the Alias Table Recursively** :

Define a recursive function that processes the `small` and `large` lists:

* While both lists are not empty:
  * Remove an index from `small` and one from `large`.
  * Set the adjusted probability for the `small` index to its original probability scaled by `n`.
  * Set the alias for the `small` index to the `large` index.
  * Update the probability of the `large` index by reducing it by `1/n`.
  * If the updated probability of the `large` index is still less than `1/n`, add it to the `small` list; otherwise, add it back to the `large` list.

Continue this until all probabilities are processed and the alias table is fully constructed.

**Sampling** :

Create a sampling function that:

* Randomly selects an index from the range `[0, n-1]`.
* Generates a random number to decide whether to sample from the `probabilities` or use the corresponding alias from the `aliases` table.

## Complexity

The complexity of the Recursive Vose's Alias Method is efficient, with a preprocessing time of  **O(n)** , where `n` is the number of probabilities. This preprocessing involves constructing the alias table by iterating through the probabilities and setting up the `small` and `large` lists. Once the alias table is built, each sampling operation takes constant time, or  **O(1)** , allowing for rapid sampling from the distribution. In terms of space complexity, the algorithm requires **O(n)** to store the alias and probability arrays. Overall, the method is designed to be both time-efficient for setup and quick for sampling, making it suitable for applications that demand frequent random sampling from a discrete probability distribution.
