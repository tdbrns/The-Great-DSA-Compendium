/*
Algorithm:          Majority Element using Hashmap (LeetCode Problem #169)

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

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> intHz;          // Stores elements in nums as keys and their frequency as values.
    int majorityElem = 0;                   // Current majority element.

    // Iterate through nums and record the frequency of each element. Update the majority element with nums[i] if nums[i] occurs more 
    // frequently than the majority element.
    for (int i = 0; i < nums.size(); i++) {
        intHz[nums[i]]++;

        if (intHz[nums[i]] > intHz[majorityElem])
            majorityElem = nums[i];
    }

    return majorityElem;
}

int main() {
    // Test case 1.
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums) << endl;

    // Test case 2.
    nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;

    return 0;
}