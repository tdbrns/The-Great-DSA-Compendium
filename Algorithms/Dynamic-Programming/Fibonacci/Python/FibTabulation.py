'''
Algorithm:          Fibonacci Sequence (Tabulation/Bottom-Up Approach)
Task:               Use the Fibonacci algorithm to print the nth number in the FIbonacci sequence.
Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following formula:
                        Fn = Fn-1 + Fn-2, for n > 2; let n0 = 0, n1 = 1, and n2 = 1
                    In this approach, we calculate each number in the sequence by adding the two numbers preceding the number and 
                    storing the sum in a table (array). This is done until the nth Fibonacci number has been stored in the table
                    and returned. This is considered a bottom-up approach because we start by calculating the first number in the 
                    sequence and then working up to the nth number.
Time Complexity:    O(N); N = number of Fibonacci values from 0 to n
Space Complexity    O(N); N = number of Fibonacci values from 0 to n to be stored in the table
Resources:          https://www.w3schools.com/dsa/dsa_ref_tabulation.php
'''

# Use a for loop with a table to return the nth Fibonacci number.
def fibTabulation(n):
    # If n is negative, it is invalid.
    if (n < 0):
        return None
    if (n == 0):
        return 0
    # If n equals 1 or 2, return 1.
    if (n <= 2):
        return 1
    
    dp_table = [0] * (n + 1)        # Array holding the first n+1 numbers of the Fibonacci sequence.
    dp_table[0] = 0                 # 0 is the 0th Fibonacci number.
    dp_table[1] = 1                 # 1 is the 1st Fibonacci number.
    dp_table[2] = 1                 # 1 is the 2nd Fibonacci number.

    # If n > 2, start calculating each number in the Fibonacci sequence and storing it in dp_table until the nth number is reached.
    for i in range(3, n + 1):
        dp_table[i] = dp_table[i - 1] + dp_table[i - 2]
        
    return dp_table[n]

# Print the first 11 numbers in the sequence.
for n in range(0, 11):
    print("fib(", n, ") = ", fibTabulation(n), sep="")