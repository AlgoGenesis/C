#include <stdio.h>

// Function to calculate the SMA
void calculateSMA(double prices[], int n, int period) {
    double sum = 0.0;
    double sma[n];  // Array to store SMA values
    
    // Calculate the first SMA value
    for (int i = 0; i < period; i++) {
        sum += prices[i];
    }
    sma[period - 1] = sum / period;
    
    // Calculate the remaining SMA values
    for (int i = period; i < n; i++) {
        sum = sum - prices[i - period] + prices[i];
        sma[i] = sum / period;
    }
    
    // Print the SMA values
    printf("SMA values: \n");
    for (int i = period - 1; i < n; i++) {
        printf("%lf\n", sma[i]);
    }
}

int main() {
    int n = 7;
    int period = 5;  // 5-day SMA
    
    // Example price data
    double prices[] = {100, 102, 101, 104, 107, 110, 108};
    
    // Calculate and display the 5-day SMA
    calculateSMA(prices, n, period);
    
    return 0;
}
