# Longest String Chain (Dynamic Programming)

## Overview

The **Longest String Chain** problem is a dynamic programming-based problem where we are given a list of strings, and we need to find the longest possible chain of strings such that each string in the chain can be formed by adding one character to the previous string in the chain.

### Problem Statement

You are given an array of words. A word chain is a sequence of words such that every word except the first one can be formed by inserting a single character into the previous word. Your task is to find the length of the longest possible word chain.

### Example

**Input:**

```plaintext
words[] = {"a", "b", "ba", "bca", "bda", "bdca"}
