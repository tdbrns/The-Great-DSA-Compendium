/*
Algorithm:          Heap Sort 

Task:               Use an unstable, divide-and-conquer sorting algorithm to sort an array of integers in-place in ascending order.

Solution:           Sort the array using the Heap Sort algorithm, which transforms the unsorted array into a max-heap - a binary tree
                    wherein the parent nodes are always greater than its child nodes and the root is the largest value in the unsorted
                    part of the array. The elements in the array are rearranged into a max-heap in-place, without creating an additional
                    data structure like a binary search tree to hold the element values. This can be done because

Time complexity:    O(N * log(N))
                        N = number of integers to be sorted
                        NOTE: worst-case scenario occurs when the array in sorted in the descending order.

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/heap-sort/
                    https://www.youtube.com/watch?v=2DmK_H7IdTo    
*/

#include <iostream>
using std::cout;
using std::swap;

// maxHeapify() has time complexity O(N).
void maxHeapify(int arr[], int size, int index)
{
    // NOTE: in a max-heap, the largest value must be the root of the heap.
    int rootIndex = index;              // Index of the root of the heap.
    int leftIndex = 2 * index + 1;      // Index of the left child of the root.
    int rightIndex = 2 * index + 2;     // Index of the right child of the root.
    
    // If the left child is greater than the root, set the left child as the root.
    if (leftIndex < size && arr[leftIndex] > arr[rootIndex])
        rootIndex = leftIndex;
    
    // If the right child is greater than the root, set the right child as the root.
    if (rightIndex < size && arr[rightIndex] > arr[rootIndex])
        rootIndex = rightIndex;
    
    // If arr[index] is no longer the root of the heap, swap arr[index] withS arr[rootIndex] and recursively max-heapify arr.
    if (rootIndex != index)
    {
        swap(arr[index], arr[rootIndex]);
        maxHeapify(arr, size, rootIndex);
    }
}

// heapSort() has time complexity O(log(N)).
void heapSort(int arr[], int size)
{
    // Transform arr[] into a max-heap with the largest element as its root.
    // Once this for loop is complete, the largest element will be arr[0].
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(arr, size, i);

    // 
    for (int i = size - 1; i > 0; i--)
    {
        // Swap largest element (arr[0]) with smallest element (arr[i]), which puts arr[0] in its correct position in the sorted array.
        swap(arr[0], arr[i]);

        // Call maxHeapify() to turn the heap back into a max-heap with the largest element as the root. The elements that have been 
        // placed into their correct positions in the sorted array will not be included in the function call.
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int nums[] = { 2, 8, 5, 3, 9, 1 };
    /* Binary tree created by nums.
                    2
                  /   \
                 8     5
                / \   /
               3   9 1
    */
   
    int size = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, size);

    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";

    return 0;
}