/*
Algorithm:          Linear Search using Iteration

Task:               Use a brute force algorithm to find a specific integer in a sorted array.

Solution:           Search for the target value in the sorted array using a Linear Search algorithm, which checks each element in the 
                    sorted array in order starting from the first element until the target value is found or there are no more elements
                    to check.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array / maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/linear-search/
*/


#include <iostream>
#include <vector>
using std::cout;
using std::vector;

bool recursiveLinearSearch(vector<int>& nums, int target, int i) {    
    // i = index of the current element being checked.
    // Base case; if nums[i] is equal to the target, return True.
    // Base case; if i >= nums.size(), return false.
    // If nums[i] is not equal to target, let i = i + 1 and recur.
    if (i < nums.size()) {
        if (nums[i] == target)
            return true;
        return recursiveLinearSearch(nums, target, i + 1);
    }
    return false;
}

int main() {
    // Test case 1.
    vector<int> nums = {5, 13, 24, 27, 33, 40, 41};
    int target = 33;
    int i = 0;
    bool foundTarget = recursiveLinearSearch(nums, target, i);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    // Test case 2.
    target = 32;
    foundTarget = recursiveLinearSearch(nums, target, i);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    return 0;
}