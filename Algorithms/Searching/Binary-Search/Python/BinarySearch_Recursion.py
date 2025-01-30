'''
Algorithm:          Recursive Binary Search

Task:               Use a divide-and-conquer algorithm to find a specific integer in an array this is sorted in either ascending or 
                    descending order.

Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares its value to the target value to determine whether the target is in the left or the right 
                    side of the array. If the target value is on one side of the centermost element, the other side of the centermost 
                    element will be omitted from the search, and the side in which the target resides will be split by its own 
                    centermost value and follow the same process. This process of of splitting subarrays will continue until the 
                    centermost element value is equal to the target value or the subarray can no longer be split.
                    
Time complexity:    O(log(N)); N = number of integers in the array

Space complexity:   O(N); N = maximum depth of the recursive call stack / number of integers in the array

Auxiliary space:    O(N); N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/binary-search/
'''


def recursive_binary_search_ascend(nums, left_i, right_i, target) -> bool:
    if left_i <= right_i:
        mid_i = left_i + (right_i - left_i) // 2    # Index of centermost element in nums.

        # Base case; if nums[mid_i] is equal to the target, return True.
        # If nums[mid_i] is greater than target, let right_i = mid_i-1 to omit the right subarray and recur.
        # If nums[mid_i] is less than target, let left_i = mid_i+1 to omit the left subarray and recur.
        if nums[mid_i] == target:
            return True
        if nums[mid_i] > target:
            return recursive_binary_search_ascend(nums, left_i, mid_i - 1, target)
        return recursive_binary_search_ascend(nums, mid_i + 1, right_i, target)
        
    # If target was not found, return False.
    return False

def recursive_binary_search_descend(nums, left_i, right_i, target) -> bool:
    if left_i <= right_i:
        mid_i = left_i + (right_i - left_i) // 2    # Index of centermost element in nums.

        # Base case; if nums[mid_i] is equal to the target, return True.
        # If nums[mid_i] is greater than target, let left_i = mid_i+1 to omit the left subarray and recur.
        # If nums[mid_i] is less than target, let right_i = mid_i-1 to omit the right subarray and recur.
        if nums[mid_i] == target:
            return True
        if nums[mid_i] > target:
            return recursive_binary_search_ascend(nums, mid_i + 1, right_i, target)
        return recursive_binary_search_ascend(nums, left_i, mid_i - 1, target)
        
    # If target was not found, return False.
    return False

# Determine whether to perform ascending or descending binary search.
def recursive_binary_search(nums, target) -> bool:
    left_i = 0                      # Index of first element in nums.
    right_i = len(nums) - 1         # Index of last element in nums.

    if nums[0] <= nums[len(nums) - 1]:
        return recursive_binary_search_ascend(nums, left_i, right_i, target)
    return recursive_binary_search_descend(nums, left_i, right_i, target)

if __name__ == "__main__":
    # Test case 1.
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    target = 1
    foundTarget: bool = recursive_binary_search(nums, target)
    print(f"{target} is in the array") if foundTarget else print(f"{target} is not in the array")

    # Test case 2.
    nums = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    target = 8
    foundTarget = recursive_binary_search(nums, target)
    print(f"{target} is in the array") if foundTarget else print(f"{target} is not in the array")
