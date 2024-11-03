/*
Algorithm:          Bubble Sort 
Characteristics:    Sorts array in-place, stable
Time complexity:    O(N^2)
Space complexity:   O(1)
Task:               Sort an unsorted array of integers in ascending order.
Solution:           Sort the array using the Bubble Sort algorithm, which iteratively swaps two adjacent elements in the unsorted array
                    if the left element is greater than the right element. The process essentially pushes the greater elements to the
                    right until all elements have been pushed into their correct positions in the sorted array.
Resources:          https://www.geeksforgeeks.org/bubble-sort-algorithm/    
*/

#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(int arr[], int size)
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
    int numArray[] = {23, 13, 19, 2, 7, 15, 19};
    int arrSize = sizeof(numArray) / sizeof(numArray[0]);
    BubbleSort(numArray, arrSize);

    for (auto num : numArray)
        cout << num << " ";
    
    return 0;
}