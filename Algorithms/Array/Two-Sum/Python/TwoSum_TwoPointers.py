'''
Algorithm:          Two Sum using Two Pointers (LeetCode Problem #1)

Task:               Given an array of integers nums and a target value, return indices of the two numbers such that they add up to 
                    target. Assume that each input would have exactly one solution, and the same element cannot be used twice.

Solution:           Store each integer and its corresponding index in nums into an array of <int, int> pairs named "num_pairs", where the 
                    integers are stored as keys and the indices are stored as values. Then, in order to use the two pointer technique, 
                    we must sort the array by key in ascending order. Then we use the technique on the array by iteratively
                    adding the smaller values in the array with the larger values and comparing the sums to the target value. If the sum
                    is less than the target, add the next smallest value to the larger value; if the sum is less than the target, add the
                    next largest value to the smaller value; and if the sum is equal to the target, return the indices of the integers 
                    used to produce that sum. 

Time complexity:    O(N)
                        N = the number of integers in nums / number of integers in nums to be sorted
                        NOTE: sorted() uses the Timsort algorithm, which gives time complexity O(N * log(N))

Space complexity:   O(N)
                        N = number of elements in nums and num_pairs

Auxiliary space:    O(N)
                        N = number of pairs in num_pairs

Resources:          https://leetcode.com/problems/two-sum/solutions/
                    https://www.datacamp.com/tutorial/sort-a-dictionary-by-value-python
'''

def twoSum(nums: list[int], target: int) -> list[int]:
    # Store the integers in nums as keys and their corresponding indices as values in num_pairs.
    num_pairs = {}
    for i in range(len(nums)):
        num_pairs[nums[i]] = i

    # Sort num_pairs by key in ascending order with sorted(); a lambda function is used to specify num_pairs should be sorted.
    num_pairs = dict(sorted(num_pairs.items(), key=lambda item: item[0], reverse=False))

    left_i = 0                  # Index of the smaller integer in nums. Initialized as the first index.
    right_i = len(nums) - 1     # Index of the larger integer in nums. Initialized as the last index.

    while (left_i < right_i):
        
        # Calculate the sum of keys at left_i and right_i.
        sum = list(num_pairs.keys())[left_i] + list(num_pairs.keys())[right_i]

        # If the sum is equal to the target, return the indices of num_pairs[left_i] and num_pairs[right_i].
        if sum == target:
            index_1 = list(num_pairs.values())[left_i]          # Index of num_pairs[left_i]
            index_2 = list(num_pairs.values())[right_i]         # Index of num_pairs[right_i]
            return [index_1, index_2]
        # If the sum is less than the target, move to the next smallest integer.
        elif sum < target:
            left_i += 1
        # If the sum is greater than the target, move to the next largest integer.
        elif sum > target:
            right_i -= 1

    # If the target is not found, return None.
    return None

# Test case 1
nums = [2, 7, 22, 15]
target = 9
result = twoSum(nums, target)
print(result)

# Test case 2
nums = [3, 2, 4]
target = 6
result = twoSum(nums, target)
print(result)

# Test case 3
nums = [2, 1]
target = 4
result = twoSum(nums, target)
print(result)