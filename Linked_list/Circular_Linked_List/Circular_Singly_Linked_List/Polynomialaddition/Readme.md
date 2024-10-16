# Polynomial Linked List Operations in C

## Overview
This project implements a polynomial using a circular linked list and provides functionalities to:
- Add two polynomials
- Evaluate a polynomial for given values of `x`, `y`, and `z`

## Features
1. **Polynomial Representation**: 
   - Each term in the polynomial is represented by a node in a circular linked list. 
   - Each node contains the coefficient and the powers of `x`, `y`, and `z`.
   
2. **Operations**:
   - **Addition of Polynomials**: The program can add two polynomials and return the resulting polynomial.
   - **Evaluation of a Polynomial**: For a given polynomial, the program can compute its value by substituting specific values for `x`, `y`, and `z`.

## How It Works
1. **Data Structure**:
   - Each term of the polynomial is stored in a `struct Node`, which contains:
     - `cf`: Coefficient of the term
     - `px`: Power of `x`
     - `py`: Power of `y`
     - `pz`: Power of `z`
     - `link`: Pointer to the next term (node) in the polynomial
     - `flag`: Used to track terms during polynomial addition
   
   The terms are organized in a circular linked list where the last node points back to the head.

2. **Functions**:
   - `getnode()`: Allocates memory for a new node.
   - `insert_rear()`: Inserts a new term at the end of the polynomial.
   - `read_poly()`: Reads terms from the user and constructs the polynomial.
   - `display()`: Prints the polynomial in human-readable form.
   - `add_poly()`: Adds two polynomials term by term.
   - `evaluate()`: Evaluates the polynomial for given values of `x`, `y`, and `z`.

## Compilation and Execution

### Compilation
To compile the program, use the following command in your terminal:
```bash
gcc polynomial_linked_list.c -o polynomial


