/*
Algorithm:          Majority Element using Hashmap (LeetCode Problem #409)

Task:               Given an array nums of size n, return the majority element. The majority element is the element that appears more 
                    than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Solution:           Use a hashmap to record the frequency of each integer in nums and return the integer with the highest frequency
                    value.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums / number of integers in the hashmap

Auxiliary space:    O(N)
                        N = number of integers in the hashmap

Resources:          https://leetcode.com/problems/majority-element/solutions/
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

int majorityElement(vector<int>& nums) 
{
    // Use a hash map to record the frequency of each integer in the array. Return the integer with the highest frequency value.
    unordered_map<int, int> intHz;
    int majorityElem = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        intHz[nums[i]]++;

        if (intHz[nums[i]] > intHz[majorityElem])
            majorityElem = nums[i];
    }

    return majorityElem;
}

int main()
{
    // Test case 1.
    vector<int> nums = {3, 2, 2};
    cout << majorityElement(nums) << endl;

    // Test case 2.
    nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;

    return 0;
}