/*
Algorithm:          Fibonacci Sequence using Iteration

Task:               Use the Fibonacci algorithm to print the nth number in the Fibonacci sequence.

Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following recursion relation:
                        F(n) = F(n-1) + F(n-2), for n > 2; let F(0) = 0 and F(1) = 1
                    In this approach, we find the nth number in the Fibonacci sequence by recursively performing the Fibonacci
                    formula on every value n we obtain after each recursive call of the Fibonacci function.
                    
Time Complexity:    O(N); N = number of Fibonacci values in range 0 to n

Space Complexity    O(1)

Resources:          https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*/

#include <iostream>
using std::cout;
using std::endl;

int fibIterative(int n)
{
    // If n is negative, it is invalid.
    if (n < 0)
        return -1;
    // If n is 0, return 0.
    if (n == 0)
        return 0;
    // If n equals 1 or 2, return 1.
    if (n <= 2)
        return 1;

    int num1 = 1;       // Fn-1; initialized as the 1st number of the Fibonacci sequence.
    int num2 = 1;       // Fn-2; initialized as the 2nd number of the FIbonacci sequence.
    int result = 0;     // Fn; sum of num1 and num2.

    // Use the formula to calculate each number in the sequence while decrementing n by 1 after each calculation. This process will 
    // continue until n equals 2.
    while (n > 2)
    {
        result = num1 + num2;
        num1 = num2;
        num2 = result;
        n--;
    }
    
    // Return the final value of result.
    return result;
}

int main()
{
    // Print the first 11 numbers in the Fibonacci sequence.
    for (int n = 0; n <= 10; n++)
        cout << "fib(" << n << ") = " << fibIterative(n) << endl;

    return 0;
}