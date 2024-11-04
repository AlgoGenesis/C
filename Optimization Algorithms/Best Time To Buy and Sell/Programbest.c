#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0; // No profit can be made

    int minPrice = prices[0]; // Initialize minPrice to the first price
    int maxProfit = 0; // Initialize maxProfit to 0

    for (int i = 1; i < pricesSize; i++) {
        // Update minPrice if the current price is lower
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            // Calculate profit if we sell at the current price
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit; // Update maxProfit if the current profit is higher
            }
        }
    }

    return maxProfit; // Return the maximum profit found
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4}; // Example prices
    int size = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, size);
    printf("The maximum profit is: %d\n", result);

    return 0;
}