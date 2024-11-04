/*
Algorithm:          Insertion Sort 

Task:               Use a stable sorting algorithm to sort an array of integers in-place in ascending order.

Solution:           Sort the array using the Insertion Sort algorithm, which iteratively inserts the elements of the unsorted array into
                    the a sorted portion of the array until all elements are placed in their correct position in the sorted array.
                    
Time complexity:    O(N^2); N = number of integers to be sorted
                    - Worst-case scenario occurs when the array in sorted in the descending order.

Space complexity:   O(1)

Resources:          https://www.geeksforgeeks.org/insertion-sort-algorithm/
*/

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size)
{
    for (int keyIndex = 1; keyIndex < size; keyIndex++)
    {
        // keyValue is the current pivot value. The values to the left of keyValue will form the sorted portion of the array.
        int keyValue = arr[keyIndex];

        // leftIndex is the index of value to the left of keyValue.
        int leftIndex = keyIndex - 1;      

        // If the element left of keyValue is greater than keyValue, swap it with keyValue. Each element to left of the current keyValue 
        // will be iteratively checked like this until leftIndex < 0 or until the element left of keyValue in the array is not greater 
        // than keyValue, which indicates that the sorted portion of the array is truly sorted.
        while(leftIndex >= 0 && arr[leftIndex] > keyValue)
        {
            arr[leftIndex + 1] = arr[leftIndex];
            leftIndex -= 1;
        }

        // Once the values to the left of keyValue are sorted, make the value to the left of 
        arr[leftIndex + 1] = keyValue;
    }
}

int main()
{
    int numArray[] = {5, 4, 7, 12, 9, 7, 2};
    int arrSize = sizeof(numArray) / sizeof(numArray[0]);
    InsertionSort(numArray, arrSize);

    for (auto num : numArray)
        cout << num << " ";

    return 0;
}