/*
Algorithm:          Find Missing Number using XOR (LeetCode Problem #268)

Task:               Given an array of containing n unique integers in the range [0, n], find the only number in the range that is 
                    missing from the array.

Solution:           There are two basic properties of the XOR operation:
                        • a XOR 0 = a
                        • a XOR a = 0
                    We can use these properties to determine the missing number in an array of integers by XORing each integer in the
                    range 0 to n with each integer in the array. 
                    For example, when array = [3, 0, 1], XORing each integer in range 0 to n with each integer in the array will give:
                                                (0 XOR 3) XOR (1 XOR 0) XOR (2 XOR 1) XOR 3

                    Grouping like numbers in the expression together will give:
                                                (0 XOR 0) XOR (1 XOR 1) XOR 2 XOR (3 XOR 3)

                    Then simplifying the expression will give:
                                                         0 XOR 0 XOR 2 XOR 0

                    Finally, solving the simplified expresson will give us the missing number: 2.

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

int missingNumber(vector<int>& nums) 
{
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= i;
        result ^= nums[i];
    }

    return result;
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