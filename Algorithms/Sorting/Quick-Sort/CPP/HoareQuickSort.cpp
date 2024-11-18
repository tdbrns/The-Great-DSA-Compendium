/*
Algorithm:          Quick Sort using Hoare's Partitioning Scheme

Task:               Use an unstable divide-and-conquer sorting algoritm to sort an array of integers in ascending order.

Solution:           Sort the array using the Quick Sort algorithm, which sorts array (vector) elements according the chosen pivot value. 
                    Elements larger than the pivot are moved to the right of the array and elements smaller than the pivot are moved to 
                    the left. Then, put the pivot into the correct position, divide the array in two, and repeat the process until the 
                    array is sorted. In this solution, the leftmost element of the array is chosen to be the pivot, and Hoare's 
                    partitioning scheme is used to divide the array according to the pivot.

Time complexity:    Best-case/Average-case: O(N*log(N)); N = number of elements to be sorted
                    Worst-case: O(N^2); N = number of elements to be sorted
                    NOTE: worst-case occurs if the chosen pivot is the smallest number in the array.
                      
Space complexity:   Best-case/Average-case: O(log(N)); N = size of each partition
                    Worst-case: O(N); N = size of each partition + meximum depth of the recursion stack

Resources:          https://www.youtube.com/watch?v=Hoixgm4-P4M
                    https://www.geeksforgeeks.org/quick-sort-algorithm/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::swap;

// partition() has time complexity O(N)
int partition(vector<int>& arr, int firstIndex, int lastIndex)
{
    int pivot = arr[firstIndex];                // The pivot is the first element of arr.
    int leftPointer = firstIndex - 1;           // The left pointer of arr.
    int rightPointer = lastIndex + 1;           // The right pointer of arr.

    while (true)
    {
        // Traverse array to the left from the leftmost element until a number greater than or equal to pivot is found.
        do
        {
            leftPointer++;
        } while (arr[leftPointer] < pivot);

        // Traverse array to the right from the rightmost element until a number less than or equal to pivot is found.
        do
        {
            rightPointer--;
        } while (arr[rightPointer] > pivot);
        
        // When the two pointers meet, or if the right pointer has passed the left pointer during traversal, return the right pointer
        // as the new lastIndex of the left partition and the new firstIndex of the right partition.
        if (leftPointer >= rightPointer)
            return rightPointer;
        
        // Swap the element that is >= pivot with the element that is <= pivot.
        swap(arr[leftPointer], arr[rightPointer]);
    }

    return 0;
}

// quickSort() has time complexity O(log(n))
void quickSort(vector<int>& arr, int firstIndex, int lastIndex)
{
    // If there is only a single element left in a partition, return
    if (firstIndex >= lastIndex)
        return;
    
    // The partition index determines how the two partitions are split
    // The element arr[partitionIndex] is in its correct place in the sorted array
    int partitionIndex = partition(arr, firstIndex, lastIndex);

    // Recursively divide the left partition (smaller side of sorted array)
    quickSort(arr, firstIndex, partitionIndex);
    // Recursively divide the right partition (larger side of the sorted array)
    quickSort(arr, partitionIndex + 1, lastIndex);
}

int main()
{
    vector<int> nums = {10, 7, 8, 9, 1, 5};
    quickSort(nums, 0, nums.size()-1);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;

    return 0;
}