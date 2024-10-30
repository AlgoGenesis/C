# Ukkonen's Algorithm

## Description

This repository provides a C implementation of **Ukkonen's Algorithm**, an efficient algorithm to construct a **suffix tree** in linear time \(O(n)\), where *n* is the length of the input string. A suffix tree is a compressed trie of all the suffixes of a given string, making it useful for various string operations such as pattern matching, longest common substring, and more.

### Suffix Tree Overview

A **suffix tree** is a special kind of data structure that represents all suffixes of a given string. It can be used to solve a variety of problems in linear time, including substring search, pattern matching, and more.

## Structures

1. **SuffixTree**:
   - A structure representing the suffix tree.
   - Members:
     - `struct Node* root`: Pointer to the root node of the tree.
     - `int size`: The number of unique characters in the input string.
     - `char* text`: The input string for which the suffix tree is built.

2. **Node**:
   - A structure representing a node in the suffix tree.
   - Members:
     - `struct Edge* edges`: Pointer to the list of edges from this node.
     - `int start`: The start index of the edge label in the original string.
     - `int* end`: Pointer to the end index of the edge label in the original string.

## Functions

1. **SuffixTree* createSuffixTree(char* text)**:
   - Creates and initializes a suffix tree for the given text.
   - Returns a pointer to the created suffix tree.

2. **void addSuffix(SuffixTree* tree, int start)**:
   - Adds a suffix starting from the given index to the suffix tree.

3. **void buildSuffixTree(SuffixTree* tree)**:
   - Constructs the suffix tree using Ukkonen's Algorithm.

4. **void printSuffixTree(SuffixTree* tree)**:
   - Prints the structure of the suffix tree for visualization.

## Main Function

- Prompts the user for input string.
- Calls `createSuffixTree` to build the suffix tree.
- Displays the constructed suffix tree using `printSuffixTree`.

## Time Complexity

- The algorithm runs in \(O(n)\), where \(n\) is the length of the input string.

## Example

### input
Enter text: banana

### Output

Suffix Tree for 'banana':
banana [leaf: 0]
a [internal]
na [leaf: 1]
nana [leaf: 2]
ana [internal]
na [leaf: 3]
nana [leaf: 4]
a [leaf: 5]
