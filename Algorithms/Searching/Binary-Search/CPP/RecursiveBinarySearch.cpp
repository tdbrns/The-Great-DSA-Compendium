/*
Algorithm:          Recursive Binary Search
Characteristics:    Divide-and-conquer
Time complexity:    O(log(N))
Space complexity:   O(1)
Task:               Search for a specific number in an array this is sorted in either ascending or descending order.
Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares the centermost element value to the target value to determine whether the target is in the
                    left or the right side of the centermost element in the array. If the target value is on one side of the centermost
                    element, the other side of the centermost element will be omitted from the search, and the side in which the target
                    resides will be split by its own centermost value and follow the same process. This process of of splitting subarrays
                    will continue until the centermost element value is equal to the target value or the subarray can no longer be split.
Resources:          https://www.geeksforgeeks.org/binary-search/
*/

#include <iostream>
using namespace std;

int RecursiveBinarySearchAscend(int arr[], int leftIndex, int rightIndex, int target)
{
    //  rightIndex = rightmost element index of the subarray being checked in the current iteration
    //  leftIndex = leftmost element index of the subarray being checked in the current iteration
    //  target = the element/value being searched for.
    //  NOTE: only the array elements between rightIndex and leftIndex are evaluated in each iteration.

    // Once leftIndex is equal to rightIndex, the subarray cannot be divide any further.
    if (leftIndex <= rightIndex)
    {
        // midIndex = centermost element index of the subarray being checked in the current iteration; if midIndex is a decimal number, 
        // it is rounded down to the nearest integer.
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        // Base case. If the centermost value is the target value, return midIndex.
        if (arr[midIndex] == target)
            return midIndex;

        // If the centermost value is greater than target, make midIndex-1 the new rightIndex so the the right subarray will be omitted 
        // from the next recursive pass.
        if (arr[midIndex] > target)
            return RecursiveBinarySearchAscend(arr, leftIndex, midIndex - 1, target);

        // Otherwise, make the midIndex+1 the new leftIndex so that the left subarray will be omitted from the next recursive pass.
        return RecursiveBinarySearchAscend(arr, midIndex + 1, rightIndex, target);
    }

    // If the value is not found, return -1.
    return -1;
}

int RecursiveBinarySearchDescend(int arr[], int leftIndex, int rightIndex, int target)
{
    if (leftIndex <= rightIndex)
    {
        // midIndex = centermost element index of the subarray being checked in the current iteration; if midIndex is a decimal number, 
        // it is rounded down to the nearest integer.
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (arr[midIndex] == target)
            return midIndex;

        // If the centermost value is greater than target, make midIndex+1 the new leftIndex so the the left subarray will be omitted 
        // from the next recursive pass.
        if (arr[midIndex] > target)
            return RecursiveBinarySearchDescend(arr, midIndex + 1, rightIndex, target);
        
        // Otherwise, make the midIndex-1 the new rightIndex so that the right subarray will be omitted from the next recursive pass.
        return RecursiveBinarySearchDescend(arr, leftIndex, midIndex - 1, target);
    }
    return -1;
}

int main()
{
    int numArray1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 12;
    int arrSize = sizeof(numArray1) / sizeof(numArray1[0]);
    int result = RecursiveBinarySearchAscend(numArray1, 0, arrSize-1, target);
    (result == -1) ? cout << "First target not found.\n" : cout << "First target found!\n";
        
    int numArray2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    target = 4;
    arrSize = sizeof(numArray2) / sizeof(numArray2[0]);
    result = RecursiveBinarySearchDescend(numArray2, 0, arrSize-1, target);
    (result == -1) ? cout << "Second target not found.\n" : cout << "Second target found!\n";

    return 0;
}