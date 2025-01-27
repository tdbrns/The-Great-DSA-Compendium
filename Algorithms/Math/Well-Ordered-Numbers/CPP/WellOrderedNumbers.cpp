/*
Algorithm:          Well-Ordered Numbers

Task:               A well-ordered number is a number with digits that are in strictly increasing order from left to right (e.g., 123, 
                    124, 3589, etc.). Given a number of digits n, find all well-ordered number with n digits. n can be any number from
                    1 to 9.

Solution:           Use a recursive algorithm to print out each possible well-ordered number with n digits. 
                    A well-ordered number is created with the following constraint:
                        Let a = value of the current digit
                        Let b = value of the digit to the left of the current digit
                        • 0 < b < a <= 9
                    The algorithm works by recursively increasing the number of digits of a well-ordered number until there are n digits
                    and then iterativelyprinting the well-ordered number with digits 1 to 9 in its appropriate place according the the
                    constraint mentioned above.

Time complexity:    O(N * 2^N)
                        N = number of digits n
                        2^N = number of n-digit numbers to be generated

Space complexity:   O(N)
                        N = maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/generate-k-digit-numbers-digits-strictly-increasing-order/
*/


#include <iostream>
using std::cout;
using std::endl;

void printWellOrderedNumbers(int num, int x, int n) {
    // Base case; if n = 0, the current number is a well-ordered number with n digits.
    if (n == 0) {
        cout << num << endl;
        return;
    }

    // Recursively call printWellOrderedNumbers() until all well-ordered numbers have been printed.
    // NOTE: i = the digit from 1 to 9 being considered with each iteration of the for loop. The number of digits to be considered will 
    //       decrease as x increases.
    // NOTE: num * 10 + i is used to increase the number of digits in num by 1 until n == 0. When n == 0, num will be assigned values
    //       from 1 to 9 according to the constraint.
    for (int i = x + 1; i < 10; i++) {
        printWellOrderedNumbers(num * 10 + i, i, n - 1);
    }    
}

// Wrapper for printWellOrderedNumbers().
void getWellOrderedNumbers(int n) {
    printWellOrderedNumbers(0, 0, n);
}

int main() {
    int n = 2;
    getWellOrderedNumbers(n);
    return 0;
}