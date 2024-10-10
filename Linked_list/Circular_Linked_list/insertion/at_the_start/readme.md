# Circular Linked List - Insertion at the Beginning

This program contains an implementation of a **Circular Linked List** with the ability to **insert a node at the beginning** of the list.

## Node Structure

Each node in the singly linked list consists of two components:
1. **Data**: An integer value stored in the node.
2. **Next Pointer**: A reference to the next node in the linked list.

## Insertion at the Beginning

The `insertAtStart` function allows you to add a new node to the beginning of the circular linked list. The steps involved in this process are as follows:

1. **Memory Allocation**: Allocate memory for the new node.
2. **Data Assignment**: Assign the provided data to the new node.
3. **Check for Empty List**:
   - If the linked list is empty, new node becomes the head of the list and points to itself.
4. **Make the new node point to head**:
   - Traverse the nodes till end (pointer of temp points to head again) and update new node's next to head (1st element).
5. **Add the new node to the list**: Update temp's next to new node.
6. **Update the head**: Change the head to new node.

## Display the List

The `display` function traverses the linked list and prints the data of each node. It continues until the end of the list is reached (i.e., when the next pointer points to the `head` again after printing the complete list). The output format shows the data values of the nodes followed by an arrow, ending with `Back to head` to indicate the end of the list i.e., again pointing to the start of list (head).

## Full Example

The complete implementation demonstrates the following functionalities:
1. **Insertion**: Nodes can be added to the beginning of the list.
2. **Display**: The current state of the linked list can be displayed.

### Example Output

When running the program, the output will display the circular linked list after inserting nodes at the beginning. 

For example: 
Circular Linked List after insertions at the beginning:
10 -> 20 -> 30 -> 40 -> (Back to head)

