'''
Algorithm:          Find Missing Number (LeetCode Problem #268)

Task:               Given an array of containing n unique integers in the range [0, n], find the only number in the range that is 
                    missing from the array.

Solution:           Subtract the sum of all the integers in the array from the sum of all the integers in range [0, N] and return the
                    difference, which will be the missing number.

Time complexity:    O(N)
                        N = size of the integer array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/missing-number/description/
'''


def missing_number(nums):
    range_sum = 0            # The sum of all integers in range 0 to n.
    nums_sum = 0             # The sum of all integers in nums.
    for i in range(0, len(nums) + 1):
        if i < len(nums):
            nums_sum += nums[i]
        range_sum += i
    
    # Subtract nums_sum from range_sum and return the difference.
    return range_sum - nums_sum
    

if __name__ == "__main__":
    # Test case 1.
    nums = [3, 0, 1]
    print(missing_number(nums))

    # Test case 2.
    nums = [0, 1]
    print(missing_number(nums))

    # Test case 3.
    nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
    print(missing_number(nums))