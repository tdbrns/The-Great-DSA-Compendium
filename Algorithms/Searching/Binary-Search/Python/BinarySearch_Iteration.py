'''
Algorithm:          Iterative Binary Search

Task:               Use a divide-and-conquer algorithm to find a specific integer in an array this is sorted in either ascending or 
                    descending order.

Solution:           Search for the target value in array using the Binary Search algorithm, which identifies the centermost element of 
                    the array and compares its value to the target value to determine whether the target is in the left or the right 
                    side of the array. If the target value is on one side of the centermost element, the other side of the centermost 
                    element will be omitted from the search, and the side in which the target resides will be split by its own 
                    centermost value and follow the same process. This process of of splitting subarrays will continue until the 
                    centermost element value is equal to the target value or the subarray can no longer be split.

Time complexity:    O(log(N)); N = number of integers in the array

Space complexity:   O(N); N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https:#www.geeksforgeeks.org/binary-search/
'''


def iterative_binary_search(nums, target) -> bool:
    left_i = 0                                              # Index of first element in nums.
    right_i = len(nums) - 1                                 # Index of last element in nums.
    
    # Binary search in ascending order.
    if nums[left_i] <= nums[right_i]:
        while left_i <= right_i:
            mid_index = left_i + (right_i - left_i) // 2    # Index of centermost element in nums.

            # If nums[midIndex] is the target, return true.
            # If nums[midIndex] is greater than target, let rightIndex = midIndex-1 to omit the right subarray.
            # if nums[midIndex] is less than target, let leftIndex = midIndex+1 to omit the left subarray.
            if nums[mid_index] == target:
                return True
            if nums[mid_index] > target:
                right_i = mid_index - 1
            elif nums[mid_index] < target:
                left_i = mid_index + 1

    # Binary search in descending order.
    else:
        while left_i <= right_i:
            mid_index = left_i + (right_i - left_i) // 2    # Index of centermost element in current array.

            # If nums[midIndex] is the target, return true.
            # If nums[midIndex] is greater than target, let leftIndex = midIndex+1 to omit the left subarray.
            # if nums[midIndex] is less than target, let rightIndex = midIndex-1 to omit the right subarray.
            if nums[mid_index] == target:
                return True
            if nums[mid_index] > target:
                left_i = mid_index + 1
            elif nums[mid_index] < target:
                right_i = mid_index - 1

    # If target was not found, return false.
    return False

if __name__ == "__main__":
    # Test case 1.
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    target = 1
    foundTarget: bool = iterative_binary_search(nums, target)
    print(f"{target} is in the array") if foundTarget else print(f"{target} is not in the array")

    # Test case 2.
    nums = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    target = 8
    foundTarget = iterative_binary_search(nums, target)
    print(f"{target} is in the array") if foundTarget else print(f"{target} is not in the array")
