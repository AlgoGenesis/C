void updateFenwickTree(int fenwick[], int n, int index, int value) {
    index += 1;  // Fenwick Tree is 1-indexed

    while (index <= n) {
        fenwick[index] += value;
        index += index & -index;
    }
}
