/*
Algorithm:          Min Cost Climbing Stairs using Iterative Approach (LeetCode Problem #746)

Task:               You are given an integer array "cost" where "cost[i]" is the cost of the ith step on a staircase. Once you pay the
                    cost, you can climb either one step or two steps. You can either start at the step with index 0 or the step with 
                    index 1. Return the minimum cost to reach the top of the staircase.

Solution:           The recurrence relation of this problem is reminiscent of the recurrence relation for the Fibonacci algorithm.
                        minCost(i) = cost[i] + min(cost[i-1], cost[i-2])
                    The minimum cost to reach the ith step is the sum of the cost of the ith step plus the cost of the cheapest step
                    between the (n-1)th step and the (n-2)th step. We can use this to find the minimum cost reqiured to reach the top
                    of the staircase, which is done by solving minCost(n) where n is the top of the staircase (a.k.a. the total number 
                    of steps). Note that the top of the staircase has no cost.
                    In this approach, we iteratively calculate the minimum cost to reach each step between the 0th and nth step in the 
                    staircase and return the cheapest step between the (n-2)th and (n-1)th step. This is done by using two variables 
                    to temporarily store the result of each subproblem.

Time complexity:    O(N); N = total number of steps in the staircase

Space complexity:   O(1)

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
    
    int oneStep = cost[0];      // Cost to climb one step.
    int twoStep = cost[1];      // Cost to climb two steps.

    // Iteratively perform the recursion relation to find the minimum cost to reach each step.
    for (int i = 2; i < n; i++)
    {
        int temp = cost[i] + std::min(oneStep, twoStep);
        oneStep = twoStep;
        twoStep = temp;
    }
    
    // Return the cheapest step between the (n-2)th step and the (n-1)th step.
    return std::min(oneStep, twoStep);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;
    
    return 0;
}