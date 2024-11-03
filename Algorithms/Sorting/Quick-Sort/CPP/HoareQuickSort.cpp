/*
Algorithm:          Quick Sort using Hoare's Partitioning Scheme
Characteristics:    Not in-place, unstable, divide-and-conquer
Task:               Sort an unsorted array of integers in ascending order.
Solution:           Sort the array using the Quick Sort algorithm, which sorts array (vector) elements according the chosen
                    pivot value; elements larger than the pivot are moved to the right of the array and elements smaller than the 
                    pivot are moved to the left. Then, t the pivot into the correct position, divides the array in two, and repeats
                    the process until the array is sorted. In this program, the first element of the array is chosen to be the pivot, 
                    and Hoare's partitioning scheme is used.
Time complexity:    O(N*log(N)) in best-case / average-case; O(N^2) in worst-case
                        Worst-case occurs if the last element is the pivot when the array is sorted in descending order or if the first
                        element is the pivot when the array is sorted in ascending order.
Space complexity:   O(log(N)) in best-case / average-case; O(N) in worst-case
Resources:          https://www.youtube.com/watch?v=Hoixgm4-P4M
                    https://www.geeksforgeeks.org/quick-sort-algorithm/
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition() gives time complexity O(N)
int Partition(vector<int>& arr, int firstIndex, int lastIndex)
{
    int pivot = arr[firstIndex];                // The pivot is the first element of arr
    int leftPointer = firstIndex - 1;           // The left pointer of arr
    int rightPointer = lastIndex + 1;           // The right pointer of arr

    while (true)
    {
        // Traverse array to the left from the leftmost element until a number greater than or equal to pivot is found
        do
        {
            leftPointer++;
        } while (arr[leftPointer] < pivot);

        // Traverse array to the right from the rightmost element until a number less than or equal to pivot is found
        do
        {
            rightPointer--;
        } while (arr[rightPointer] > pivot);
        
        // When the two pointers meet, or if the right pointer has passed the left pointer during traversal, return the right pointer
        // as the new lastIndex of the left partition and the new firstIndex of the right partition
        if (leftPointer >= rightPointer)
            return rightPointer;
        
        // Swap the element that is >= pivot with the element that is <= pivot
        swap(arr[leftPointer], arr[rightPointer]);
    }

    return 0;
}

// QuickSrt() gives time complexity O(log(n))
void QuickSort(vector<int>& arr, int firstIndex, int lastIndex)
{
    // If there is only a single element left in a partition, return
    if (firstIndex >= lastIndex)
        return;
    
    // The partition index determines how the two partitions are split
    // The element arr[partitionIndex] is in its correct place in the sorted array
    int partitionIndex = Partition(arr, firstIndex, lastIndex);

    // Recursively divide the left partition (smaller side of sorted array)
    QuickSort(arr, firstIndex, partitionIndex);
    // Recursively divide the right partition (larger side of the sorted array)
    QuickSort(arr, partitionIndex + 1, lastIndex);
}

int main()
{
    vector<int> numVect = {10, 7, 8, 9, 1, 5};
    QuickSort(numVect, 0, numVect.size()-1);

    for (auto num : numVect)
        cout << num << ' ';
    cout << endl;

    return 0;
}