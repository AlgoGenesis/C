int query_segment_tree(int* seg_tree, int n, int left, int right) {
    // Query in the range [left, right)
    int result = 0;
    left += n;
    right += n;

    while (left < right) {
        if (left % 2 == 1) {
            result += seg_tree[left];
            left++;
        }
        if (right % 2 == 1) {
            right--;
            result += seg_tree[right];
        }
        left /= 2;
        right /= 2;
    }

    return result;
}
