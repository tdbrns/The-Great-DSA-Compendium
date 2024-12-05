'''
Algorithm:          Maximum Subarray Sum (LeetCode Problem #53)

Task:               Given an integer array, find the subarray with the largest sum and return the sum.

Solution:           Basically, we must find the "maximum subarray" of the given array, which is the subarray of whose elements, when 
                    added together, give the largest sum of any other subarray. This is done using Kadane's algorithm, which involves
                    iteratively adding up each integer in the array and keeping track of the largest sum that is given by adding up
                    a certain contiguous sequence of integers in the array.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
'''

def maxSubarraySum(nums: list[int]) -> int:
    currMax = nums[0]       # Largest value between the sum of the current subarray and nums[i].
    maxSum = nums[0]        # Sum of the maximum subarray in nums.

    for i in range(1, len(nums)):
        currMax = max(currMax + nums[i], nums[i])
        maxSum = max(currMax, maxSum)
    
    return maxSum
'''maxSubarraySum() when nums = [3, 2, -1, 7, -8, 3, 2]
    init.   currMax = 3   maxSum = 3
    1.      nums[i] = 2   currMax = max(3+2, 3) = 5       maxSum = max(5, 3) = 5
    2.      nums[i] = -1  currMax = max(5+(-1), -1) = 4   maxSum = max(5, 4) = 5
    3.      nums[i] = 7   currMax = max(4+7, 7) = 11      maxSum = max(11, 5) = 11
    4.      nums[i] = -8  currMax = max(11+(-8), -8) = 3  maxSum = max(3, 11) = 11
    5.      nums[i] = 3   currMax = max(3+3, 3) = 6       maxSum = max(6, 11) = 11
    6.      nums[i] = 2   currMax = max(6+2, 2) = 8       maxSum = max(8, 11) = 11
    return 11
'''

nums = [3, 2, -1, 7, -8, 3, 2]
print(maxSubarraySum(nums))
# [3, 2, -1, 7] is the subarray with the largest sum.

nums - [5, 4, -1, 7, 8]
print(maxSubarraySum(nums))
# [5, 4, -1, 7, 8] is the subarray with the largest sum.

nums = [1]
print(maxSubarraySum(nums))
# [1] is the subarray with the largest sum.