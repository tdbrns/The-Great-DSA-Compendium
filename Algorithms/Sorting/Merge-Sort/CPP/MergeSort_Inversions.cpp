/*
Algorithm:          Counting Inversions in Merge Sort Algorithm

Task:               Use a stable divide-and-conquer sorting algorithm to sort an array of integers in ascending order, and count the 
                    total number of inversion required to sort the array.

Solution:           Sort the array using the Merge Sort algorithm, which sorts the array by dividing it into subarrays until it has been
                    divided into separate single elements and placing those elements into a sorted array in the appropriate order.
                    During the process of merging the subarrays into ascending order, when the current element of the left subarray is 
                    greater than the current element of the right subarray, the current left subarray element and all the elements to its 
                    right are considered inversions. If none of the left subarray elements are greater than any of the right subarray 
                    elements, the total inversion count is 0.

Time complexity:    O(N*log(N))
                        N = number of integers to be sorted
                        NOTE: worst-case scenario occurs when the input array is sorted in descending order.

Space complexity:   O(N)
                        N = maximum depth of the recursion stack and the number of integers in the array

Auxiliary space:    O(N)
                        N = number of integers in the subarrays

Resources:          https://www.geeksforgeeks.org/merge-sort/
                    https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// merge() has time complexity O(N).
unsigned int merge(int currArray[], int leftIndex, int midIndex, int rightIndex)
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
    unsigned int invCount = 0;

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

            // If the current left subarray element is greater than the current right subarray element, count the current left 
            // subarray element and all the elements to the right of it as an inversion.
            invCount += (leftSize - leftSubIndex);
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

    return invCount;
}

// mergeSort() has time complexity O(log(N)).
unsigned int mergeSort(int currArray[], int leftIndex, int rightIndex)
{
    unsigned int totalInversion = 0;

    // Base case; when the array has been divided into single elements, return totalInversion, which is 0.
    if (leftIndex >= rightIndex)
        return totalInversion;

    int midIndex = (rightIndex + leftIndex) / 2;        // Stores the middle element that divides the current array into two subarrays.

    // NOTE: when dividing two integers produces a fractional quotient, the quotient is always rounded 
    // down to the nearest whole number.
    
    // Recursively divide the left and right subarray in half until there are only single elements.
    totalInversion += mergeSort(currArray, leftIndex, midIndex);        // Left subarray.
    totalInversion += mergeSort(currArray, midIndex+1, rightIndex);     // Right subarray.

    // Merge the single elements into a sorted array.
    totalInversion += merge(currArray, leftIndex, midIndex, rightIndex);

    return totalInversion;
}

int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7, 10, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    unsigned int totalInversion = mergeSort(nums, 0, size-1);
    
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    cout << "\nInversion Count: " << totalInversion << endl;

    return 0;
}