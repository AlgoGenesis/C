# Interpolation Search

Interpolation Search is an algorithm for finding the position of a target value within a sorted array. It improves upon binary search by estimating the position based on the value of the target.

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)

## Introduction

Interpolation search is an improvement over binary search for instances where the values are uniformly distributed. The algorithm calculates the probable position of the target value and narrows down the search range accordingly.

## How It Works

1. **Start with a sorted array** and determine the low and high bounds.
2. Calculate the probe position using the formula:

   \[
   \text{pos} = \text{low} + \left( \frac{(\text{target} - \text{array}[low]) \times (high - low)}{(\text{array}[high] - \text{array}[low])} \right)
   \]

3. If the target value is found at the probe position, return the index.
4. If the target is less than the value at the probe position, narrow the search to the lower half.
5. If the target is greater, narrow the search to the upper half.
6. Repeat until the target is found or the bounds converge.