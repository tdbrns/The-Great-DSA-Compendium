'''
Algorithm:          Majority Element (LeetCode Problem #169)

Task:               Given an array nums of size n, return the majority element. The majority element is the element that appears more 
                    than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Solution:           Starting at the first element in nums, iterate through each element while keeping track of an "majority score" - a
                    counter used to determine if the current element nums[i] is the majority element. 
                    Scoring rules:
                        • If the score equals 0 during the current iteration, nums[i] is the new majority element.
                        • If nums[i] is the current majority element, add 1 to the score.
                        • If nums[i] is not the current majority element, subtract 1 from the score.
                    The last integer to be considered the majority element is returned.

Time complexity:    O(N)
                        N = number of integers in nums

Space complexity:   O(N)
                        N = number of integers in nums

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/majority-element/solutions/
'''


def majority_element(nums):
    majority_elem = 0               # Current majority element.
    majority_score = 0              # Score determining if current element is the majority element.

    # Iterate through nums while recording the majority score as described.
    for i in range(0, len(nums)):
        if majority_score == 0:
            majority_elem = nums[i]
        
        if majority_elem == nums[i]:
            majority_score += 1
        else:
            majority_score -= 1

    return majority_elem

if __name__ == "__main__":
    # Test case 1.
    nums = [3, 2, 3]
    print(majority_element(nums))

    # Test case 2.
    nums = [2, 2, 1, 1, 1, 2, 2]
    print(majority_element(nums))