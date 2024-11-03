/*
Algorithm:          Maximum Subarray Sum (LeetCode Problem #53)
Task:               Given an integer array, find the subarray with the largest sum and return the sum.
Solution:           Basically, we must find the "maximum subarray" of the given array, which is the subarray of whose elements, when 
                    added together, give the largest sum of any other subarray. This is done using Kadane's algorithm.
Time complexity:    O(N); N = size of the integer array
Space complexity:   O(1)
Resources:          https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::max;

int maxSubarraySum (vector<int>& arr)
{
    // result and maxValue are intitialized with the element arr[0]
    int result = arr[0];        // Sum of the maximum subarray in arr[], initialized with arr[0]
    int maxValue = arr[0];      // Largest value between the sum of the current subarray and element arr[i], initialized with arr[0].

    for (int i = 1; i < arr.size(); i++) 
    {
        maxValue = max(maxValue + arr[i], arr[i]);
        result = max(maxValue, result);
    }

    return result;
}

/* maxSubarraySum() when arr = {3, 2, -1, 7, -8, 3, 2}:
    init.   maxValue = 2; result = 2
    1.      arr[i] = 3; maxValue = 2+3 = 5; result = 5
    2.      arr[i] = -8; maxValue = 5+(-8) = -3; result = 5
    3.      arr[i] = 7; maxValue = (-3)+7 = 4; result = 7  <- (maxValue + arr[i]) < arr[i]; start new subarray with 7 as 1st element
    4.      arr[i] = -1; maxValue = 7+(-1) = 6; result = 7
    5.      arr[i] = 2; maxValue = 6+2 = 8; result = 8
    6.      arr[i] = 3; maxValue = 8+3 = 11; result = 11
    return 11
*/
int main()
{
    vector<int> numArray = {3, 2, -1, 7, -8, 3, 2};
    cout << maxSubarraySum(numArray) << endl;

    return 0;
}