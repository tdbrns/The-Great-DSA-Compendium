/*
Algorithm:          Merge Sort

Task:               Use a stable divide-and-conquer sorting algorithm to sort an array of integers in ascending order, and count the 
                    total number of inversion required to sort the array.

Solution:           Sort the array using the Merge Sort algorithm, which sorts the array by dividing it into subarrays until it has been
                    divided into separate single elements, and placing those elements into a sorted array in the appropriate order.
                    During the process of merging the subarrays into ascending order, when the current element of the left subarray is 
                    greater than the current element of the right subarray, the left subarray element and all the elements to its right
                    are considered inversions. If none of the left subarray elements are greater than any of the right subarray 
                    elements, the total inversion count is 0.

Time complexity:    O(N*log(N)); N = number of integers to be sorted
                    - Worst-case scenario occurs when the array in sorted in the descending order.

Space complexity:   O(N)

Resources:          https://www.geeksforgeeks.org/merge-sort/
                    https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/
*/

#include <iostream>
#include <vector>
using namespace std;

// Count the number of times a merge occurs.
unsigned int mergeCount = 0;

// Note: Arrays are always passed by reference
unsigned int Merge(int currArray[], int leftIndex, int midIndex, int rightIndex)
{
    int leftSize = midIndex - leftIndex + 1;        // Size of the left subarray
    int rightSize = rightIndex - midIndex;          // SIze of the right subarray
    int* leftSubarray = new int[leftSize];          // Temp array to hold elements of the left subarray
    int* rightSubarray = new int[rightSize];        // Temp array to hold elements of the right subarray

    // See the sizes of the left and right subarrays; when the two sizes are unequal, it means the array that was divided prior had an
    // odd number of elements.
    // cout << leftSize << " <-> " << rightSize << endl; 

    // Move the left and right elements of currArray's left and right subarrays into their respective temp arrays
    for (int i = 0; i < leftSize; i++)
        leftSubarray[i] = currArray[leftIndex + i];
    for (int i = 0; i < rightSize; i++)
        rightSubarray[i] = currArray[midIndex + i + 1];
    
    int leftSubIndex = 0;           // Index of the left subarray
    int rightSubIndex = 0;          // Index of the right subarray
    int mergedIndex = leftIndex;    // Index of currArray as the subarrays are merged in order
    unsigned int invCount = 0;
    while (leftSubIndex < leftSize && rightSubIndex < rightSize)
    {
        if (leftSubarray[leftSubIndex] <= rightSubarray[rightSubIndex])
        {
            // If the left element is less than or equal to the right element, store it as next element in currArray
            currArray[mergedIndex] = leftSubarray[leftSubIndex];
            leftSubIndex++;
        }
        else
        {
            // If the left element is greater than the right element, store it as next element in currArray
            currArray[mergedIndex] = rightSubarray[rightSubIndex];
            rightSubIndex++;

            // If the current left subarray element is greater than the current right subarray element, count the left subarray element
            // and all the elements to the right of it as an inversion
            invCount += (leftSize - leftSubIndex);
        }
        mergedIndex++;
    }

    // If there are remaining elements in leftSubarray, move them into currArray
    while (leftSubIndex < leftSize)
    {
        currArray[mergedIndex] = leftSubarray[leftSubIndex];
        leftSubIndex++;
        mergedIndex++;
    }

    // If there are remaining elements in rightSubarray, move them into currArray
    while (rightSubIndex < rightSize)
    {
        currArray[mergedIndex] = rightSubarray[rightSubIndex];
        rightSubIndex++;
        mergedIndex++;
    }
    mergeCount++;
    return invCount;
}

unsigned int MergeSort(int currArray[], int leftIndex, int rightIndex)
{
    unsigned int totalInversion = 0;
    // When the array has been divided into single elements, stop the recursion
    if (leftIndex >= rightIndex)
        return totalInversion;

    // midIndex will change with each recursive pass
    int midIndex = (rightIndex + leftIndex) / 2;
    
    // Recursively divide the left and right subarray in half until there are only single elements
    totalInversion += MergeSort(currArray, leftIndex, midIndex);
    totalInversion += MergeSort(currArray, midIndex+1, rightIndex);

    // Merge the single elements into a sorted array
    totalInversion += Merge(currArray, leftIndex, midIndex, rightIndex);

    return totalInversion;
}

int main()
{
    //int array[] = { 12, 11, 13, 5, 6, 7, 10, 9};
    int array[] = {4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    unsigned int totalInversion = MergeSort(array, 0, size-1);
    
    for (auto num : array)
        cout << num << " ";
    cout << "\nMerge Count: " << mergeCount << endl;
    cout << "Inversion Count: " << totalInversion << endl;

    return 0;
}