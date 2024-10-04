#include <stdio.h>

int is_ith_bit_set(int num, int i) {
    return (num & (1 << i)) != 0;
}

int main() {
    int num, i;

  
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the bit position to check (0-indexed): ");
    scanf("%d", &i);

    if (is_ith_bit_set(num, i)) {
        printf("The %d-th bit is set.\n", i);
    } else {
        printf("The %d-th bit is not set.\n", i);
    }

    return 0;
}
