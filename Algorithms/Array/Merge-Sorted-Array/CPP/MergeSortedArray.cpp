/*
Algorithm:          Merge Sorted Array (LeetCode Problem #88)

Task:               You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
                    representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array 
                    sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored 
                    inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the 
                    elements that should be merged, and the last n elements are considered "vacant," meaning they should be set to 0 
                    ignored.

Solution:           Since nums1 and nums2 are already sorted in non-decreasing order and the remaining positions of nums1 are filled 
                    with an n number of 0s, the best way to approach this task is to find the largest number of nums1 and nums2 and 
                    place it at the rightmost position of nums1 that contains a 0.

Time complexity:    O(M + N)
                        M = size of nums1
                        N = size of nums2

Space complexity:   O(M + N)
                        M = size of nums1
                        N = size of nums2

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/merge-sorted-array/solutions/
*/

#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    if (n > 0)
    {
        int n1_i = m - 1;               // The current value in nums1, initialized as the rightmost value in nums1, excluding the 0s.
        int n2_i = n - 1;               // The current value in nums2, initialized as the rightmost value in nums2.
        int n1Zero_i = m + n - 1;       // The rightmost value in nums1 that is a 0; it will either hold the value at n1_i or n2_i. 

        while (n2_i > -1)
        {
            // If all the values of nums1 have been checked, move the value at n2_i in nums2 to n1Zero_i in nums1.
            // Move on to check the next value in nums2.
            if (n1_i == -1)
            {
                nums1[n1Zero_i] = nums2[n2_i];
                nums2[n2_i] = 0;                // n2_i in nums2 is now vacant.
                n2_i--;
                n1Zero_i--;
            }
            // If the current value in nums1 is less than or equal to the current value in nums2, perform the same task in the statement
            // above.
            else if (nums1[n1_i] <= nums2[n2_i])
            {
                nums1[n1Zero_i] = nums2[n2_i];
                nums2[n2_i] = 0;                // n2_i in nums2 is now vacant.
                n2_i--;
                n1Zero_i--;
            }
            // If the current value in nums1 is greater than the current value in nums2, move that value to n1Zero_i in nums1. Move on
            // to check the next value in nums1.
            else if (nums1[n1_i] > nums2[n2_i])
            {
                nums1[n1Zero_i] = nums1[n1_i];
                nums1[n1_i] = 0;                // n1_i in nums1 is now vacant.
                n1_i--;
                n1Zero_i--;
            }
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = nums1.size() - nums2.size();
    int n = nums2.size();
    mergeSortedArray(nums1, m, nums2, n);

    for (auto num : nums1)
        cout << num << " ";

    return 0;
}