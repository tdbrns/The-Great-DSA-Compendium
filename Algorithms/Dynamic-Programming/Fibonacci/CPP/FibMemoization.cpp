/*
Algorithm:          Fibonacci Sequence (Memoization Approach)
Task:               Use the Fibonacci algorithm to print the nth number in the FIbonacci sequence.
Solution:           The Fibonacci sequence is a sequence of numbers in which each number is the sum of the two numbers preceding it, 
                    excluding the 0th and 1st number. The sequence is calculated with the following formula:
                        Fn = Fn-1 + Fn-2, for n > 2; let n0 = 0, n1 = 1, and n2 = 1
                    In this approach, we first recursively use the Fibonacci formula until every recursive function call meets the
                    base case. Then, each function call returns a value, and the values are added together until the sums are returned
                    to the original function call, which then returns the nth Fibonacci number. A cache (dictionary/hashmap) stores
                    previously calculated Fibonacci numbers to prevent the function from calculating a number more then once. This is
                    a top-down approach because we solve the problem of finding the nth Fibonacci number by dividing it into 
                    smaller subproblems through recursion.
Time Complexity:    O(N); N = number of Fibonacci values from 0 to n
Space Complexity    o(N); N = number of Fibonacci values from 0 to n to be stored in the cache
Resources:          
*/

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;

// Hashmap of calculated Fibonacci numbers.
// key = position of the nth Fibonacci number in the sequence, value = value of the nth Fibonnaci number
unordered_map<int, int> cache;

int fibMemoization(int n)
{
    int value;      // The current value of Fn.

    // If n is negative, it is invalid.
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    // If n is already in cache, return it.
    if (cache.find(n) != cache.end())
        return cache[n];
    // Base case: if n equals 1 or 2, set value to 1.
    if (n <= 2)
        value = 1;
    // If n > 2, recursively perform Fn-1 + Fn-2 until the function either returns 1 or 2.
    else
        value = fibMemoization(n - 1) + fibMemoization(n - 2);
    
    // Store the nth number in the cache before returning it.
    cache[n] = value;
    return value;
}

int main()
{
    // Print the first 11 numbers in the Fibonacci sequence.
    for (int n = 0; n <= 10; n++)
        cout << "fib(" << n << ") = " << fibMemoization(n) << endl;
    
    return 0;
}