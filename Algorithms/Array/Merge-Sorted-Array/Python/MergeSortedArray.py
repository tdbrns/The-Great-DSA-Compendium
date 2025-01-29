'''
Algorithm:          Merge Sorted Array (LeetCode Problem #88)

Task:               You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
                    representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array 
                    sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored 
                    inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the 
                    elements that should be merged, and the last n elements are considered "vacant," meaning they should be set to 0 
                    ignored.

Solution:           Since nums1 and nums2 are already sorted in non-decreasing order and the remaining positions of nums1 are filled 
                    with n 0s, the best way to approach this task is to find the largest number of nums1 and nums2, place it at the 
                    rightmost position of nums1 that contains a 0, and repeat until all the elements of nums2 have been merged into
                    nums1.

Time complexity:    O(M + N)
                        M = size of nums1
                        N = size of nums2

Space complexity:   O(M + N)
                        M = size of nums1
                        N = size of nums2

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/merge-sorted-array/solutions/
'''

# NOTE: in Python, immutable objects are passed to functions by value, and mutable objects are passed by reference. Since list objects
#       are mutable, any changes to nums1 and num2 will be reflected outside of merge().
def merge(nums1: list[int], m: int, nums2: list[int], n: int):
    if n > 0:
        n1_i = m - 1                    # Index of current nums1 element, initialized as rightmost element in nums1, excluding 0s.
        n2_i = n - 1                    # Index of current nums2 element, initialized as rightmost element in nums2.
        n1_zero_i = m + n - 1           # Index of rightmost element in nums1 that is a 0.

        while n2_i > -1:
            # If all nums1 elements have been processed, move the current nums2 element to nums1[n1_zero_i].
            if n1_i == -1:
                nums1[n1_zero_i] = nums2[n2_i]
                nums2[n2_i] = 0         # Index n2_i in nums2 is now vacant.
                n2_i -= 1
                n1_zero_i -= 1
            # If current nums1 element is less than / equal to current nums2 element, move the nums2 element to nums1[n1_zero_i].
            elif nums1[n1_i] <= nums2[n2_i]:
                nums1[n1_zero_i] = nums2[n2_i]
                nums2[n2_i] = 0         # Index n2_i in nums2 is now vacant.
                n2_i -= 1
                n1_zero_i -= 1
            # If current nums1 element is greater than current nums2 element, move the nums1 element to nums1[n1_zero_i].
            elif nums1[n1_i] > nums2[n2_i]:
                nums1[n1_zero_i] = nums1[n1_i]
                nums1[n1_i] = 0         # Index n1_i in nums1 is now vacant.
                n1_i -= 1
                n1_zero_i -= 1

if __name__ == "__main__":
    # Test case 1.
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    merge(nums1, len(nums1) - len(nums2), nums2, len(nums2))
    print(nums1)   
    