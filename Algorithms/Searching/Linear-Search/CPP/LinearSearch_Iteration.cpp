/*
Algorithm:          Linear Search using Iteration

Task:               Use a brute force algorithm to find a specific integer in a sorted array.

Solution:           Search for the target value in the sorted array using a Linear Search algorithm, which checks each element in the 
                    sorted array in order starting from the first element until the target value is found or there are no more elements
                    to check.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/linear-search/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

bool iterativeLinearSearch(vector<int>& nums, int target) {
    // Check each element in nums until target is found or there are no more elements to check.
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return true;
    }
    return false;
}

int main() {
    // Test case 1.
    vector<int> nums = {5, 13, 24, 27, 33, 40, 41};
    int target = 33;
    bool foundTarget = iterativeLinearSearch(nums, target);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    // Test case 2.
    target = 32;
    foundTarget = iterativeLinearSearch(nums, target);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    return 0;
}