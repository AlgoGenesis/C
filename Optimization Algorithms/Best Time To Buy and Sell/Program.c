#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {  
    int n = prices.size();
    int profit= 0;
     int bestBuy=prices[0];
  
    // Explore all possible ways to buy and sell stock
    for (int i = 1; i < n; i++) {
     if(prices[i]>bestBuy)
     {
            profit = max(profit, prices[i] - bestBuy);
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 4, 1, 3, 6, 9, 20};
    cout << maxProfit(prices) << endl;
    return 0;
}