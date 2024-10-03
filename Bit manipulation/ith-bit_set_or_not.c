#include <stdio.h>

void check_ith_bit_set(int num, int i) {
    if (num & (1 << i)) {
        printf("The %d-th bit is set.\n", i);
    } else {
        printf("The %d-th bit is not set.\n", i);
    }
}

int main() {
    int num, i;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the bit position (0-indexed): ");
    scanf("%d", &i);

    check_ith_bit_set(num, i);
    return 0;
}
