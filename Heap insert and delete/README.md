### Max-Heap Implementation
This C program demonstrates the basic operations of a Max-Heap data structure, including insertion, deletion of the root node, and displaying the heap elements.

In a Max-Heap, each parent node is greater than or equal to its child nodes, which means the root node always contains the maximum element. The program provides a menu-driven approach to insert elements into the heap, delete the root node, and display the heap structure.

### Key Operations:
- **Insert into Heap:** Inserts an element into the heap and maintains the Max-Heap property by reordering the elements appropriately using a bottom-up approach (heapify up).      
- **Delete Root:** Deletes the root element (which is the maximum element) and maintains the Max-Heap property by reordering the heap using a top-down approach (heapify down).       
- **Display Heap:** Prints the current elements of the heap.
### Sample Input and Output 
***MAIN MENU***
1. INSERT
2. DELETE
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter the item to be inserted in the heap: 30

***MAIN MENU***
1. INSERT
2. DELETE
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter the item to be inserted in the heap: 50

***MAIN MENU***
1. INSERT
2. DELETE
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter the item to be inserted in the heap: 20
The heap is: 50 30 20

***MAIN MENU***
1. INSERT
2. DELETE
3. DISPLAY
4. EXIT
Enter your choice: 2
Root node deleted
The heap is: 30 20

### Time Complexity:
- **Insertion:** Inserting a new element involves adding it at the last position and heapifying up. This takes O(log n) because the height of the heap is log n.
- **Deletion (Root)**: Deleting the root involves moving the last element to the root and heapifying down. This also takes O(log n).
- **Display:** Displaying the heap involves printing all elements, which takes O(n).

