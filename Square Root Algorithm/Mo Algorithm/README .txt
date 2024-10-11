README.md: Mo's Algorithm Implementation
Overview
This project implements Mo's Algorithm, which is an efficient solution for answering multiple range queries on an array. Mo's algorithm is particularly useful when dealing with queries that involve finding results over a range of array indices, such as finding the number of distinct elements in a subarray. The algorithm leverages a square root decomposition technique to minimize the number of operations required to process multiple queries on the array.

Key Concepts
Mo's Algorithm
Mo's algorithm is used to answer range queries efficiently, typically when there are a large number of queries. The algorithm works by dividing the array into blocks of size √N, where N is the size of the array, and sorting the queries based on the block and range. By processing the queries in a specific order, the algorithm minimizes the number of element additions and removals required to compute the result for each query.

Input:
An array of n elements.
q range queries, where each query is of the form (L, R) asking for information (e.g., the number of distinct elements) between indices L and R of the array.
Output:
The answer for each query.
Project Structure
main.c: The C program that implements Mo's algorithm and processes range queries on an array.
README.md: This file, explaining the project, Mo's algorithm, and instructions on how to run the program.
How the Algorithm Works
Query Structure: Each query is represented by a structure (Query) containing:

L: Left boundary of the query.
R: Right boundary of the query.
idx: The index of the query, used to store the result in the correct order after sorting.
Sorting Queries:

Queries are sorted in a specific order based on the block in which the left boundary (L) resides. If two queries are in the same block, they are sorted by their right boundary (R).
Processing Queries:

Mo's algorithm processes the queries by adjusting the current range to match the query's range using efficient additions and removals of elements. This is done to minimize redundant recalculations.
Handling Frequency:

The frequency of each element in the current range is tracked. When the range is extended or shrunk, the frequency of elements is updated accordingly, and the number of distinct elements is recalculated.
How to Run
Clone the repository:

bash
Copy code
git clone <repository-url>
cd <repository-directory>
Compile the program: Use the following command to compile the C program:

bash
Copy code
gcc main.c -o mo_algorithm
Run the program: After compiling, run the executable:

bash
Copy code
./mo_algorithm
Input:

First, input the number of elements in the array (n).
Then, enter the elements of the array.
Next, input the number of queries (q).
For each query, enter two integers, L and R, which represent the range [L, R] for the query (1-based indexing).
Example Usage
Input:
bash
Copy code
Enter number of elements in array: 5
1 2 1 3 4
Enter number of queries: 3
1 3
2 5
1 5
Output:
bash
Copy code
2
4
4
Explanation:
For the above example:

Query (1, 3) has 2 distinct elements: 1, 2.
Query (2, 5) has 4 distinct elements: 2, 1, 3, 4.
Query (1, 5) has 4 distinct elements: 1, 2, 3, 4.
Code Walkthrough
Key Structures and Functions:
Query structure:

Holds information about each query, including the range (L, R) and the index (idx).
mo_compare function:

Custom comparator used by qsort to sort queries based on the block of L and the value of R. This helps process queries in an optimal order.
add(int x) function:

Adds an element x to the current range, updates the frequency, and increases the count of distinct elements if necessary.
remove_element(int x) function:

Removes an element x from the current range, updates the frequency, and decreases the count of distinct elements if necessary.
main function:

Reads input, initializes variables, processes the queries using Mo's algorithm, and outputs the results.
Time Complexity
Time Complexity: O((n + q) * sqrt(n)), where n is the size of the array, and q is the number of queries. This is much faster than the naive O(n * q) approach, especially when q is large.
License
This project is licensed under the MIT License.
