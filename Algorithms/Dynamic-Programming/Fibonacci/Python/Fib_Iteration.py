'''
Algorithm:          Fibonacci Sequence using Iteration

Task:               Use the Fibonacci algorithm to print the nth number in the Fibonacci sequence.

Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following recursion relation:
                        F(n) = F(n-1) + F(n-2), for n > 2; let F(0) = 0 and F(1) = 1
                    In this approach, we calculate each number in the sequence by adding the two numbers preceding the number until the 
                    nth number is reached.

Time complexity:    O(N)
                        N = number of Fibonacci values in range 0 to n

Space complexity:    O(1)

Auxiliary space:    O(1)

Resources:          https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
'''

# Use a while loop to return the nth Fibonacci number.
def fibIterative(n):
    # If n is negative, it is invalid.
    if n < 0:
        return None
    # If n is 0, return 0.
    if n == 0:
        return 0
    # If n equals 1 or 2, return 1.
    if n <= 2:
        return 1
    
    # If n > 2, start calculating each number in the Fibonacci sequence until the nth number is reached.
    num1 = 1        # Fn-2; initialized as the 1st number of the Fibonacci sequence.
    num2 = 1        # Fn-1; initialized as the 2nd number of the Fibonacci sequence.
    result = 0      # Fn; sum of num1 and num2.

    # Use the formula to calculate each number in the sequence while decrementing n by 1 after each calculation. This process will 
    # continue until n equals 2.
    while n > 2:
        result = num1 + num2
        num1, num2 = num2, result
        n -= 1
    
    # Return the final value of result.
    return result

# Print the first 11 numbers in the Fibonacci sequence.
for n in range(0, 11):
    print("fib(", n, ") = ", fibIterative(n), sep="")