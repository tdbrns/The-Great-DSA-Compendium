/*
Algorithm:          Edit Distance using Recursion (LeetCode Problem #72)
Task:               Given two strings str1 and str2 with lengths m and n respectively, find the minimum number of edit operations
                    required to convert str1 into str2. There are three types of edit operations:
                     Insert - insert a character into str1
                     Replace - replace a character in str1 with a character from str2
                     Remove - remove a character from str1
                    NOTE: If one string is empty, the edit distance will be equal to the length of the other string.
Solution:           To find the minimum number of edit operation needed to transform str1 into str2, we can compare each character in 
                    str1 to each character in str2 according to their position starting from the last character in both strings (i.e., 
                    compare str1[m-1] to str2[n-1], then str1[m-2] to str2[n-2], and so on). If the two characters match, move on to 
                    compare the next character in str1 to the next character in str2. If the two character do not match, recursively 
                    perform all three edit operations to determine which one would ultimately lead to converting str1 into str2 with the
                    fewest edit operations possible.
Time complexity:    O(3^M); M = length of str1 when str1.length <= str2.length
                    O(3^N); N = length of str2 when str1.length > str2.length
Space complexity:   O(M * N); M * N = size of 2-D memoization cache.
Resources:          https://www.youtube.com/watch?v=XYi2-LPrwm4&t=23s
                    https://www.geeksforgeeks.org/edit-distance-dp-5/
                    https://leetcode.com/problems/edit-distance/solutions/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;

int editDistRecursion(string& str1, string& str2, int m, int n)
{
    // Base case; if there are no characters left to process in str1, it will take n insert operations to convert str1 into str2.
    if (m == 0)
        return n;
    // Base case; if there are no characters left to process in str2, it will take m remove operations to convert str1 into str2.
    if (n == 0)
        return m;

    // If the character in str1 matches the character in str2, no edits are required, so move to next character in str1 and str2.
    if (str1[m - 1] == str2[n - 1])
        return editDistRecursion(str1, str2, m - 1, n - 1);
    // If the character in str1 doesn't match the character in str2, add 1 to the edit distance and recursively perform all three 
    // edit operations to determine the operation that will result in the lowest edit distance.
    else
    {
        return 1 + min({
        editDistRecursion(str1, str2, m, n - 1),      // Insert; move to next character in str2.
        editDistRecursion(str1, str2, m - 1, n),      // Remove; move to next character in str1.
        editDistRecursion(str1, str2, m - 1, n - 1)   // Replace; move to next character in str1 and str2.
        });
    }
}

// Wrapper for editDistRecursion().
int minEditDistance(string str1, string str2)
{
    int m = str1.length();          // Length of string 1.
    int n = str2.length();          // Length of string 2.

    return editDistRecursion(str1, str2, m, n);
}

int main()
{
    string str1 = "";           // The string to be converted into str2.
    string str2 = "acd";        
    cout << "Minimum edit distance" << endl;
    cout << "\"" << str1 << "\" to \"" << str2 << "\": " << minEditDistance(str1, str2) << endl;

    str1 = "abc";
    str2 = "abc";
    cout << "\"" << str1 << "\" to \"" << str2 << "\": " << minEditDistance(str1, str2) << endl;

    str1 = "abd";
    str2 = "acd";
    cout << "\"" << str1 << "\" to \"" << str2 << "\": " << minEditDistance(str1, str2) << endl;

    str1 = "abe";
    str2 = "abcd";
    cout << "\"" << str1 << "\" to \"" << str2 << "\": " << minEditDistance(str1, str2) << endl;

    return 0;
}