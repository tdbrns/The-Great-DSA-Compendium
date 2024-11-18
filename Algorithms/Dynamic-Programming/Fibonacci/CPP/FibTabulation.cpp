/*
Algorithm:          Fibonacci Sequence using Tabulation/Bottom-Up Approach

Task:               Use the Fibonacci algorithm to print the nth number in the Fibonacci sequence.

Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following recursion relation:
                        F(n) = F(n-1) + F(n-2), for n > 2; let F(0) = 0 and F(1) = 1
                    In this approach, we calculate each number in the sequence by adding the two numbers preceding the number and 
                    storing the sum in a table (array). This is done until the nth Fibonacci number has been stored in the table
                    and returned. This is considered a bottom-up approach because we start by calculating the first number in the 
                    sequence and then working up to the nth number.

Time Complexity:    O(N); N = number of Fibonacci values in range 0 to n

Space Complexity    O(N); N = number of Fibonacci values to be stored in the table

Resources:          https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// Use a for loop with a table to return the nth Fibonacci number.
int fibTabulation(int n)
{
    // If n is negative, it is invalid.
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    // If n equals 1 or 2, return 1.
    if (n <= 2)
        return 1;
    
    vector<int> dpTable;            // Vector holding the first n+1 numbers of the Fibonacci sequence.
    dpTable.push_back(0);           // 0 is the 0th Fibonacci number.
    dpTable.push_back(1);           // 1 is the 1st Fibonacci number.
    dpTable.push_back(1);           // 1 is the 2nd Fibonacci number.

    // If n > 2, start calculating each number in the Fibonacci sequence and storing it in dp_table until the nth number is reached.
    for (int i = 3; i < n + 1; i++)
        dpTable.push_back(dpTable[i - 1] + dpTable[i - 2]);
    
    return dpTable[n];
}

int main()
{
    // Print the first 11 numbers in the Fibonacci sequence.
    for (int n = 0; n <= 10; n++)
        cout << "fib(" << n << ") = " << fibTabulation(n) << endl;
    
    return 0;
}