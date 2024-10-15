# Linked List Program in C

This is a simple C program that implements a singly linked list. The program allows you to:
- Insert new nodes with integer data at the end of the list.
- Print the linked list.
- Find and display the middle element of the linked list.

## How the Program Works

### Structure Definition
The program defines a `Node` structure that represents each element in the linked list. Each node contains:
- `data`: an integer value.
- `next`: a pointer to the next node in the list.

### Global Variables
- `head`: a pointer to the first node (head) of the linked list.
- `tail`: a pointer to the last node (tail) of the linked list.

### Functions
- **insert(int data)**: Inserts a new node with the given data at the end of the linked list.
- **printList()**: Prints the entire linked list in the format `data1 -> data2 -> ... -> NULL`.
- **middleelement()**: Finds and prints the middle element of the linked list using the slow and fast pointer approach.

## How to Use

1. Compile the program using a C compiler:
    ```bash
    gcc linkedlist.c -o linkedlist
    ```

2. Run the program:
    ```bash
    ./linkedlist
    ```

3. The program will prompt you to enter the number of nodes and the data for each node.

4. After entering the data, the program will:
    - Print the entire linked list.
    - Print the middle element of the linked list.

### Example

```bash
Enter the number of nodes: 5
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50

Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Middle Element: 30
