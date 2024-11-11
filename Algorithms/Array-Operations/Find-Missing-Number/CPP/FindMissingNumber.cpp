/*
Algorithm:          Find Missing Number (LeetCode Problem #268)

Task:               Given an array of containing N unique integers in the range [0, N], find the only number in the range that is 
                    missing from the array.

Solution:           Subtract the sum of all the integers in the array from the sum of all the integers in range [0, N].

Time complexity:    O(N); N = size of the integer array

Space complexity:   O(1)

Resources:          https://leetcode.com/problems/missing-number/description/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int findMissingNumber(vector<int>& nums)
{
    int rangeSum = 0;       // The sum of all integers in range [0, n].
    int numsSum = 0;        // The sum of all integers in nums.

    for (int i = 0; i <= nums.size(); i++)
        rangeSum += i;
    
    for (int i = 0; i < nums.size(); i++)
        numsSum += nums[i];
    
    // Subtract numsSum from rangeSum; the difference should be the number in range [0, n] that is missing from the nums. 
    return rangeSum - numsSum;
}

int main()
{
    vector<int> array1 = {0, 2, 3, 4};
    cout << findMissingNumber(array1);

    return 0;
}