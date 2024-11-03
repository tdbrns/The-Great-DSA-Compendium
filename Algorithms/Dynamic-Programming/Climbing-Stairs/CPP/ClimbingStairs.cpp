/*
Algorithm:          Climbing Stairs using Tabulation (LeetCode Problem #70)
Task:               It takes n steps to reach the top of a staircase. Each time you can either climb up 1 or 2 steps. Return the number
                    of distinct ways the staircase can be climbed.
Solution:           Let x = the number of stairs in the staircase, where 1 <= x <= n. For every value of x in range 1 to n, find the 
                    number of ways to climb a staircase with x stairs. The number of ways to climb a staircase when x equals n depends 
                    on the results produced for every previous value of x.
Time complexity:    O(N); N = number of steps in the staircase
Space complexity:   o(1)
Resources:          https://www.youtube.com/watch?v=Y0lT9Fck7qI
                    https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
*/

#include <iostream>
using std::cout;

int countSteps(int n)
{
    int oneStep = 1;            // Number of 1-step moves taken to climb the staricase.
    int twoStep = 1;            // Number of 2-step moves taken to climb the staircase.

    // Use a bottom-up approach to find the number of ways to climb a staircase with x stairs for every value of x.
    for (int x = 1; x < n; x++)
    {
        int temp = oneStep;           // Store the current value of the step one up from the current.
        oneStep = oneStep + twoStep;
        twoStep = temp;
    }
    return oneStep;
}
/* countSteps() when n = 5; 
    init  oneStep = 1; twoStep = 1      n = 1
    1.    oneStep = 2; twoStep = 1      n = 2
    2.    oneStep = 3; twoStep = 2      n = 3
    3.    oneStep = 5; twoStep = 3      n = 4
    4.    oneStep = 8; twoStep = 5      n = 5
    return 8
*/

int main()
{
    int n = 5;
    cout << "Number of ways: " << countSteps(n);

    return 0;
}