# Binary Search #

**Binary Search** is an efficient algorithm for finding an item from sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

The main idea of binary search is to keep track of the current range of reasonable guesses.

Let's say that I'm thinking of a number between 1 and 100. If you've already guessed 25, and I told you my number was higher, and you've already guessed 81 and I told you my number was lower, then the number in the range from 26 to 80 are the only reasonable guesses.

In each turn, you choose a guess that divide the set of reasonable guesses into two ranges of roughly the same size. If your guess is not correct, then I tell you whether it's too high or too low, and you can eliminate about half of the reasonable guesses.

## Time Complexity ##

- **Best Case O(1)**
- **Worst and Average O(log n)**
  If we had 16 elements in an array we would perform 4 steps to find the solution log2(16) = 4 , if we had 32 we will perform 5 steps to find the solution log2(32) = 5

## Algorithm ##

- Function accepts a sorted array, and a value
- Create a _beg_ variable for indexing the start of the array and _end_ variable for indexing the end of the array
- While the _beg_ variable before the _end_ variable
  - Create a variable which points to the middle
  - If you find the value you want, return index
  - If the value is too small, move the left pointer up
  - If the value is too large, move the right pointer down
- If you never find the value, return -1