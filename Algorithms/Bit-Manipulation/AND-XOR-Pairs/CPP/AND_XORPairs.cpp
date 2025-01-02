/*
Algorithm:          AND XOR Pairs

Task:               For an array "arr" of n positive integers, count the unordered pairs (i, j) where 0 <= i < j < n and 
                    arr[i] XOR arr[j] > arr[i] AND arr[j]. XOR denotes the bitwise XOR operation and AND denotes the AND bitwise 
                    operation.

Solution:           Use two for loops to iteratively check each unordered pair in arr that meets the constraint 0 <= i < j < n. Perform
                    a XOR and AND operation on each unordered pair; if the XOR result is greater than the AND result, increment the
                    count by one. After the for loops have exited, return the final count.

Time complexity:    O(N^2)
                        N = number of integers in arr

Space complexity:   O(N)
                        N = number of integers in arr

Auxiliary space:    O(1)

Resources:          
*/


#include <iostream>
using std::cout;
using std::endl;

int validUnorderedPairs(int arr[], int size)
{
    int count = 0;      // Track number of pairs that meet the criteria XOR > AND.

    // Iteratively check each unordered pair in arr that meets the given constraint 0 <= i < j < n. 
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // Perform XOR and AND on the unordered pairs. If the XOR result is greater than the AND result, increment count by 1.
            if ((arr[i] ^ arr[j]) > (arr[i] & arr[j]))
                count++;
        }
    }

    return count;
}

int main()
{
    int arr[4] = {4, 3, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << validUnorderedPairs(arr, size);

    return 0;
}