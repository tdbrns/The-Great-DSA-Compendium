/*
Algorithm:          Maximum Subarray Sum (LeetCode Problem #53)

Task:               Given an integer array, find the subarray with the largest sum and return the sum.

Solution:           Basically, we must find the "maximum subarray" of the given array, which is the subarray of whose elements, when 
                    added together, give the largest sum of any other subarray. This is done using Kadane's algorithm, which involves
                    iteratively adding up each integer in the array and keeping track of the largest sum that is given by adding up
                    a certain contiguous sequence of integers in the array.

Time complexity:    O(N)
                        N = size of the integer array

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
    // maxSum and currMax are intitialized with element arr[0].
    int currMax = arr[0];       // Largest value between the sum of the current subarray and element arr[i].
    int maxSum = arr[0];        // Sum of the maximum subarray in arr[].

    for (int i = 1; i < arr.size(); i++) 
    {
        currMax = max(currMax + arr[i], arr[i]);
        maxSum = max(currMax, maxSum);
    }

    return maxSum;
}
/* maxSubarraySum() when arr = {3, 2, -1, 7, -8, 3, 2}
    init.   currMax = 3   maxSum = 3
    1.      arr[i] = 2   currMax = max(3+2, 3) = 5       maxSum = max(5, 3) = 5
    2.      arr[i] = -1  currMax = max(5+(-1), -1) = 4   maxSum = max(5, 4) = 5
    3.      arr[i] = 7   currMax = max(4+7, 7) = 11      maxSum = max(11, 5) = 11
    4.      arr[i] = -8  currMax = max(11+(-8), -8) = 3  maxSum = max(3, 11) = 11
    5.      arr[i] = 3   currMax = max(3+3, 3) = 6       maxSum = max(6, 11) = 11
    6.      arr[i] = 2   currMax = max(6+2, 2) = 8       maxSum = max(8, 11) = 11
    return 11
*/

int main()
{
    vector<int> numArray = {3, 2, -1, 7, -8, 3, 2};
    cout << maxSubarraySum(numArray) << endl;

    return 0;
}