/*
Algorithm:          Merge Sort

Task:               Use a stable divide-and-conquer sorting algorithm to sort an array of integers in ascending order.

Solution:           Sort the array using the Merge Sort algorithm, which sorts the array by dividing it into subarrays until it has been
                    divided into separate single elements and placing those elements into a sorted array in the appropriate order.

Time complexity:    O(N * log(N))
                        N = number of integers to be sorted
                        NOTE: worst-case scenario occurs when the input array is sorted in descending order.

Space complexity:   O(N)
                        N = maximum depth of the recursion stack and the number of integers in the array

Auxiliary space:    O(N)
                        N = number of integers in the subarrays

Resources:          https://www.geeksforgeeks.org/merge-sort/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// merge() has time complexity O(N).
void merge(int currArray[], int leftIndex, int midIndex, int rightIndex)
{
    int leftSize = midIndex - leftIndex + 1;        // Size of the left subarray.
    int rightSize = rightIndex - midIndex;          // Size of the right subarray.
    vector<int> leftSubarray(leftSize);             // Temp array to hold elements of the left subarray.
    vector<int> rightSubarray(rightSize);           // Temp array to hold elements of the right subarray.

    // Move the left and right elements of currArray's left and right subarrays into their respective temp arrays.
    for (int i = 0; i < leftSize; i++)
        leftSubarray[i] = currArray[leftIndex + i];
    for (int i = 0; i < rightSize; i++)
        rightSubarray[i] = currArray[midIndex + i + 1];
    
    int leftSubIndex = 0;           // Index of the left subarray.
    int rightSubIndex = 0;          // Index of the right subarray.
    int mergedIndex = leftIndex;    // Index of currArray that an element of leftSubarray or rightSubarray will be stored at.

    // Sort the elements of leftSubarray and rightSubarray into currArray.
    while (leftSubIndex < leftSize && rightSubIndex < rightSize)
    {
        // If the left element is less than or equal to the right element, store it in currArray.
        if (leftSubarray[leftSubIndex] <= rightSubarray[rightSubIndex])
        {
            currArray[mergedIndex] = leftSubarray[leftSubIndex];
            leftSubIndex++;
        }
        // If the left element is greater than the right element, store it in currArray.
        else
        {
            currArray[mergedIndex] = rightSubarray[rightSubIndex];
            rightSubIndex++;
        }

        mergedIndex++;
    }

    // If there are remaining elements in leftSubarray, store them into currArray.
    while (leftSubIndex < leftSize)
    {
        currArray[mergedIndex] = leftSubarray[leftSubIndex];
        leftSubIndex++;
        mergedIndex++;
    }

    // If there are remaining elements in rightSubarray, store them into currArray.
    while (rightSubIndex < rightSize)
    {
        currArray[mergedIndex] = rightSubarray[rightSubIndex];
        rightSubIndex++;
        mergedIndex++;
    }
}

// mergeSort() has time complexity O(log(N)).
void mergeSort(int currArray[], int leftIndex, int rightIndex)
{
    // Base case; when the array has been divided into single elements, return.
    if (leftIndex >= rightIndex)
        return;

    int midIndex = (rightIndex + leftIndex) / 2;        // Stores the middle element that divides the current array into two subarrays.

    // NOTE: when dividing two integers produces a fractional quotient, the quotient is always rounded 
    // down to the nearest whole number.
    
    // Recursively divide the left and right subarray in half until there are only single elements.
    mergeSort(currArray, leftIndex, midIndex);        // Left subarray.
    mergeSort(currArray, midIndex+1, rightIndex);     // Right subarray.

    // Merge the single elements into a sorted array.
    merge(currArray, leftIndex, midIndex, rightIndex);
}

int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7, 10, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, 0, size-1);
    
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";

    return 0;
}