/*
Algorithm:          Valid Palindrome using Two Pointers (LeetCode Problem #125)

Task:               A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-
                    alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
                    Given a string s, return true if it is a palindrome, or false otherwise.

Solution:           We do not need to convert the given string as directed. In this solution, we just take the string as it is and use
                    the two pointer technique to determine if the string is a palindrome. Non-alphanumeric characters are ignored during
                    the process, and uppercase characters are converted to lowercase as needed.

Time complexity:    O(N)
                        N = length of input string

Space complexity:   O(1)

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/valid-palindrome/solutions/
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool isPalindrome(string s) 
{
    int left_i = 0;                 // Index of the left part of the string.
    int right_i = s.length() - 1;   // Index of the right part of the string (the reversed part).
    bool result = true;             // Boolean result.

    while (left_i < right_i)
    {
        // If s[left_i] is non-alphanumeric, ignore it and move on to the next character to the left.
        if (!isalnum(s[left_i]))
        {
            left_i++;
            continue;
        } 

        // If s[right_i] is non-alphanumeric, ignore it and move on to the next character to the right.
        if (!isalnum(s[right_i]))
        {
            right_i--;
            continue;
        }

        // If the two characters are not equal, the string is not a palindrome, so return false.
        if (tolower(s[left_i]) != tolower(s[right_i]))
        {
            result = false;
            break;
        }
        // If the characters are equal, move on to the next characters.
        else
        {
            left_i++;
            right_i--;
        }
    }

    return result;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    (isPalindrome(str)) ? printf("The 1st string is a palindrome.") : printf("The 1st string is not a palindrome.");
    cout << endl;

    str = "race a car";
    (isPalindrome(str)) ? printf("The 2nd string is a palindrome.") : printf("The 2nd string is not a palindrome.");
    cout << endl;

    str = "";
    (isPalindrome(str)) ? printf("The 3rd string is a palindrome.") : printf("The 3rd string is not a palindrome.");
    
    return 0;
}