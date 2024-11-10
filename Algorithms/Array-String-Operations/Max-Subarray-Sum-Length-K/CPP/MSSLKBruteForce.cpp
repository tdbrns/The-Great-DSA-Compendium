/*
Algorithm:          Maximum Sum of Distinct Subarrays with Length K using Brute Force (LeetCode Problem #2461)

Task:               You are given an integer array "nums" and an integer "k". Find the maximum subarray of all the subarrays of nums
                    the meet the following conditions:
                        • The length of the subarray is k
                        • All the elements of the subarray are distinct
                    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions,
                    return 0. Note that k should always be less than or equal to the size of nums.

Solution:           Use brute force to iteratively find the sum of each subarray with length of k in nums and identify the subarray 
                    with the greatest sum. Use a hashmap to keep track of the frequency of the elements in each subarray; if an element
                    appears more than once in a subarray, the subarray should be skipped over. Note that this approach will probably
                    produce a "Time Limit Exceeded" error in LeetCode due to its poor runtime when processing larger input data.

Time complexity:    O(k * N); k = the number of integers in a subarray of nums, N = the number of integers in nums

Space complexity:   O(k); k = the number of integers in a subarray of nums

Resources:          https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/solutions/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

long long maximumSubarraySum(vector<int>& nums, int k) 
{
    long long maxSum = 0;
    int n = nums.size();
    
    // Find the sum for each subarray with length of k in nums.
    for (int i = 0; i < n - k + 1; i++)
    {
        long long currSum = 0;                  // The sum of the current subarray.
        unordered_map<int, int> elems(k);       // Stores the frequency of each element in a subarray.
        bool isDistinct = true;

        // Compute the sum for the current subarray.
        for (int j = 0; j < k; j++)
        {
            // If the current element is not already present in the subarray, add it to the current sum.
            if (elems[nums[i + j]] == 0)
            {
                elems[nums[i + j]]++;
                currSum = currSum + nums[i + j];
            }
            // If the current element is already present in the subarray, skip it.
            else
            {
                isDistinct = false;
                break;
            }
        }
        
        // If the current subarray has no repeating elements, determine the new maxSum.
        if (isDistinct)
            maxSum = std::max(currSum, maxSum);
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