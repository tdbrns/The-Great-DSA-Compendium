/*
Algorithm:          Greatest Common Divisor (LeetCode Problem #1979)
Task:               Given an array of integers, return the greatest common divisor of the largest and smallest integer in the array.
Solution:           Use the Euclidean algorithm to find the greatest common divisor. The algorithm is based on the principle that the
                    greatest common divisor of two numbers does not change if the larger number (a) is replaced by its difference with 
                    the smaller number (b). In this solution, we use the Euclidean algorithm with division which involves replacing a
                    with b and replacing b with the remainder of a divided by b; this process is repeated until b equals 0, which
                    indicates that the value of a is the greatest common divisor.
Time Complexity:    O(log(max(A, B))); A = the larger number, B = the smaller number.
Space Complexity    O(N); N = size of the integer array.
Resources:          https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

int GCD(int a, int b)
{
    // Base case; if b equals 0, then the GCD is a.
    if (b == 0)
        return a;
    
    // Recursively call GCD with b as the larger number and (a mod b) as the smaller number.
    return GCD(b, a % b);
}
/* GCD() when a = 252 and b = 105
    init.   a = 252, b = 105
    1.      a = 105, b = 252 % 105 = 42
    2.      a = 42, b = 105 % 42 = 21
    3.      a = 21, b = 42 % 21 = 0
    return 21
*/

// Wrapper for GCD().
int findGCD(vector<int>& nums)
{
    int min = *std::min_element(nums.begin(), nums.end());      // Lowest integer in nums.
    int max = *std::max_element(nums.begin(), nums.end());      // Highest integer in nums.
    return GCD(max, min);
}

int main()
{
    vector<int> nums = {4, 5, 6, 9, 10};
    cout << "Greatest Common Divisor: " << findGCD(nums);
    cout << endl;

    nums = {105, 132, 155, 205, 252};
    cout << "Greatest Common Divisor: " << findGCD(nums);
    cout << endl;

    return 0;
}