/*
Algorithm:          Find Missing Number (LeetCode Problem #268)

Task:               Given an array of containing n unique integers in the range [0, n], find the only number in the range that is 
                    missing from the array.

Solution:           Subtract the sum of all the integers in the array from the sum of all the integers in range [0, N] and return the
                    difference, which will be the missing number.

Time complexity:    O(N)
                        N = size of the integer array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/missing-number/description/
*/


#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int missingNumber(vector<int>& nums) {
    int rangeSum = 0;       // The sum of all integers in range [0, n].
    int numsSum = 0;        // The sum of all integers in nums.

    for (int i = 0; i <= nums.size(); i++) {
        if (i < nums.size())
            numsSum += nums[i];
        rangeSum += i;
    }
    
    return rangeSum - numsSum;
}

int main() {
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