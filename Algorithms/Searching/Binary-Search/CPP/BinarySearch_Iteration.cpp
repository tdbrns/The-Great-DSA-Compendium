/*
Algorithm:          Iterative Binary Search

Task:               Use a divide-and-conquer algorithm to find a specific integer in an array this is sorted in either ascending or 
                    descending order.

Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares its value to the target value to determine whether the target is in the left or the right 
                    side of the array. If the target value is on one side of the centermost element, the other side of the centermost 
                    element will be omitted from the search, and the side in which the target resides will be split by its own 
                    centermost value and follow the same process. This process of of splitting subarrays will continue until the 
                    centermost element value is equal to the target value or the subarray can no longer be split.

Time complexity:    O(log(N)); N = number of integers in the array

Space complexity:   O(N); N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/binary-search/
*/


#include <iostream>
#include <vector>
using std::cout;
using std::vector;

bool iterativeBinarySearch (vector<int>& nums, int target) {
    int left_i = 0;                                         // Index of first element in nums.
    int right_i = nums.size() - 1;                          // Index of last element in nums.
    
    // Binary search in ascending order.
    if (nums[left_i] <= nums[right_i]) {
        // Binary search in ascending order.
        while (left_i <= right_i) {
            int mid_i = left_i + (right_i - left_i) / 2;    // Index of the centermost element of the current array.

            // If nums[mid_i] is the target, return true.
            // If nums[mid_i] is greater than target, let right_i = mid_i-1 to omit the right subarray.
            // If nums[mid_i] is less than target, let left_i = mid_i+1 to omit the left subarray.
            if (nums[mid_i] == target)
                return true;
            if (nums[mid_i] > target)
                right_i = mid_i - 1;
            else
                left_i = mid_i + 1;
        }
    }
    // Binary search in descending order.
    else {
        while (left_i <= right_i) {
            int mid_i = left_i + (right_i - left_i) / 2;    // Index of centermost element of the current array.

            // If nums[mid_i] is the target, return true.
            // If nums[mid_i] is greater than target, let left_i = mid_i+1 to omit the left subarray.
            // if nums[mid_i] is less than target, let right_i = mid_i-1 to omit the right subarray.
            if (nums[mid_i] == target)
                return true;
            if (nums[mid_i] > target)
                left_i = mid_i + 1;
            else
                right_i = mid_i - 1;
        }
    }

    // If the target was not found, return false.
    return false;
}

int main() {
    // Test case 1.
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 1;
    bool foundTarget = iterativeBinarySearch(nums, target);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    // Test case 2.
    nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};    
    target = 8;
    foundTarget = iterativeBinarySearch(nums, target);
    (foundTarget) ? cout << target << " is in the array\n" : cout << target << " is not in the array\n";

    return 0;
}