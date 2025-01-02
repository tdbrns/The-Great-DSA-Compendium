/*
Algorithm:          Find Missing Number using Gauss Sum Formula (LeetCode Problem #268)

Task:               Given an array of containing n unique integers in the range [0, n], find the only number in the range that is 
                    missing from the array.

Solution:           Find the sum of all integers from 0 to N using the Gauss Sum formula, subtract the sum of all the integers in the
                    array from the the Gauss sum, and return the difference.
                    NOTE:
                        • This solution may result in an integer overflow if the Gauss sum is too large.

Time complexity:    O(N)
                        N = size of the integer array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/missing-number/solutions/
                    https://dev.to/alisabaj/the-gauss-sum-and-solving-for-the-missing-number-996#:~:text=In%20other%20words%2C%20if%20you,lot%20you%20can%20do%20with%20.
*/


#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int missingNumber(vector<int>& nums) {
    int sum = (0 + nums.size()) * (nums.size() + 1) / 2;        // Gauss sum.

    // Iteratively subtract each integer in nums from the Gaus sum to find the difference.
    for (int i = 0; i < nums.size(); i++)
        sum -= nums[i];
    
    // Return the remaining sum (i.e., the missing number).
    return sum;
}

int main()
{
    // Test case 1.
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums) << endl;

    // Test case 2.
    nums = {0, 1};
    cout << missingNumber(nums) << endl;

    // Test case 3.
    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums) << endl;

    return 0;
}