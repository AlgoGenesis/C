#include <stdio.h>
int a[50], n = 0, i, value, temp, parent;
int insertheap(int a[], int n, int value) {
    n = n + 1;
    a[n] = value;
    i = n;
    while (i > 1) {
        parent = i / 2;
        if (a[parent] < a[i]) {
            temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;
            i = parent;
        } else {
            return n;
        }
    }
    return n;
}
int delete_root(int a[], int n) {
    if (n == 0) {
        printf("Heap is empty. Cannot delete from an empty heap.\n");
        return n;
    }
    int left, right, ptr, last, temp;
    last = a[n];
    n = n - 1;
    ptr = 1;
    left = 2;
    right = 3;
    a[ptr] = last;
    while (left <= n) {
        if (a[ptr] >= a[left] && a[ptr] >= a[right])
            return n;

        if (a[right] <= a[left]) {
            temp = a[ptr];
            a[ptr] = a[left];
            a[left] = temp;
            ptr = left;
        } else {
            temp = a[ptr];
            a[ptr] = a[right];
            a[right] = temp;
            ptr = right;
        }
        left = 2 * ptr;
        right = 2 * ptr + 1;
    }
    printf("Root node deleted\n");
    return n;
}
int main() {
    int choice, j;
    do {
        printf("\n***MAIN MENU***");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted in the heap:");
                scanf("%d", &value);
                n = insertheap(a, n, value);
                break;
            case 2:
                n = delete_root(a, n);
                break;
            case 3:
                if (n == 0) {
                    printf("Heap is empty.\n");
                } else {
                    printf("The heap is:");
                    for (j = 1; j <= n; j++)
                        printf(" %d", a[j]);
                    printf("\n");
                }
                break;
            case 4:
                break;
        }
    } while (choice != 4);
    return 0;
}
