#include <stdio.h>

int is_power_of_two(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_power_of_two(num)) {
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }

    return 0;
}
