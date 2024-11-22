/*
Algorithm:          Recursive Binary Search

Task:               Use a divide-and-conquer algorithm to find a specific integer in an array this is sorted in either ascending or 
                    descending order.

Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares the centermost element value to the target value to determine whether the target is in the
                    left or the right side of the centermost element in the array. If the target value is on one side of the centermost
                    element, the other side of the centermost element will be omitted from the search, and the side in which the target
                    resides will be split by its own centermost value and follow the same process. This process of of splitting subarrays
                    will continue until the centermost element value is equal to the target value or the subarray can no longer be split.
                    
Time complexity:    O(log(N)); N = number of integers in the array

Space complexity:   O(N); N = maximum depth of the recursive call stack / number of integers in the array

Auxiliary space:    O(N); N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/binary-search/
*/

#include <iostream>
using namespace std;

int recursiveBinarySearchAscend(int arr[], int leftIndex, int rightIndex, int target)
{
    // NOTE: only the array elements between rightIndex and leftIndex are evaluated in each iteration. Once leftIndex is equal to 
    // rightIndex, the subarray cannot be divide any further.

    if (leftIndex <= rightIndex)
    {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;  // Index of the centermost element of the current array.

        // NOTE: if midIndex is a decimal number, it is rounded down to the nearest whole number.

        // Base case; if the centermost value is the target value, return midIndex.
        if (arr[midIndex] == target)
            return midIndex;

        // If the centermost value is greater than target, make midIndex-1 the new rightIndex in the next recursive pass.
        if (arr[midIndex] > target)
            return recursiveBinarySearchAscend(arr, leftIndex, midIndex - 1, target);

        // Otherwise, make the midIndex+1 the new leftIndex in the next recursive pass.
        return recursiveBinarySearchAscend(arr, midIndex + 1, rightIndex, target);
    }

    // If the value is not found, return -1.
    return -1;
}

int recursiveBinarySearchDescend(int arr[], int leftIndex, int rightIndex, int target)
{
    if (leftIndex <= rightIndex)
    {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;    // Index of the centermost element of the current array.

        // Base case; if the centermost value if the target value, return midIndex.
        if (arr[midIndex] == target)
            return midIndex;

        // If the centermost value is greater than target, make midIndex+1 the new leftIndex in the next recursive pass.
        if (arr[midIndex] > target)
            return recursiveBinarySearchDescend(arr, midIndex + 1, rightIndex, target);
        
        // Otherwise, make the midIndex-1 the new rightIndex in the next recursive pass.
        return recursiveBinarySearchDescend(arr, leftIndex, midIndex - 1, target);
    }

    // If the value if not found, return -1.
    return -1;
}

int main()
{
    int nums1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 12;
    int arrSize = sizeof(nums1) / sizeof(nums1[0]);
    int result = recursiveBinarySearchAscend(nums1, 0, arrSize-1, target);
    (result == -1) ? cout << "First target not found.\n" : cout << "First target found!\n";
        
    int nums2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    target = 4;
    arrSize = sizeof(nums2) / sizeof(nums2[0]);
    result = recursiveBinarySearchDescend(nums2, 0, arrSize-1, target);
    (result == -1) ? cout << "Second target not found.\n" : cout << "Second target found!\n";

    return 0;
}