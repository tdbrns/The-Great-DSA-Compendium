/*
Algorithm:          Bubble Sort 

Task:               Use a stable sorting algorithm that sorts an array of integers in-place in ascending order.

Solution:           Sort the array using the Bubble Sort algorithm, which iteratively swaps two adjacent elements in the unsorted array
                    if the left element is greater than the right element. The process essentially pushes the greater elements to the
                    right until all elements have been pushed into their correct positions in the sorted array.

Time complexity:    O(N^2)
                        N = number of integers to be sorted
                        NOTE: worst-case scenario occurs when the array in sorted in the descending order.

Space complexity:   O(N)
                        N = number of intgers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/bubble-sort-algorithm/    
*/

#include <iostream>
#include <vector>
using std::cout;
using std::swap;

void bubbleSort(int arr[], int size)
{
    bool swapped;       // Whether or not at least two of the elements have been swapped

    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            // If the left element is greater than the right element, swap them
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If none of the elements in arr were swapped in this iteration, then the array has been sorted and there's no need to continue.
        if (!swapped)
            break;
    }
}

int main()
{
    int nums[] = {23, 13, 19, 2, 7, 15, 19};
    int size = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, size);
    
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    
    return 0;
}