/*
Algorithm:          Iterative Binary Search

Task:               Use a divide-and-conquer algorithm to find a specific integer in an array this is sorted in either ascending or 
                    descending order.

Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares the centermost element value to the target value to determine whether the target is in the
                    left or the right side of the centermost element in the array. If the target value is on one side of the centermost
                    element, the other side of the centermost element will be omitted from the search, and the side in which the target
                    resides will be split by its own centermost value and follow the same process. This process of of splitting subarrays
                    will continue until the centermost element value is equal to the target value or the subarray can no longer be split.

Time complexity:    O(log(N)); N = number of integers in the array

Space complexity:   O(N); N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/binary-search/
*/


#include <iostream>
using namespace std;

bool iterativeBinarySearch (int arr[], int leftIndex, int rightIndex, int target)
{
    if (arr[leftIndex] <= arr[rightIndex])
    {
        // Binary search in ascending order.
        while (leftIndex <= rightIndex)
        {
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;    // Index of the centermost element of the current array.

            // NOTE: if midIndex is a decimal number, it is rounded down to the nearest whole number.

            // If the midIndex value is the target, return true.
            if (arr[midIndex] == target)
                return true;

            // If arr[midIndex] is greater than target, make midIndex-1 the new rightIndex to omit the right subarray from the next
            // iteration.
            if (arr[midIndex] > target)
                rightIndex = midIndex - 1;
            // Otherwise, make the midIndex+1 the new leftIndex so only the left subarray is omitted from the next iteration.
            else
                leftIndex = midIndex + 1;
        }
    }
    else
    {
        // Binary search in descending order.
        while (leftIndex <= rightIndex)
        {
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;    // Index of centermost element of the current array.

            // If the midIndexdle value is the target value, return true.
            if (arr[midIndex] == target)
                return true;
            
            // If arr[midIndex] is greater than target, make midIndex+1 the new leftIndex to omit the left subarray from the next 
            // iteration.
            if (arr[midIndex] > target)
                leftIndex = midIndex + 1;
            // Otherwise, make midIndex-1 the new rightIndex to omit the right subarray from the next iteration.
            else
                rightIndex = midIndex - 1;
        }
    }

    // If the target was not found, return false.
    return false;
}

int main()
{
    int nums1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(nums1) / sizeof(nums1[0]);
    int target = 10;
    bool result = iterativeBinarySearch(nums1, 0, size - 1, target);
    (result) ? cout << "First target found!\n" : cout << "First target not found.\n";

    int nums2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};    
    size = sizeof(nums2) / sizeof(nums2[0]);
    target = 8;
    result = iterativeBinarySearch(nums2, 0, size - 1, target);
    (result) ? cout << "Second target found!\n" : cout << "Second target not found.\n";

    return 0;
}