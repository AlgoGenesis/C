# Lempel-Ziv-Welch (LZW) Compression Algorithm

## Description

This program implements the **Lempel-Ziv-Welch (LZW)** compression algorithm, a lossless data compression technique. It compresses an input string by replacing repeated patterns with shorter codes using a dynamically built dictionary.

The program reads a string from the user, compresses it using the LZW algorithm, and outputs the corresponding compressed sequence of dictionary indices.

## Structures

1. **DictionaryEntry**:
   - A structure to represent an entry in the LZW dictionary.
   - Members:
     - `char *string`: The string associated with the dictionary entry.

## Functions

### 1. `void initDictionary(DictionaryEntry *dictionary)`

- **Description**: Initializes the dictionary with single-character ASCII strings (values 0–255).
- **Parameters**:
  - `dictionary[]`: An array of `DictionaryEntry` structures representing the dictionary.

### 2. `int searchDictionary(DictionaryEntry *dictionary, int dictSize, char *str)`

- **Description**: Searches for a string in the dictionary and returns its index. If the string is not found, it returns `-1`.
- **Parameters**:
  - `dictionary[]`: The dictionary array to search in.
  - `dictSize`: The current size of the dictionary.
  - `str`: The string to search for in the dictionary.
- **Returns**: The index of the string in the dictionary or `-1` if not found.

### 3. `void LZWCompress(char *input)`

- **Description**: Compresses the input string using the LZW algorithm and outputs the compressed sequence of dictionary indices.
- **Parameters**:
  - `input`: The string to be compressed.

## Main Function

### Details:

- Prompts the user to input a string for compression.
- Initializes the dictionary with all ASCII characters.
- Processes the input string character by character, adding new patterns to the dictionary as needed.
- Outputs the compressed sequence of dictionary indices.
- Frees dynamically allocated memory used by the dictionary entries.

## Memory Management

- The dictionary dynamically grows as new strings are added.
- Dynamically allocated memory for the dictionary entries is released before the program exits.

## Time Complexity

- **Initialization**: Initializing the dictionary takes constant time, \(O(256)\), for the ASCII character set.
- **Compression**:
  - The time complexity of searching the dictionary is \(O(n)\), where \(n\) is the size of the dictionary.
  - For each character in the input string, the program performs a search and potentially adds a new dictionary entry, resulting in a total time complexity of \(O(m \times n)\), where \(m\) is the length of the input string, and \(n\) is the size of the dictionary at a given point.

## Example

### Input:
Enter the string to compress: ABABABA
### Output
Compressed Output: 65 66 256 258
