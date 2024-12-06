'''
Algorithm:          Two Sum using Hashmap (LeetCode Problem #1)

Task:               Given an array of integers nums and a target value, return indices of the two numbers such that they add up to 
                    target. Assume that each input would have exactly one solution, and the same element cannot be used twice.

Solution:           Iteratively subtract every integer in the array from the target value and store each difference (compliment) 
                    into a hash map (dictionary). With each iteration, check the hash map to see if the current difference exists in the
                    hash map; if it does exist, then the current difference is a compliment of the current number in the array that will
                    add up to target.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array and the hash map

Auxiliary space:    O(N)
                        N = number of integers in the hash map

Resources:          https://leetcode.com/problems/two-sum/solutions/
'''

def twoSum(nums: list[int], target: int) -> list[int]:
    mp = {}         # Dictionary that stores integers in nums as keys and integers' index in nums as values.

    for i in range(len(nums)):
        compliment = target - nums[i]       # Integer that, when added to nums[i], would equal target.

        # If the compliment exists in the dictionary, return the index of compliment and nums[i].
        if compliment in mp:
            return {mp[compliment], i}
        # Otherwise, store nums[i] and its index into mp.
        else:
            mp[nums[i]] = i
    
    # If compliment is never found in mp, return None.
    return None

nums = [2, 7, 11, 15]
target = 9
result = twoSum(nums, target)
print(result)  

nums = [3, 2, 4]
target = 6
result = twoSum(nums, target)
print(result)

nums = [2, 1]
target = 4
result = twoSum(nums, target)
print(result)