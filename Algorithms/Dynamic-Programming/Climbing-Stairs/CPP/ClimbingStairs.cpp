/*
Algorithm:          Climbing Stairs (LeetCode Problem #70)

Task:               It takes n steps to reach the top of a staircase. Each time you can either climb up 1 or 2 steps. Return the number
                    of distinct ways the staircase can be climbed. The recursion relation of this problem is practically identical to
                    that of the Fibonacci algorithm.
                        F(n) = F(n-1) + F(n-2), for n > 2; let F(0) = 0 and F(1) = 1

Solution:           Let x be any number of steps in range 1 to n. Our goal is to find F(x) when x=n. First, we should find every value 
                    of F(x) for every possible value of x in range 1 to n-1; this should be done sequentially (i.e., find F(x) when x=1,
                    then F(x) when x=2, and so on, until we find F(x) when x=n-1). Then, to find F(x) when x=n, we can add the result
                    of F(x) when x=n-1 and F(x) when x=n-2.  

Time complexity:    O(N)
                        N = number of steps to reach the top of the staircase

Space complexity:   O(1)

Auxiliary space:    O(1)

Resources:          https://www.youtube.com/watch?v=Y0lT9Fck7qI
                    https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
*/


#include <iostream>
using std::cout;
using std::endl;

int climbStairs(int n) {
    // If n = 0, return 0.
    if (n <= 0)
        return 0;

    int oneStep = 1;            // Variable for F(x-1).
    int twoStep = 1;            // Variable for F(x-2).

    // Find every value of F(x) for every possible value of x in range 1 to n.
    for (int x = 1; x < n; x++)
    {

        int temp = oneStep;
        oneStep = oneStep + twoStep;        // Change oneStep from F(x-1) to F(x).
        twoStep = temp;                     // Change twoStep from F(x-2) to F(x-1).

        // In the next iteration, oneStep will change to F(x-1) and twoStep will change to F(x-2).
    }

    // oneStep will be F(n) - the number of distinct ways to climb the staircase.
    return oneStep;
}

/* climbStairs() when n = 5; 
    init  oneStep = 1; twoStep = 1      x = 1
    1.    oneStep = 2; twoStep = 1      x = 2
    2.    oneStep = 3; twoStep = 2      x = 3
    3.    oneStep = 5; twoStep = 3      x = 4
    4.    oneStep = 8; twoStep = 5      x = n = 5
    return 8
*/

int main() {
    // Test case 1.
    int n = 0;
    cout << "Number of ways to climb " << n << "-step staircase: " << climbStairs(n) << endl;

    // Test case 2.
    n = 2;
    cout << "Number of ways to climb " << n << "-step staircase: " << climbStairs(n) << endl;

    // Test case 2.
    n = 5;
    cout << "Number of ways to climb " << n << "-step staircase: " << climbStairs(n) << endl;

    return 0;
}