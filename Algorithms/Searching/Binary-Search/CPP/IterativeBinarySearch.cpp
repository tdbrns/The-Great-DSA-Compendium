/*
Algorithm:          Iterative Binary Search
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

bool IterativeBinarySearch (int arr[], int leftIndex, int rightIndex, int target)
{
    //  rightIndex = rightmost element index of the subarray being checked in the current iteration.
    //  leftIndex = leftmost element index of the subarray being checked in the current iteration.
    //  target = the element/value being searched for.
    //  NOTE: only the array elements between rightIndex and leftIndex are evaluated in each iteration.

    if (arr[leftIndex] <= arr[rightIndex])
    {
        // Binary search in ascending order (smaller values are on the left side; larger values are on the right side).
        // Once leftIndex is equal to rightIndex, the subarray cannot be divide any further.
        while (leftIndex <= rightIndex)
        {
            // midIndex = centermost element index of the subarray being checked in the current iteration; if midIndex is a decimal number, 
            // it is rounded down to the nearest integer.
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            // If the midIndex value is the target, return true.
            if (arr[midIndex] == target)
                return true;

            // If element arr[midIndex] is greater than target, make midIndex-1 the new rightIndex so that the right subarray is omitted
            // from the next iteration. Otherwise, make the midIndex+1 the new leftIndex so only the left subarray is omitted from the
            // next iteration.
            if (arr[midIndex] > target)
                rightIndex = midIndex - 1;
            else
                leftIndex = midIndex + 1;
        }

        // If the target value was not found, return false.
        return false;
    }
    else
    {
        // Binary search in descending order (larger values are on the left side; smaller values are on the right side).
        // Once rightIndex is equal to leftIndex, the subarray cannot be divide any further.
        while (leftIndex <= rightIndex)
        {
            // midIndex = centermost element index of the subarray being checked in the current iteration; if midIndex is a decimal number, 
            // it is rounded down to the nearest integer.
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            // If the midIndexdle value is the target value, return true.
            if (arr[midIndex] == target)
                return true;
            
            // If the element arr[midIndex] is greater than target, make midIndex+1 the new leftIndex so that the left subarray is
            // omitted from the next iteration. Otherwise, make the midIndex-1 the new rightIndex so that the right subarray is omitted
            // from the next iteration.
            if (arr[midIndex] > target)
                leftIndex = midIndex + 1;
            else
                rightIndex = midIndex - 1;
        }

        // If the target value was not found, return false.
        return false;
    }

    return false;
}

int main()
{
    int numArray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(numArray1) / sizeof(numArray1[0]);
    int target = 10;
    bool result = IterativeBinarySearch(numArray1, 0, arrSize - 1, target);
    (result) ? cout << "First target found!\n" : cout << "First target not found.\n";

    int numArray2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};    
    arrSize = sizeof(numArray2) / sizeof(numArray2[0]);
    target = 8;
    result = IterativeBinarySearch(numArray2, 0, arrSize - 1, target);
    (result) ? cout << "Second target found!\n" : cout << "Second target not found.\n";

    return 0;
}