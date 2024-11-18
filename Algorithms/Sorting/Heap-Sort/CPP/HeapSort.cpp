/*
Algorithm:          Heap Sort 

Task:               Use an unstable, divide-and-conquer sorting algorithm to sort an array of integers in-place in ascending order.

Solution:           Sort the array using the Heap Sort algorithm, which transforms the unsorted array into a max-heap - a binary tree
                    wherein the parent nodes are always greater than its child nodes and the root is the largest value in the unsorted
                    part of the array.

Time complexity:    O(N*log(N)); N = number of integers to be sorted
                    NOTE: worst-case scenario occurs when the array in sorted in the descending order.

Space complexity:   O(1)

Resources:          https://www.geeksforgeeks.org/heap-sort/      
*/

#include <iostream>
using std::cout;
using std::swap;

void maxHeapify(int arr[], int size, int index)
{
    // In a max-heap, the largest value must be the root of the heap.
    // Set index as the root of the heap.
    int indexOfLargest = index;
    
    // Indices of the left and right child nodes.
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    
    // If the left child from arr[] is greater than the root, set the left child as the root.
    if (leftIndex < size && arr[leftIndex] > arr[indexOfLargest])
        indexOfLargest = leftIndex;
    
    // If the right child from arr[] is greater than the root, set the right child as the root.
    if (rightIndex < size && arr[rightIndex] > arr[indexOfLargest])
        indexOfLargest = rightIndex;
    
    // If index is no longer the root of the heap (i.e., if the largest value is not the root), swap the value of arr[index] with that
    // of arr[indexOfLargest].
    if (indexOfLargest != index)
    {
        swap(arr[index], arr[indexOfLargest]);
        maxHeapify(arr, size, indexOfLargest);
    }
}

void heapSort(int arr[], int size)
{
    // Transform arr[] into a max-heap with the largest element as its root.
    // Once this for loop is completed, the largest element will be the first element (arr[0]) of the array.
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(arr, size, i);
    
    // Swap largest element (arr[0]) with smallest element (arr[i]), which puts arr[0] in its correct position in the sorted array.
    // Then, call maxHeapify to turn the heap back into a max-heap with the largest element as the root.
    // Note: the elements that are placed in their correct position are not included in the maxHeapify call.
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, size);

    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";

    return 0;
}