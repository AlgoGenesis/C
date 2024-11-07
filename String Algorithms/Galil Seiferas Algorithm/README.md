# **Galil-Seiferas Algorithm**

## **Description**

The **Galil-Seiferas Algorithm** is an efficient string matching algorithm designed to find all occurrences of a pattern in a given text. It improves upon the Knuth-Morris-Pratt (KMP) algorithm by optimizing the search process and avoiding redundant comparisons. The algorithm runs in linear time \( O(n + m) \), where \( n \) is the length of the text and \( m \) is the length of the pattern, making it highly efficient for string matching tasks.

### **Problem Definition**

Given:
- A **text** string and a **pattern** string.

Objective:
- Identify all occurrences of the **pattern** within the **text** string in linear time.

### **Algorithm Overview**

1. **Preprocessing the Pattern**:  
   - Compute the **Longest Prefix Suffix (LPS)** array for the pattern, which allows the algorithm to skip unnecessary comparisons when a mismatch occurs.

2. **Pattern Search**:  
   - Traverse the **text** string while comparing it with the **pattern**.  
   - On a match, print the starting index of the match.  
   - On a mismatch, use the LPS array to skip characters and resume the search from the optimal position.

3. **Optimization**:  
   - The Galil-Seiferas Algorithm ensures that no character in the text is scanned more than once, leading to an optimal linear-time solution.

### **Time Complexity**

- **Time Complexity**: \( O(n + m) \), where:
  - \( n \) is the length of the **text** string.
  - \( m \) is the length of the **pattern** string.

- **Space Complexity**: \( O(m) \) for storing the LPS array.

## **How to Run the Program**

### **Prerequisites**

- A C compiler, such as GCC.

### **Steps to Compile and Execute**

1. **Save the Program**:  
   Save the provided C code as `Program.c`.

2. **Compile the Program**:  
   Open your terminal and compile the program using the following command:
   ```bash
   gcc Program.c -o galil_seiferas
   ```

3. **Run the Program**:  
   After compilation, run the program:
   ```bash
   ./galil_seiferas
   ```

4. **Example Output**:  
   Given the input:
   ```plaintext
   Text: "galilseiferasalgorithmstringmatching"
   Pattern: "matching"
   ```
   The output will be:
   ```plaintext
   Pattern found at index 26
   ```

## **Usage**

The **Galil-Seiferas Algorithm** is widely used in applications requiring efficient string matching, such as:

- **Text search engines**
- **Bioinformatics** (e.g., DNA sequence matching)
- **Spell checkers**
- **Plagiarism detection systems**

## **Code Overview**

### **Functions**:

- **`computeLPSArray()`**:  
  Computes the **Longest Prefix Suffix (LPS)** array for the pattern, used to avoid redundant comparisons during mismatches.

- **`galilSeiferasSearch()`**:  
  Implements the actual pattern matching logic using the **Galil-Seiferas Algorithm**.

### **Input and Output**:

- **Input**:  
  A text string and a pattern string to search for.

- **Output**:  
  Prints the starting index of every match found in the text.