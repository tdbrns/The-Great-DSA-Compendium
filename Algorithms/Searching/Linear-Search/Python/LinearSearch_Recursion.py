'''
Algorithm:          Linear Search using Iteration

Task:               Use a brute force algorithm to find a specific integer in a sorted array.

Solution:           Search for the target value in the sorted array using a Linear Search algorithm, which checks each element in the 
                    sorted array in order starting from the first element until the target value is found or there are no more elements
                    to check.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array / maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https:#www.geeksforgeeks.org/linear-search/
'''


def recursive_linear_search(nums, target, i) -> bool:
    # i = index of the current element being checked.
    # Base case; if nums[i] is equal to the target, return True.
    # Base case; if i >= nums.size(), return false.
    # If nums[i] is not equal to target, let i = i + 1 and recur.
    if i < len(nums):
        if nums[i] == target:
            return True
        return recursive_linear_search(nums, target, i + 1)
    return False

if __name__ == "__main__":
    # Test case 1.
    nums = [5, 13, 24, 27, 33, 40, 41]
    target = 33
    i = 0
    targetFound: bool = recursive_linear_search(nums, target, i)
    print(f"{target} is in the array") if targetFound else print(f"{target} is not in the array")

    # Test case 2.
    target = 32
    targetFound: bool = recursive_linear_search(nums, target, i)
    print(f"{target} is in the array") if targetFound else print(f"{target} is not in the array")