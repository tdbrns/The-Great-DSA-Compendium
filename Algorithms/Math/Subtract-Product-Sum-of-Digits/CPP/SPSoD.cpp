/*
Algorithm:          Subtract the Product and Sum of Digits of an Integer (LeetCode Problem #1281)

Task:               Given an integer n, return the difference between the product of its digits and the sum of its digits.

Solution:           Use some arithmetic to obtain each digit of integer n and find the product and sum of the digits. Then subtract the
                    sum from the product and return the difference.

Time complexity:    O(N)
                        N = number of digits in the integer

Space complexity:   O(1)

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
                    https://www.geeksforgeeks.org/program-for-sum-of-the-digits-of-a-given-number/
*/


#include <iostream>
using std::cout;
using std::endl;

int subtractProductAndSum(int num) {
    int sum = 0;
    int product = 1;

    while (num > 0) {
        sum += num % 10;            // Add the digit currently in the ones place of num to sum.
        product *= num % 10;        // Multiply the digit currently in the ones place of num by product.
        num /= 10;                  // Divide num by 10 to move all digits down by one place. Quotient is rounded down to the nearest 
                                    // integer.
    }

    return product - sum;
}

int main() {
    // Test case 1.
    int num = 234;
    cout << "Difference between the digit product and digit sum of " << num << " is " << subtractProductAndSum(num) << endl;

    // Test case 2.
    num = 4421;
    cout << "Difference between the digit product and digit sum of " << num << " is " << subtractProductAndSum(num) << endl;
    return 0;
}