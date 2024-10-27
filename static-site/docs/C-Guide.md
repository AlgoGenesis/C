---
title: C Guide
sidebar_position: 2
---

# 🚀 C Programming Guide 

## Table of Contents
- [🌟  Basics](#basics)
- [🎯  Control Flow](#control-flow)
- [📦  Functions](#functions)
- [🗃️  Arrays & Strings](#arrays--strings)
- [📝  Pointers](#pointers)
- [🏗️  Structures & Unions](#structures--unions)
- [📂  File Handling](#file-handling)
- [🧰  Advanced Concepts](#advanced-concepts)

##  Basics
### 🔰 Introduction to C
- History and importance
- Features of C language
- Structure of a C program

### ⚙️ Setting Up Environment
- Installing C compiler (GCC)
- Setting up IDE/text editor
- Writing first program

### 📊 Variables & Data Types
```c
// Basic data types
int age = 25;         // Integer
float price = 99.99;  // Floating point
char grade = 'A';     // Character
double pi = 3.14159;  // Double precision float
```

### 🔢 Operators
- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Relational: `==`, `!=`, `>`, `<`, `>=`, `<=`
- Logical: `&&`, `||`, `!`
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`

##  Control Flow
### 🔄 Conditional Statements
```c
// if-else statement
if (age >= 18) {
    printf("You can vote!");
} else {
    printf("Too young to vote");
}

// switch statement
switch (grade) {
    case 'A': printf("Excellent");
              break;
    case 'B': printf("Good");
              break;
    default:  printf("Pass");
}
```

### 🔁 Loops
```c
// For loop
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// While loop
while (count > 0) {
    printf("Countdown: %d\n", count);
    count--;
}

// Do-while loop
do {
    printf("Enter number (0 to exit): ");
    scanf("%d", &num);
} while (num != 0);
```

##  Functions
### 📋 Function Declaration & Definition
```c
// Function declaration
int add(int a, int b);

// Function definition
int add(int a, int b) {
    return a + b;
}

// Function with void return
void greet(char name[]) {
    printf("Hello, %s!\n", name);
}
```

### 🔄 Recursion
```c
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

##  Arrays & Strings
### 📊 Arrays
```c
// One-dimensional array
int numbers[5] = {1, 2, 3, 4, 5};

// Two-dimensional array
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

### 📝 String Operations
```c
char str1[20] = "Hello";
char str2[20] = "World";

// String functions
strlen(str1);         // Length
strcpy(dest, src);    // Copy
strcat(str1, str2);   // Concatenation
strcmp(str1, str2);   // Comparison
```

##  Pointers
### 🎯 Pointer Basics
```c
int x = 10;
int *ptr = &x;    // Pointer declaration and initialization

printf("Value: %d\n", *ptr);     // Dereferencing
printf("Address: %p\n", (void*)ptr);  // Address
```

### 🔄 Dynamic Memory Allocation
```c
// Memory allocation
int *arr = (int*)malloc(5 * sizeof(int));
if (arr == NULL) {
    printf("Memory allocation failed!");
    return 1;
}

// Memory deallocation
free(arr);
```

##  Structures & Unions
### 🏗️ Structures
```c
struct Student {
    char name[50];
    int roll_no;
    float marks;
};

struct Student s1 = {"John", 101, 85.5};
```

### 🔄 Unions
```c
union Data {
    int i;
    float f;
    char str[20];
};
```

##  File Handling
### 📂 File Operations
```c
// File writing
FILE *file = fopen("data.txt", "w");
if (file != NULL) {
    fprintf(file, "Hello, File!");
    fclose(file);
}

// File reading
char buffer[100];
file = fopen("data.txt", "r");
if (file != NULL) {
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}
```

##  Advanced Concepts
### 🧰 Preprocessor Directives
```c
#define MAX 100
#define SQUARE(x) ((x) * (x))

#ifdef DEBUG
    printf("Debug mode\n");
#endif
```

### 🔧 Bit Manipulation
```c
// Bit operations
int a = 5;    // 101 in binary
int b = 3;    // 011 in binary

int and_result = a & b;   // Bitwise AND
int or_result = a | b;    // Bitwise OR
int xor_result = a ^ b;   // Bitwise XOR
int left_shift = a << 1;  // Left shift
int right_shift = a >> 1; // Right shift
```

### 💾 Memory Management
```c
// Memory alignment
#pragma pack(1)
struct PackedData {
    char c;    // 1 byte
    int i;     // 4 bytes
    double d;  // 8 bytes
};
```

## 🔍 Additional Resources
- [C Programming Language Specification](https://www.iso.org/standard/74528.html)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [C Standard Library Reference](https://en.cppreference.com/w/c)

## 🛠️ Practice Projects
1. Calculator Application
2. Student Management System
3. File Encryption/Decryption
4. Linked List Implementation
5. Simple Game Development

## 📝 Best Practices
1. Always initialize variables
2. Use meaningful variable names
3. Comment your code appropriately
4. Check return values of functions
5. Free allocated memory
6. Use const when applicable
7. Handle errors gracefully

## ⚠️ Common Pitfalls
1. Buffer overflows
2. Memory leaks
3. Undefined behavior
4. Integer overflow
5. Null pointer dereferencing

Remember to compile with warnings enabled:
```bash
gcc -Wall -Wextra -Werror program.c -o program
```

## 🎯 Next Steps
- Learn about standard libraries
- Practice with coding challenges
- Contribute to open source projects
- Explore related technologies (Make, CMake)
- Study design patterns in C

Happy Coding! 🚀