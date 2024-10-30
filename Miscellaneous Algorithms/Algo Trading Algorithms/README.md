
# Algorithmic Trading Strategies in C

This repository contains implementations of algorithmic trading strategies in C, starting with the **Simple Moving Average (SMA)** strategy.

## How Does It Work?

### Simple Moving Average (SMA) Strategy
The **Simple Moving Average (SMA)** is a basic technical analysis tool used to smooth out price data by creating a constantly updated average price. The SMA is calculated by taking the average of a specified number of past price data points. Traders use this to identify trends and make buy or sell decisions based on price movements.

#### Example:
For a 5-day SMA, the average of the past 5 days' prices is calculated, and as new data comes in, the oldest data point is replaced by the newest, creating a rolling average.

**How to Use**:
1. Input an array of price data (e.g., daily stock prices).
2. Specify the period (e.g., 5 for a 5-day SMA).
3. The program computes the moving average for the specified period and displays the results.

```c
// Example of calculating a 5-day SMA in C
double prices[] = {100, 102, 101, 104, 107, 110, 108};
int period = 5;
```

Future strategies like the **Exponential Moving Average (EMA)** and **Bollinger Bands** will be added to expand this project.
