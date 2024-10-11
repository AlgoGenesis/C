## Best Time to Buy and Sell Stock

## Problem Description
The problem presents us with an array named prices that represents the price of a certain stock on each day. Our objective is to choose a single day for buying one stock and another future day for selling that stock in order to achieve the maximum possible profit. If it's not possible to make any profit, the expected return value is 0. This problem essentially asks us to find two days, where buying on the first and selling on the second would result in the highest profit margin.

##Solution Approach
The provided solution uses a simple yet effective approach that relies on a single pass through the prices array, a concept that is often referred to as the "One Pass" algorithm. This algorithm falls under the category of greedy algorithms since it makes a locally optimal choice at each step with the hope of finding a global optimum.

Here's a step-by-step walk-through of the implementation:

Initialize Variables: Two variables are initialized at the start. ans is initialized to 0 to represent the maximum profit which starts at no profit, and mi is set to inf, representing the minimum buying price (set to infinity since we have not encountered any price yet).

Iterate Over prices: We loop through each price v in the array prices, treating each one as a potential selling price.

Calculate Profit and Update Maximum Profit (ans): For each price v, if selling at this price leads to a profit higher than the best profit found so far (ans), the maximum profit is updated. This is done by computing the difference v - mi and using the max function: ans = max(ans, v - mi).

Update Minimum Buying Price (mi): After checking the potential profit at price v, update the minimum buying price if v is lower than all previously seen prices: mi = min(mi, v).

Return Maximum Profit: After finishing the traversal of the array prices, the variable ans holds the maximum profit that can be achieved. This value is returned as the solution to the problem.

##Example Walkthrough
Let's assume we have an array of stock prices for 5 consecutive days, represented as follows: prices = [7, 1, 5, 3, 6, 4].

Applying the solution approach step-by-step:

Initialize Variables: Set ans = 0 (maximum profit starts at no profit) and mi = inf (minimum buying price is initially set to infinity since no prices have been seen yet).

Iterate Over prices Day 1 (prices[0] = 7): Start with the first price. Since mi is set to infinity, any price we encounter will be lower, so we set mi = 7.

Day 2 (prices[1] = 1): Proceed to the next price.

Potential profit if we sell today: 1 - mi = 1 - 7 = -6. Since this is negative, no profit is made. We don't update ans.
Update mi since 1 is less than 7: mi = 1.

Day 3 (prices[2] = 5): Move on to the third price
Potential profit: 5 - mi = 5 - 1 = 4. This is a profit, and since ans is 0, it becomes the new maximum profit: ans = 4.
mi remains at 1, as 5 is higher than the current mi.

Day 4 (prices[3] = 3) 6. Day 5 (prices[4] = 6): Analyzing the fifth price.

Potential profit: 6 - mi = 6 - 1 = 5. This exceeds the current ans of 4, so we update ans = 5.
mi remains unchanged as 6 is higher than 1.

Day 4 (prices[3] = 3) 6. Day 5 (prices[4] = 6): Analyzing the fifth price.

Potential profit: 6 - mi = 6 - 1 = 5. This exceeds the current ans of 4, so we update ans = 5.
mi remains unchanged as 6 is higher than 1.

Day 6 (prices[5] = 4): Finally, the price on the last day.

Potential profit: 4 - mi = 4 - 1 = 3. This does not beat the current ans of 5, so ans stays at 5.
mi does not change, as 4 is higher than 1.

Return Maximum Profit: Having processed all days, we have found that the maximum profit is ans = 5, which is the highest profit achievable (by buying on day 2 at a price of 1 and selling on day 5 at a price of 6).

## Time and Space Complexity
The time complexity of the given function is O(n), where n is the length of the input list prices. This is because the function includes a single loop that iterates through each element in the list exactly once, performing a constant amount of work at each step; thus, the total work done is linear in the size of the input.

The space complexity of the function is O(1), indicating that the amount of additional memory used by the function does not depend on the size of the input.