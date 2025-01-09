/*
Algorithm:          Add Binary (LeetCode Problem #409)

Task:               Given two binary strings a and b, return their sum as a binary string.

Solution:           Iteratively perform binary addition with a[i], b[j], and the value carried from the preceding binary addition
                    operation. 
                    First convert the characters a[i] and b[j] into their integer form by subtracting the ASCII value of '0' (48) from 
                    the ASCII value of the characters. Then we add the resulting integers together along with the value that was carried 
                    over from the previous binary addition operation. If the resulting sum is greater than 1, then the sum is set to 0
                    and a value of 1 is carried over to the binary addition operation of the next iteration. Then the final sum is 
                    inserted to the front of the result string. This process is repeated until each character in a and b has been 
                    iterated through. 
                    If the carried value is still 1 after the end of the iteration, insert "1" at the front result string.
                    Finally, return the result 

Time complexity:    O(max(M, N))
                        M = length of string a
                        N = length of string b

Space complexity:   O(M + N)
                        M = length of string a
                        N = length of string b

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/add-binary/solutions/
*/


#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

string addBinary(string a, string b) 
{
    int i = a.length() - 1;         // Index of string a.
    int j = b.length() - 1;         // Index of string b.
    int carry = 0;                  // The carried value.
    string result = "";             // Result string.

    // Iteratively perform binary addition until all values characters have added.
    while (i >= 0 || j >= 0)
    {
        int sum = carry;    // Sum of the current set of binary digits.

        // Get the ASCII the characters a[i] and b[j], subtract the ASCII value of '0' (48) from each of them, and the the two differences together.
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        
        // If the sum is greater than 1, set carry to 1; otherwise, set carry to 0.
        carry = sum > 1 ? 1 : 0;
        
        // Insert the result of sum % 2 at the front of the result string.
        /* Example
            when sum = 0, 0 % 2 = 0
            when sum = 1, 1 % 2 = 1
            when sum = 2, 2 % 2 = 0
            when sum = 3, 3 % 2 = 1
        */
        result.insert(0, std::to_string(sum % 2));
    }

    // If carry is 1, insert it at the front of the result string.
    if (carry == 1)
        result.insert(0, "1");

    return result;
}

int main()
{
    // Test case 1.
    string a = "11";
    string b = "1";
    cout << "The sum of " << a << " and " << b << " is " << addBinary(a, b) << endl;

    // Test case 2.
    a = "1010";
    b = "1011";
    cout << "The sum of " << a << " and " << b << " is " << addBinary(a, b) << endl;

    return 0;
}