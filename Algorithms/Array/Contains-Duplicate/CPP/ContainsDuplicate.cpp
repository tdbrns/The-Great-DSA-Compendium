/*
Algorithm:          Contains Duplicate using Hashmap (LeetCode Problem #217)

Task:               Given an integers array nums, return true if any value appears at least twice, and return false if every element is
                    distinct.

Solution:           Iterate though nums while storing the frequency of each integer into a hashmap. If any integer has a frequency value 
                    greater than 1, return false; otherwise, return true.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums / number of elements in the hashmap

Auxiliary space:    O(N)
                        N = number of elements in the hashmap

Resources:          https://leetcode.com/problems/contains-duplicate/solutions/
                    https://www.geeksforgeeks.org/check-if-the-given-input-contains-duplicates/
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> intHz;          // Hashmap storing elements in nums as keys and their frequency as values.

    // Iteratively store the frequency of each element in nums.
    for (int i = 0; i < nums.size(); i++) {
        // If the current integer's frequency is equal to 0, add 1 to its frequency; otherwise, return true.
        if (intHz[nums[i]] == 0)
            intHz[nums[i]]++;
        else
            return true;
    }

    // If all integers have a frequency of 1 at the end of the loop, then every element in nums if distinct.
    return false;
}

int main() {
    // Test case 1.
    vector<int> nums = {1, 2, 3, 1};
    containsDuplicate(nums) ? cout << "True\n" : cout << "False\n";
    
    // Test case 2.
    nums = {1, 2, 3, 4};
    containsDuplicate(nums) ? cout << "True\n" : cout << "False\n";
    
    // Test case 3.
    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    containsDuplicate(nums) ? cout << "True\n" : cout << "False\n";

    return 0;
}