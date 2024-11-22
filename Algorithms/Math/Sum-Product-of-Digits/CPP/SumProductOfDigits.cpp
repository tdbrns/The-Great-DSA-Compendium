/*
Algorithm:          Subtract the Sum and Product of the Digits of an Integer (LeetCode Problem #1281)

Task:               Given an integer n, return the difference between the product of its digits and the sum of its digits.

Solution:           Use some arithmetic to obtain each digit of integer n and find the product and sum of the digits.

Time complexity:    O(N)
                        N = number of digits in the integer.

Space complexity:   O(1)

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
                    https://www.geeksforgeeks.org/program-for-sum-of-the-digits-of-a-given-number/
*/

#include <iostream>
using std::cout;
using std::endl;

// NOTE: if two integers cannot be divided evenly, the quotient is rounded down to the nearest integer.

// Find the sum of the digits of a number.
int findDigitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;        // Add the digit currently in the ones place of num to sum.
        num /= 10;              // Divide num by 10 to move all digits down by one place.
    }
        
    return sum;
}

// Find the product of the digits of a number.
int findDigitProduct(int num)
{
    int product = 1;
    while (num > 0)
    {
        product *= num % 10;    // Multiply the digit currently in the one place of num by product.
        num /= 10;              // Divide num by 10 to move all digits down by one place.
    }
        
    return product;
}

// Find the difference between the product and the sum.
int subtractProductAndSum(int num)
{
    int sum = 0;
    int product = 1;

    while (num > 0)
    {
        sum += num % 10;
        product *= num % 10;
        num /= 10;
    }

    return product - sum;
}

int main()
{
    int num = 234;
    cout << "Sum: " <<findDigitSum(num) << endl;
    cout << "Product: " << findDigitProduct(num) << endl;
    cout << "Difference between product and sum:" << subtractProductAndSum(num);
    return 0;
}