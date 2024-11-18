/*
Algorithm:          Maximum Sum of Distinct Subarrays with Length K using Sliding Window (LeetCode Problem #2461)

Task:               You are given an integer array "nums" and an integer "k". Find the maximum subarray of all the subarrays of nums
                    the meet the following conditions:
                        • The length of the subarray is k
                        • All the elements of the subarray are distinct
                    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions,
                    return 0. Note that k should always be less than or equal to the size of nums.

Solution:           Use the sliding window technique to iteratively find the sum of each subarray with length of k in nums that meets 
                    the conditions. Instead of adding up the elements of each subarray to get a sum, we will take the sum of the first
                    subarray and subtract its leftmost value from its sum and add the next element to its right to its sum to get the
                    sum of the next subarray with length of k; this is done iteratively to acquire the sum of each subarray in nums 
                    with fewer iterations than the brute force approach.
                    To ensure that only subarrays that follow the conditions are considered, use a hashmap to keep track of the 
                    frequency of the integers in each subarray; if an element appears more than once in a subarray, that subarray 
                    should be skipped over. Note that when applying the sliding window technique, each window consists of the elements 
                    of a subarray with length of k exist in range nums[i-k] to nums[i-1]. nums[i] is the next element to be added.

Time complexity:    O(N); N = the number of integers in nums

Space complexity:   O(k); k = the number of integers in a subarray of nums

Resources:          https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/solutions/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

long long maximumSubarraySum(vector<int>& nums, int k) {
    long long maxSum = 0;           // The sum of the maximum subarray.
    long long windowSum = 0;        // The sum of every element in subarray with length of k.
    unordered_map<int, int> uMp;    // Stores the frequency of each element in a subarray.

    // Compute the sum of the elements in the first k-sized window and use uMp to store the frequency of each element.
    for (int i = 0; i < k; i++) 
    {
        uMp[nums[i]]++;
        windowSum += nums[i];
    }

    // If the size of uMp is k, all the elements in the first window are distinct.
    if (uMp.size() == k)
        maxSum = windowSum;

    // Compute the sum of the  
    for (int i = k; i < nums.size(); i++) 
    {
        uMp[nums[i]]++;         // Add the next value to uMp by adding 1 to its value.
        uMp[nums[i - k]]--;     // Remove the leftmost value

        // If nums[i - k] has value 0, it isn't present in the current subarray, so erase it.
        if (uMp[nums[i - k]] == 0)
            uMp.erase(nums[i - k]);

        // Subtract the leftmost value from and add the next value to the window sum.
        windowSum += nums[i] - nums[i - k];

        // If the size of uMp is, all the elements in the current window are distinct, so determine the new maxSum.
        if (uMp.size() == k)
            maxSum = std::max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    cout << "The sum of the maximum distinct subarray is " << maximumSubarraySum(nums, k) << endl;

    nums = {4, 4, 4};
    k = 3;
    cout << "The sum of the maximum distinct subarray is " << maximumSubarraySum(nums, k) << endl;

    return 0;
}