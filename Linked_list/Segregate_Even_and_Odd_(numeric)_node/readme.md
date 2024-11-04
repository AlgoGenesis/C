# Segregate Even and Odd Nodes in a Linked List

This project provides a C program to segregate even and odd nodes in a singly linked list. The program separates all even nodes and moves them to the beginning of the list while retaining the relative order of the odd nodes that follow. 

## Code Structure

1. **Node Structure**
   - Each node has:
     - `data`: Stores the integer value of the node.
     - `next`: Pointer to the next node in the list.

2. **Functions**
   - `newNode`: Creates a new node with a specified integer value.
   - `segregateEvenOdd`: Segregates even and odd nodes in the list, placing all even nodes at the start of the list followed by the odd nodes. Returns the head of the modified list.
   - `printList`: Prints the entire linked list.
   - `insertAtEnd` : Inserts the Linked list node at the end of the list.
     
3. **Main Function**
   - Creates a sample linked list and displays it.
   - Calls `segregateEvenOdd` to segregate even and odd nodes.
   - Displays the modified list.

## Usage

To compile and run the code, use the following commands:

```bash
gcc segregate_even_odd.c -o segregate_even_odd
./segregate_even_odd

```
## Example Output

The program will output the original list and the modified list with even nodes first:

- Original Linked list:  1 4 6 9 10 11 
- Modified Linked list:  4 6 10 1 9 11 
