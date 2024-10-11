#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int amt;
    int price;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->price / itemA->amt;
    double ratioB = (double)itemB->price / itemB->amt;
    return (ratioA < ratioB) - (ratioA > ratioB); // Sorting in descending order
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        printf("Enter amount and price for item %d: ", i + 1);
        scanf("%d %d", &items[i].amt, &items[i].price);
    }

    double knapsack;
    printf("Enter capacity: ");
    scanf("%lf", &knapsack);

    qsort(items, n, sizeof(Item), compare);

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (knapsack >= items[i].amt) {
            ans += items[i].price;
            knapsack -= items[i].amt;
        } else {
            double vw = (double)items[i].price / items[i].amt;
            ans += vw * knapsack;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", ans);
    free(items);
    return 0;
}
