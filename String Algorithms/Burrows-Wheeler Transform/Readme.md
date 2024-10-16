# Burrows-Wheeler Transform

## Description

This repository provides a C implementation of the **Burrows-Wheeler Transform (BWT)**, a data transformation technique that is useful for data compression and text processing. The BWT rearranges the characters of a string into runs of similar characters, which can then be compressed more efficiently.

## Overview

The BWT is a reversible transformation that can be applied to a string, and it is commonly used in conjunction with other algorithms such as Move-to-Front and Huffman coding. The main advantage of the BWT is that it makes the resulting string more amenable to compression.

## How It Works

The BWT works by generating all rotations of the input string, sorting these rotations, and then extracting the last column of the sorted rotations. This transformation is reversible, allowing for the original string to be reconstructed.

## Structures

1. **BWTResult**:
   - A structure to hold the result of the Burrows-Wheeler Transform.
   - Members:
     - `char* transformed`: The BWT-transformed string.
     - `int* original_indices`: Array holding the original indices of characters.

## Functions

1. **`void burrows_wheeler_transform(char* input, BWTResult* result)`**:
   - Performs the Burrows-Wheeler Transform on the input string and stores the result.

2. **`void inverse_burrows_wheeler_transform(BWTResult* result, char* output)`**:
   - Reverses the Burrows-Wheeler Transform to retrieve the original string.

3. **`void print_bwt_result(BWTResult* result)`**:
   - Prints the transformed string and original indices for verification.

## Example

### Input

Enter text: banana

### output

Transformed: annb$aa
Original Indices: 5 0 3 1 4 2 
Reconstructed: banana


