# **Maximal Shift Algorithm**

## **Description**

The **Maximal Shift Algorithm** is a string matching algorithm used to efficiently find all occurrences of a pattern in a given text. This algorithm leverages a preprocessing step where it computes a **shift array**, allowing the search to skip over sections of the text during mismatches. It is similar to the Knuth-Morris-Pratt (KMP) algorithm but is optimized for cases where large shifts are required. The **Maximal Shift Algorithm** runs in linear time \( O(n + m) \), where \( n \) is the length of the text and \( m \) is the length of the pattern.

### **Problem Definition**

Given:
- A **text** string and a **pattern** string.

Objective:
- Efficiently find all occurrences of the **pattern** within the **text** using the **Maximal Shift Algorithm**.

### **Algorithm Overview**

1. **Compute the Maximal Shift Array**:  
   - Precompute a shift array for the pattern, where each position indicates how far the algorithm can safely shift the pattern without rechecking previously matched characters.

2. **Pattern Search**:  
   - Traverse through the text and compare it with the pattern.  
   - If a mismatch occurs, use the precomputed **shift array** to skip over unnecessary comparisons, effectively shifting the pattern forward.

3. **Optimal Shifting**:  
   - The algorithm ensures that no character in the text is checked more than once, leading to an optimal \( O(n + m) \) time complexity.

### **Time Complexity**

- **Time Complexity**: \( O(n + m) \), where:
  - \( n \) is the length of the **text**.
  - \( m \) is the length of the **pattern**.

- **Space Complexity**: \( O(m) \) for storing the shift array.

## **How to Run the Program**

### **Prerequisites**

- A C compiler such as GCC.

### **Steps to Compile and Execute**

1. **Save the Program**:  
   Save the provided C code as `Program.c`.

2. **Compile the Program**:  
   Open your terminal and compile the program using the following command:
   ```bash
   gcc Program.c -o maximal_shift
   ```

3. **Run the Program**:  
   After compilation, execute the program using:
   ```bash
   ./maximal_shift
   ```

4. **Example Output**:  
   Given the input:
   ```plaintext
   Text: "maximalshiftalgorithmstringmatching"
   Pattern: "algorithm"
   ```
   The output will be:
   ```plaintext
   Pattern found at index 12
   ```

## **Usage**

The **Maximal Shift Algorithm** is suitable for applications where pattern matching is required, such as:

- **Text search engines**
- **Pattern detection in large datasets**
- **Plagiarism detection**
- **Bioinformatics** (e.g., DNA sequence alignment)

## **Code Overview**

### **Functions**:

- **`computeMaximalShiftArray()`**:  
  Computes the **Maximal Shift Array** for the pattern, allowing the algorithm to efficiently skip sections of the text during mismatches.

- **`maximalShiftSearch()`**:  
  Implements the search process using the **Maximal Shift Algorithm**, comparing the pattern against the text.

### **Input and Output**:

- **Input**:  
  A **text** string and a **pattern** string to search for.

- **Output**:  
  Prints the starting index of each occurrence of the pattern in the text.
