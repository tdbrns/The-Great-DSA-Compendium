'''
Algorithm:          Linear Search using Iteration

Task:               Use a brute force algorithm to find a specific integer in a sorted array.

Solution:           Search for the target value in the sorted array using a Linear Search algorithm, which checks each element in the 
                    sorted array in order starting from the first element until the target value is found or there are no more elements
                    to check.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/linear-search/
'''

def iterative_linear_search(nums, target) -> bool:
    # Check each element in nums until target is found or there are no more elements to check.
    for i in range(0, len(nums)):
        if nums[i] == target:
            return True
    return False

if __name__ == "__main__":
    # Test case 1.
    nums = [5, 13, 24, 27, 33, 40, 41]
    target = 33
    targetFound: bool = iterative_linear_search(nums, target)
    print(f"{target} is in the array") if targetFound else print(f"{target} is not in the array")

    # Test case 2.
    target = 32
    targetFound: bool = iterative_linear_search(nums, target)
    print(f"{target} is in the array") if targetFound else print(f"{target} is not in the array")