'''
Algorithm:          Majority Element using Dictionary (LeetCode Problem #169)

Task:               Given an array nums of size n, return the majority element. The majority element is the element that appears more 
                    than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Solution:           Use a dictionary to record the frequency of each integer in nums and return the integer with the highest 
                    frequency value.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums / number of integers in the hashmap

Auxiliary space:    O(N)
                        N = number of integers in the hashmap

Resources:          https://leetcode.com/problems/majority-element/solutions/
'''


def majority_element(nums):
    intHz: dict = {0: 0}                # Stores elements in nums as keys and their frequency as values. Initialized with {0: 0}.
    majority_elem = 0                   # Current majority element.

    # Iterate through nums and record the frequency of each element. Update the majority element with nums[i] if nums[i] occurs more 
    # frequently than the majority element.
    for i in range(0, len(nums)):
        if nums[i] not in intHz:
            intHz[nums[i]] = 1
        else:
            intHz[nums[i]] += 1

        if intHz[nums[i]] > intHz[majority_elem]:
            majority_elem = nums[i]

    return majority_elem

if __name__ == "__main__":
    # Test case 1.
    nums = [3, 2, 3]
    print(majority_element(nums))

    # Test case 2.
    nums = [2, 2, 1, 1, 1, 2, 2]
    print(majority_element(nums))