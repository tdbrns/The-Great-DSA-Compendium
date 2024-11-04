'''
Algorithm:          Fibonacci Sequence using Memoization/Top-Down Approach

Task:               Use the Fibonacci algorithm to print the nth number in the Fibonacci sequence.

Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following recursion relation:
                        F(n) = F(n-1) + F(n-2), for n > 2; let F(0) = 0 and F(1) = 1
                    In this approach, we first recursively use the Fibonacci formula until every recursive function call meets the
                    base case. Then, each function call returns a value, and the values are added together until the sums are returned
                    to the original function call, which then returns the nth Fibonacci number. A cache (dictionary/hashmap) stores
                    previously calculated Fibonacci numbers to prevent the function from calculating a number more then once. This is
                    a top-down approach because we solve the problem of finding the nth Fibonacci number by dividing it into 
                    smaller subproblems through recursion.

Time Complexity:    O(N); N = number of Fibonacci values from 0 to n

Space Complexity    o(N); N = number of Fibonacci values from 0 to n to be stored in the cache

Resources:          https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
'''
# Dictionary of calculated Fibonacci numbers.
# key = position of the nth Fibonacci number in the sequence, value = value of the nth Fibonnaci number
cache = {}      

# Use recursion to return the nth Fibonacci number. Use cache Fibonacci numbers that have been calculated.
def fibMemoization(n):
    # If n is negative, it is invalid.
    if (n < 0):
        return None
    if (n == 0):
        return 0
    # If n is already in cache, return it.
    if n in cache: 
        return cache[n]
    # Base case: if n equals 1 or 2, set value to 1.
    if n <= 2:
        value = 1
    # If n > 2, recursively perform Fn-1 + Fn-2 until the function either returns 1 or 2.
    else:
        value = fibMemoization(n - 1) + fibMemoization(n - 2)
    
    # Store the current nth number in cache before returning it.
    cache[n] = value
    return value

# Print the first 11 numbers in the Fibonacci sequence.
for n in range(0, 11):
    print("fib(", n, ") = ", fibMemoization(n), sep="")