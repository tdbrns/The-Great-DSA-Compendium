/*
Algorithm:          Two Sum using Two Pointers (LeetCode Problem #1)

Task:               Given an array of integers nums and a target value, return indices of the two numbers such that they add up to 
                    target. Assume that each input would have exactly one solution, and the same element cannot be used twice.

Solution:           Store each integer and its corresponding index in nums into an array of <int, int> pairs named "numPairs", where the 
                    integers are stored as keys and the indices are stored as values. Then, in order to use the two pointer technique, 
                    we must sort the array by key in ascending order. Then we use the technique on the array by iteratively
                    adding the smaller values in the array with the larger values and comparing the sums to the target value. If the sum
                    is less than the target, add the next smallest value to the larger value; if the sum is less than the target, add the
                    next largest value to the smaller value; and if the sum is equal to the target, return the indices of the integers 
                    used to produce that sum. 

Time complexity:    O(N * log(N))
                        N = the number of integers in nums / number of integers in nums to be sorted
                        NOTE: std::sort() uses the Introsort algorithm, which gives the time complexity O(N * log(N))

Space complexity:   O(N)
                        N = number of elements in nums and numPairs

Auxiliary space:    O(N)
                        N = number of pairs in numPairs

Resources:          https://leetcode.com/problems/two-sum/solutions/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::pair;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> numPairs(nums.size());       // Store elements in nums as keys and their indices as values in numPairs.
    
    for (int i = 0; i < nums.size(); i++)
        numPairs[i] = std::make_pair(nums[i], i);

    // Sort numPairs by key in ascending order.
    std::sort(numPairs.begin(), numPairs.end());

    int left_i = 0;                 // Index of the smaller integer in nums. Initialized as the first index.
    int right_i = nums.size() - 1;  // Index of the larger integer in nums. Initialized as the last index.

    while (left_i < right_i) {
        // Calculate the sum of the keys at left_i and right_i.
        int sum = numPairs[left_i].first + numPairs[right_i].first;

        // If the sum is equal to the target, return the indices of numPairs[left_i] and numPairs[right_i].
        if (sum == target)
            return {numPairs[left_i].second, numPairs[right_i].second};
        // If the sum is less than the target, move to the next smallest integer in nums.
        else if (sum < target)
            left_i++;
        // If the sum is greater than the target, move to the next largest integer in nums.
        else if (sum > target)
            right_i--;
    }

    // If the target is not found, return {-1, -1}.
    return {-1, -1};
}

int main() {
    // Test case 1
    vector<int> numVect = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;

    // Test case 2
    numVect = {3, 2, 4};
    target = 6;
    result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;

    // Test case 3
    numVect = {2, 1};
    target = 4;
    result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;

    return 0;
}