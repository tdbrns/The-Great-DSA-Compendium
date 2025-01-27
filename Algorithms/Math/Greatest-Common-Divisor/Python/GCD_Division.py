'''
Algorithm:          Greatest Common Divisor using Division (LeetCode Problem #1979)

Task:               Given an array of integers, return the greatest common divisor of the largest and smallest integer in the array.

Solution:           Use the Euclidean algorithm to find the greatest common divisor. The algorithm is based on the principle that the
                    greatest common divisor of two numbers does not change if the larger number "a" is replaced by its difference with 
                    the smaller number "b". In this solution, we use the Euclidean algorithm with division which involves recursively
                    replacing "a" with "b" and replacing "b" with the remainder of "a" divided by "b"; this process is repeated until
                    "b" equals 0, which indicates that the value of "a" is the greatest common divisor.
                    Example:
                        when a = 252 and b = 105
                            init.   a = 252, b = 105
                            1.      a = 105, b = 252 mod 105 = 42
                            2.      a = 42, b = 105 mod 42 = 21
                            3.      a = 21, b = 42 mod 21 = 0
                            return 21

Time complexity:    O(log(B))
                        B = the smaller number

Space complexity:   O(N)
                        N = number of integers in the array

Auxiliary space:    O(1)

Resources:          https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
                    https://www.baeldung.com/cs/euclid-time-complexity
'''


def GCD(a, b):
    # Base case; if b equals 0, return a.
    if b == 0:
        return a
    
    # Recursively perform the Euclidean algorithm with division.
    return GCD(b, a % b)

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