'''
Algorithm:          Greatest Common Divisor by Subtraction (LeetCode Problem #1979)

Task:               Given an array of integers, return the greatest common divisor of the largest and smallest integer in the array.

Solution:           Use the Euclidean algorithm to find the greatest common divisor. The algorithm is based on the principle that the
                    greatest common divisor of two numbers does not change if the larger number "a" is replaced by its difference with 
                    the smaller number "b". In this solution, we use the Euclidean algorithm by subtraction by recursively subtracting
                    the larger number from the smaller number until both numbers are equal to each other, which indicates that the value
                    of both "a" and "b" is the greatest common divisor.
                    Example:
                        when a = 252 and b = 105
                            init.   a = 252, b = 105
                            1.      252 > 105   a = 252 - 105 = 147,  b = 105
                            2.      147 > 105   a = 147 - 105 = 42,   b = 105
                            3.      42  < 105   a = 42,               b = 105 - 42 = 63
                            4.      42  < 63    a = 42                b = 63 - 42 = 21
                            5.      42  > 21    a = 42 - 21 = 21      b = 21
                            6       21 == 21    return 21

Time complexity:    O(N)
                        N = number of steps required to make "a" equal to "b"

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
'''


def GCD(a, b):
    # Base case; if a equals b, return the GCD.
    if (a == b):
        return a
    # If a is the larger number, subtract b from a and recursively call GCD().
    elif (a > b):
        return GCD(a - b, b)
    # If b is the larger number, subtract a from b recursively call GCD().
    else:
        return GCD(a, b - a)

# Wrapper for GCD(); passes the largest and smallest integers in nums to GCD() as arguments.
def find_GCD(nums: list[int]):
    # NOTE: min() and max() both give the time complexity O(N).
    a = max(nums)
    b = min(nums)
    return GCD(a, b)

if __name__ == "__main__":
    # Test case 1.
    nums = [4, 5, 6, 9, 10]
    print(f"Greatest common divisor: {find_GCD(nums)}")

    # Test case 2.
    nums = [105, 132, 155, 205, 252]
    print(f"Greatest common divisor: {find_GCD(nums)}")