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
    // result and maxValue are intitialized with element arr[0].
    int maxValue = arr[0];      // Largest value between the sum of the current subarray and element arr[i], initialized with arr[0].
    int result = arr[0];        // Sum of the maximum subarray in arr[], initialized with arr[0].

    for (int i = 1; i < arr.size(); i++) 
    {
        maxValue = max(maxValue + arr[i], arr[i]);
        result = max(maxValue, result);
    }

    return result;
}
/* maxSubarraySum when arr = {3, 2, -1, 7, -8, 3, 2}
    init.   maxValue = 3   result = 3
    1.      arr[i] = 2   maxValue = max(3+2, 3) = 5       result = max(5, 3) = 5
    2.      arr[i] = -1  maxValue = max(5+(-1), -1) = 4   result = max(5, 4) = 5
    3.      arr[i] = 7   maxValue = max(4+7, 7) = 11      result = max(11, 5) = 11
    4.      arr[i] = -8  maxValue = max(11+(-8), -8) = 3  result = max(3, 11) = 11
    5.      arr[i] = 3   maxValue = max(3+3, 3) = 6       result = max(6, 11) = 11
    6.      arr[i] = 2   maxValue = max(6+2, 2) = 8       result = max(8, 11) = 11
    return 11
*/

int main()
{
    vector<int> numArray = {3, 2, -1, 7, -8, 3, 2};
    cout << maxSubarraySum(numArray) << endl;

    return 0;
}