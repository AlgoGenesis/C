
# Project Title
Suffix tree


## Problem Description

This C implementation constructs a suffix tree for a given input string. A suffix tree is a data structure that represents all suffixes of a string in a compact and efficient manner. It has various applications in pattern matching, text indexing, and bioinformatics.
## Input
The program expects a single string as input.
Input :  banana

## Output
The program will print the constructed suffix tree in a human-readable format, showing each node's start and end indices.

Output :
0-5
  1-5
    2-5
      3-5
        4-5
          5-5

## Algorithm
The implementation uses Ukkonen's online suffix tree construction algorithm, which is an efficient and space-efficient method for building suffix trees.
## Key Features
Efficiency: The algorithm is optimized for performance.
Clarity: The code is well-structured and commented for readability.
Flexibility: The code can be easily adapted for different applications.
## Notes

The code assumes that the input string contains only ASCII characters.
For larger strings, consider using a more efficient data structure for representing the suffix tree nodes and edges.
The code can be extended to support additional features such as pattern matching and longest common substring finding.
## License

This code is released under the MIT License.