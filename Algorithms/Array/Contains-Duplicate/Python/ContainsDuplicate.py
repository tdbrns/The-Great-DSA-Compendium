'''
Algorithm:          Contains Duplicate using Hashset (LeetCode Problem #217)

Task:               Given an integers array nums, return true if any value appears at least twice, and return false if every element is
                    distinct.

Solution:           Iterate though nums while storing the frequency of each integer into a hashmap. If any integer has a frequency value 
                    greater than 1, return false; otherwise, return true.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums / number of elements in the hashmap

Auxiliary space:    O(N)
                        N = number of elements in the hashmap

Resources:          https://leetcode.com/problems/contains-duplicate/solutions/
                    https://www.geeksforgeeks.org/check-if-the-given-input-contains-duplicates/
'''


def containsDuplicate(nums) -> bool:
    intSet = set()        # Hashset storing elements in nums as keys.

    # Iteratively store each value in nums in intSet.
    for i in range(0, len(nums)):
        # If the current value is already in intSet, return True; otherwise, return false.
        if nums[i] in intSet:
            return True
        else:
            intSet.add(nums[i])
    return False

if __name__ == "__main__":
    # Test case 1.
    nums = [1, 2, 3, 1]
    print(containsDuplicate(nums))

    # Test case 2.
    nums = [1, 2, 3, 4]
    print(containsDuplicate(nums))

    # Test case 3.
    nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    print(containsDuplicate(nums))

