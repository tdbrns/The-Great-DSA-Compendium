/*
Algorithm:          Majority Element (LeetCode Problem #409)

Task:               Given an array nums of size n, return the majority element. The majority element is the element that appears more 
                    than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Solution:           Starting at the first element in nums, iterate through each element while keeping track of an "majority score" - a
                    counter used to determine if the current element nums[i] is the majority element. 
                    Scoring rules:
                        • If the score equals 0 during the current iteration, nums[i+1] is the new majority element.
                        • If nums[i] is the current majority element, add 1 to the score.
                        • If nums[i] is not the current majority element, subtract 1 from the score.
                    The last integer to be considered the majority element is returned.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums

Auxiliary space:    O(1)

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
    int majorityElem = 0;       // The current majority element.
    int majorityScore = 0;      // Score that determines if the current element is the majority element.

        // Record the majority score as described.
        for (int i = 0; i < nums.size(); i++)
        {
            if (majorityScore == 0)
                majorityElem = nums[i];
            
            if (majorityElem == nums[i])
                majorityScore++;
            else
                majorityScore--;
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