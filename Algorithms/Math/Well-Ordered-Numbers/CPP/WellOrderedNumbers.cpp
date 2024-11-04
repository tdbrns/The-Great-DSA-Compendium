/*
Algorithm:          Well-Ordered Numbers

Task:               A well-ordered number is a number with digits that are in strictly increasing order from left to right (e.g., 123, 
                    124, 3589, etc.). Given a number of digits n, find all well-ordered number with n digits. n can be any number from
                    1 to 9.

Solution:           Use a recursive function to print out each possible well-ordered number with n digits.

Time Complexity:    O(N * 2^N); N = number of digits n, 2^N = number of n-digit numbers to be generated.

Space Complexity    O(1)

Resources:          https://www.geeksforgeeks.org/generate-k-digit-numbers-digits-strictly-increasing-order/
*/

#include <iostream>
using std::cout;
using std::endl;

// num = current number that may be printed. Initialized at 0.
// x = number of digits from 1 to 9 that cannot be considered. Initialized at 0.
// n = number of digits to be considered.
void printWellOrderedNumbers(int num, int x, int n)
{
    // Base case: if n = 0, the current number is a well-ordered number with n digits.
    if (n == 0)
    {
        cout << num << endl;
        return;
    }

    // Recursively call printWellOrderedNumbers until all well-ordered numbers have been printed.
    // i = the digit from 1 to 9 being considered with each iteration of the for loop. The number of digits to be considered will 
    //     decrease as x increases.
    for (int i = x + 1; i < 10; i++)
    {
        // number * 10 + i will increase the number of digits in num by 1 until n equals 0.
        printWellOrderedNumbers(num * 10 + i, i, n - 1);
    }
}
/* printWellOrderedNumbers() when n = 2:
    init.   printWellOrderedNumbers(0, 0, 2)
    1.      printWellOrderedNumbers(1, 1, 1)
    2.      printWellOrderedNumbers(12, 1, 0) -> print 12; return
    3.      printWellOrderedNumbers(13, 2, 0) -> print 13; return
    4.      printWellOrderedNumbers(14, 2, 0) -> print 14; return
    5.      printWellOrderedNumbers(15, 2, 0) -> print 15; return
    6.      printWellOrderedNumbers(16, 2, 0) -> print 16; return
    7.      printWellOrderedNumbers(17, 2, 0) -> print 17; return
    8.      printWellOrderedNumbers(18, 2, 0) -> print 18; return
    9.      printWellOrderedNumbers(19, 2, 0) -> print 19; return
    10.     printWellOrderedNumbers(1, 2, 1)
    ...
*/

// Wrapper for printWellOrderedNumbers().
void getWellOrderedNumbers(int n)
{
    printWellOrderedNumbers(0, 0, n);
}

int main()
{
    int numDigits = 3;
    getWellOrderedNumbers(numDigits);
    return 0;
}