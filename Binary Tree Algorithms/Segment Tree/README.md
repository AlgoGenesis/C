### What is a Segment Tree for Maximum Range Queries?

A Segment Tree is a data structure that enables efficient querying of an array, particularly useful for answering range queries (such as finding the maximum, minimum, or sum over a specific range) in logarithmic time. Segment trees are built to preprocess and store data about segments of the array, allowing for quick queries and updates. This program uses a segment tree to find the maximum value in any specified range and to update individual elements efficiently.

### How does building the Segment Tree work?

Building the segment tree involves recursively dividing the array into smaller segments and calculating the maximum value for each segment. The leaf nodes of the tree represent individual elements of the array, while internal nodes store the maximum of their respective segments.
Start by initializing a segment tree array with size approximately 4 \* N (where N is the size of the input array).
For each segment, store the maximum value based on its left and right child nodes.
Continue until the segment tree is fully constructed with all segment maxima in place.

### How does querying the Segment Tree work?

Querying the segment tree to find the maximum in a specific range [l, r] involves comparing the required range with the current segment at each step:
If the current segment is completely within [l, r], return the maximum stored in this segment.
If the current segment is entirely outside [l, r], return a minimum value (such as INT_MIN).
For segments that partially overlap [l, r], recursively query the left and right child nodes and return the maximum of their results.

### How does updating an element in the Segment Tree work?

Updating an element in the segment tree requires finding the leaf node corresponding to the element’s index and updating it with the new value. The maximum values of affected segments are then updated accordingly.
Traverse down to the leaf node where the element resides.
Update the value at this leaf node.
Recursively update the maximum values in parent nodes to reflect the new change.

### What is the time complexity of these operations?

The segment tree enables efficient updates and range queries:

- Building the Tree: O(N), where N is the number of elements in the array.
- Range Query (Max Query): O(log N), due to logarithmic tree height.
- Update Operation: O(log N), as it affects only the path from the leaf to the root.
