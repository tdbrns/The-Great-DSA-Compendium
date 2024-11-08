/*
Algorithm:          Min Cost Climbing Stairs using Memoization/Top-Down Approach (LeetCode Problem #746)

Task:               You are given an integer array "cost" where "cost[i]" is the cost of the ith step on a staircase. Once you pay the
                    cost, you can climb either one step or two steps. You can either start at the step with index 0 or the step with 
                    index 1. Return the minimum cost to reach the top of the staircase.

Solution:           The recurrence relation of this problem is reminiscent of the recurrence relation for the Fibonacci algorithm.
                        minCost(i) = cost[i] + min(cost[i-1], cost[i-2])
                    The minimum cost to reach the ith step is the sum of the cost of the ith step plus the cost of the cheapest step
                    between the (n-1)th step and the (n-2)th step. We can use this to find the minimum cost reqiured to reach the top
                    of the staircase, which is done by solving minCost(n) where n is the top of the staircase (a.k.a. the total number 
                    of steps). Note that the top of the staircase has no cost.
                    In this approach, we calculate the minimum cost to reach the top of the staircase by recursively calculating the
                    cost required to reach each of the steps below it until the results can be used to find the answer to our initial
                    problem. Each of the results are stored into a cache, which is used to prevent the function from calculating a
                    subproblem more than once.

Time complexity:    O(N); N = total number of steps in the staircase

Space complexity:   O(N); N = total number of steps in the staircase

Resources:          https://leetcode.com/problems/min-cost-climbing-stairs/solutions/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

unordered_map<int, int> cache;

int minCost(vector<int>& cost, int n)
{
    // Base case; If n < 0, return 0.
    if (n < 0)
        return 0;
    // Base case; if n == 0 or n == 1, return cost[n].
    if (n == 0 || n == 1)
        return cost[n];
    // Base case; if the result of the current subproblem is in cache, return cache[n].
    if (cache.find(n) != cache.end())
        return cache[n];
    
    // Recursively perform the recursion relation until the one of the base cases are met. Store the result in cache and return it.
    cache[n] = cost[n] + std::min(minCost(cost, n-1), minCost(cost, n-2));
    return cache[n];
}

// Wrapper for the recursive minCost() function.
int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();            // Size of the integer array (vector).
    return std::min(minCost(cost, n-1), minCost(cost, n-2));
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;
    
    cache.clear();
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;
    
    return 0;
}