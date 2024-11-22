/*
Algorithm:          Best Time to Buy and Sell Stock (LeetCode Problem #121)

Task:               You are given an array "prices" where "prices[i]" is the price of a given stock on the ith day. You want to maximize 
                    your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
                    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Solution:           Iterate through each price in "prices" and keep track of the lowest price and the highest profit that is calculated 
                    with each iteration. Then return the maximum profit that was calculated after each price has been processed. Note 
                    that buying a stock at its lowest price in "prices" does not always guarantee that it can be sold for the highest 
                    profit on a subsequent day. Due to this, we must keep track of previously calculated profits to compare them to
                    subsequently calculated profits and ensure that the largest possible profit is returned, regardless of the price of
                    the stock when it was bought.

Time complexity:    O(N)
                        N = number of integers in prices

Space complexity:   O(N)
                        N = numver of integers in prices

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

int maxProfit(vector<int>& prices) 
{
    int minPrice = INT_MAX;     // Current minimum price for buying a stock.
    int maxProfit = 0;          // Current maximum profit for selling a stock. Calculated by solving prices[i] - minPrice.

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);                // Keep track of the current lowest price to buy the stock.
        maxProfit = max(maxProfit, prices[i] - minPrice);   // Keep track of the current highest profit for selling the stock.
    }

    return maxProfit;
}
/* maxProfit when prices = {7, 1, 5, 3, 0, 2}
    init.   maxProfit = 0;  minPrice = INT_MAX
    1.      prices[i] = 7  minPrice = min(INT_MAX, 7) = 7  maxProfit = max(0, 7 - 7) = 0
    2.      prices[i] = 1  minPrice = min(7, 1) = 1        maxProfit = max(0, 1 - 1) = 0
    3.      prices[i] = 5  minPrice = min(1, 5) = 1        maxProfit = max(1, 5 - 1) = 4
    4.      prices[i] = 3  minPrice = min(1, 3) = 1        maxProfit = max(4, 3 - 1) = 4
    5.      prices[i] = 0  minPrice = min(1, 0) = 0        maxProfit = max(4, 0 - 0) = 4
    6.      prices[i] = 2  minPrice = min(0, 2) = 0        maxProfit = max(4, 2 - 0) = 4
    return 4
*/

int main()
{
    vector<int> prices = {7, 1, 5, 3, 0, 2};
    cout << "Maximum profit: " << maxProfit(prices) << endl;

    prices = {7, 6, 4, 3, 2};
    cout << "Maximum profit: " << maxProfit(prices);
    return 0;
}