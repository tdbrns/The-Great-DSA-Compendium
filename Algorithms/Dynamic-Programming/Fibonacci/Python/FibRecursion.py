'''
Algorithm:          Fibonacci Sequence (Recursive Approach)
Task:               Use the Fibonacci algorithm to print the nth number in the FIbonacci sequence.
Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following formula:
                        Fn = Fn-1 + Fn-2, for n > 2; let n0 = 0, n1 = 1, and n2 = 1
                    In this approach, we first recursively use the Fibonacci formula until every recursive function call meets the
                    base case. Then, each function call returns a value, and the values are added together until the sums are returned
                    to the original function call, which then returns the nth Fibonacci number.
Time Complexity:    O(2^N); N = number of Fibonacci values from 0 to n
Space Complexity    O(1)
Resources:          https://www.geeksforgeeks.org/python-program-to-print-the-fibonacci-sequence/
'''

# Use recursion to return the nth Fibonacci number.
def fibRecursion(n):
    # If n is negative, it is invalid.
    if n < 0:
        return None
    if n == 0:
        return 0
    # Base case: if n equals 1 or 2, return 1.
    if n <= 2:
        return 1
    # If n > 2, recursively perform Fn-1 + Fn-2 until the function either returns 1 or 2.
    return fibRecursion(n - 1) + fibRecursion(n - 2)

'''fibRecursion() when n = 5
    init.   fib(5)
    1.      fib(5-1) + fib(5-2) = fib(4) + fib(3)
    2.      fib(4-1) + fib(4-2) + fib(3-1) + fib(3-2) = fib(3) + fib(2) + fib(2) + fib(1)
    3.      fib(3-1) + fib(3-2) + fib(2) + fib(2) + fib(1) = fib(2) + fib(1) + fib(2) + fib(2) + fib(1)
    4.      fib(2) + fib(1) + fib(2) + fib(2) + fib(1) = 1 + 1 + 1 + 1 + 1 = 5
    return 5
'''
    
# Print the first 11 numbers in the Fibonacci sequence.
for n in range(0, 11):
    print("fib(", n, ") = ", fibRecursion(n), sep="")