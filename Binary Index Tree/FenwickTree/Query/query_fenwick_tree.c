int query_fenwick_tree(int* fenwick_tree, int index) {
    // Query sum from index 0 to the given index
    int result = 0;
    index += 1;

    while (index > 0) {
        result += fenwick_tree[index];
        index -= index & -index;  // Move to parent
    }

    return result;
}
