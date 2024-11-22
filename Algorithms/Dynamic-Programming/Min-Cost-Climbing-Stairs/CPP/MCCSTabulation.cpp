/*
Algorithm:          Min Cost Climbing Stairs using Tabulation/Bottom-Up Approach (LeetCode Problem #746)

Task:               You are given an integer array "cost" where "cost[i]" is the cost of the ith step on a staircase. Once you pay the
                    cost, you can climb either one step or two steps. You can either start at the step with index 0 or the step with 
                    index 1. Return the minimum cost to reach the top of the staircase.

Solution:           The recurrence relation of this problem is reminiscent of the recurrence relation for the Fibonacci algorithm.
                        minCost(i) = cost[i] + min(cost[i-1], cost[i-2])
                    The minimum cost to reach the ith step is the sum of the cost of the ith step plus the cost of the cheapest step
                    between the (n-1)th step and the (n-2)th step. We can use this to find the minimum cost reqiured to reach the top
                    of the staircase, which is done by solving minCost(n) where n is the top of the staircase (a.k.a. the total number 
                    of steps). Note that the top of the staircase has no cost.
                    In this approach, we find the minimum cost to reach each step between the 0th and nth step in the staircase, store 
                    each result into a DP table, and return the lowest result between the last and second-to-last element in the table. 
                    This is considered a bottom-up approach because we start by calculating the minimum cost of the first step and use 
                    the result to calculate the minimum cost of the second step and so on, until we reach the nth step.

Time complexity:    O(N)
                        N = number of steps to climb to reach the top of the staircase

Space complexity:   O(N)
                        N = number of integers in cost

Auxiliary space:    O(N)
                        N = size of the 1-D DP table

Resources:          https://leetcode.com/problems/min-cost-climbing-stairs/solutions/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();            // Size of the integer array (vector).

    // If n <= 0, return 0.
    if (n <= 0)
        return 0;
    // If n == 1, return the only element in cost.
    if (n == 1)
        return cost[n-1];
    // If n == 2, return the smallest of the only two elements in cost.
    if (n == 2)
        return std::min(cost[n-1], cost[n-2]);
    
    // If n > 2...

    vector<int> dp(n);              // DP table of size n that holds the minimum cost to reach each step.

    // Iteratively perform the recursion relation to find the minimum cost to reach each step.
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            dp[i] = cost[i];        // Store the first two values in dp as they are.
        else
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
    }
    
    // Return the lowest result between the last and second-to-last element in dp.
    return std::min(dp[n-1], dp[n-2]);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;
    
    return 0;
}