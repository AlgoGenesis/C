void update_segment_tree(int* seg_tree, int n, int index, int value) {
    // Update the value at index and propagate the changes upwards
    index += n;
    seg_tree[index] = value;

    // Move upwards and update parents
    while (index > 1) {
        index /= 2;
        seg_tree[index] = seg_tree[2 * index] + seg_tree[2 * index + 1];
    }
}
