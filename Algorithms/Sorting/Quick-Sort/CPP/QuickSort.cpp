/*
Algorithm:          Quick Sort

Task:               Use an unstable divide-and-conquer sorting algoritm to sort an array of integers in ascending order.

Solution:           Sort the array using the Quick Sort algorithm, which sorts elements of an array according the chosen pivot value. 
                    Elements larger than the pivot are moved to the right of the array and elements smaller than the pivot are moved to 
                    the left. Then, put the pivot into the correct position, partition the array into two subarrays (the pivot element
                    is not included in either subarray), and recursively repeat the process until the array is sorted. In this solution, 
                    the rightmost element of the array is chosen to be the pivot.

Time complexity:    Best-case/Average-case: O(N*log(N)); N = number of elements to be sorted
                    Worst-case: O(N^2); N = number of elements to be sorted
                    NOTE: worst-case occurs if the chosen pivot is the smallest number in array.
                      
Space complexity:   Best-case/Average-case: O(log(N)); N = size of each partition
                    Worst-case: O(N); N = size of each partition + maximum depth of the recursion stack

Resources:          https://www.geeksforgeeks.org/quick-sort-algorithm/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::swap;

// partition() has time average-case time complexity O(N).
int partition(int arr[], int leftIndex, int rightIndex)
{
    int pivot = arr[rightIndex];        // The pivot is the rightmost element of arr.
    int i = leftIndex - 1;              // Index of arr where the element that is less than pivot is placed. Initialized as -1.

    // Compare each element in arr to pivot.
    for (int j = leftIndex; j < rightIndex; j++)
    {
        // If the current element is less than pivot, swap the current element with the ith element on the left side of arr.
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot into its correct position in arr by swapping it with the (i+1)th element.
    swap(arr[i+1], arr[rightIndex]);

    // Return the index of the pivot, which is used to form the next partition.
    return i + 1;
}

// quickSort() has average-case time complexity O(log(N)).
void quickSort(int arr[], int leftIndex, int rightIndex)
{
    // Base case; if the left index passes the right index, return.
    if (leftIndex >= rightIndex)
        return;
    
    // Determine the index of the pivot and use it to establish two subarrays.
    int partIndex = partition(arr, leftIndex, rightIndex);

    // Recursively partition arr into subarrays, excluding the pivot element.
    quickSort(arr, leftIndex, partIndex - 1);
    quickSort(arr, partIndex + 1, rightIndex);
}

int main()
{
    int nums[] = {13, 19, 9, 12, 8, 7, 4, 2, 6, 11};
    int size = sizeof(nums) / sizeof(nums[0]);
    quickSort(nums, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}