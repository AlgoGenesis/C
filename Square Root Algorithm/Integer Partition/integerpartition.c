#include <stdio.h>

void printPartition(int arr[], int length) {
    if(length<=0){
        printf("No partition exist");
    }
    for (int i = 0; i < length; i++) {
        if (i != 0) printf(" + ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void integerPartitions(int n, int max, int arr[], int index) {
    if (n == 0) {
        printPartition(arr, index);
        return;
    }

    for (int i = (n < max ? n : max); i >= 1; i--) {
        arr[index] = i;
        integerPartitions(n - i, i, arr, index + 1);
    }
}

void generatePartitions(int n) {
    int arr[n]; // Array to store partitions
    integerPartitions(n, n, arr, 0);
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Integer partitions of %d:\n", n);
    generatePartitions(n);

    return 0;
}
