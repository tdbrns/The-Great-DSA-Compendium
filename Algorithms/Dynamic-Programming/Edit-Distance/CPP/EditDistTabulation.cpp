/*
Algorithm:          Edit Distance using Tabulation/Bottom-Up Approach (LeetCode Problem #72)

Task:               Given two strings str1 and str2 with lengths m and n respectively, find the minimum number of edit operations
                    required to convert str1 into str2. There are three types of edit operations:
                        • Insert - insert a character into str1
                        • Replace - replace a character in str1 with a character from str2
                        • Remove - remove a character from str1
                    NOTE: If one string is empty, the edit distance will be equal to the length of the other string.

Solution:           To find the minimum number of edit operation needed to transform str1 into str2, we can compare each character in 
                    str1 to each character in str2 according to their position starting from the last character in both strings (i.e., 
                    compare str1[m-1] to str2[n-1], then str1[m-2] to str2[n-2], and so on). If the two characters match, move on to 
                    compare the next character in str1 to the next character in str2. If the two character do not match, recursively 
                    perform all three edit operations to determine which one would ultimately lead to converting str1 into str2 with the
                    fewest edit operations possible.
                    In this solution, the result of each subproblem is stored in a DP table of size (m+1) * (n+1). The table is used to 
                    avoid solving the same subproblem multiple times with each iteration. The first column of the table is initialized 
                    with the subproblem results produced when only str2 is empty, and the first row is initialized with the subproblem 
                    results produced when only str1 is empty.

Time complexity:    O(M * N)
                        M = length of str1
                        N = length of str2

Space complexity:   O(M * N)
                        M * N = size of the dynamic programming table

Auxiliary space:    O(M * N)
                        M * N = size of the dynamic programming table

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

int editDistTabulation(const string& str1, const string& str2, int m, int n, vector<vector<int>> dp)
{
    // Initialize the first column with values in range 0 to m; when str2 is empty, the minimum edit distance will be the length of the
    // current subsequence of str1.
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    // Initialize the first row with values in range 0 to n; when str1 is empty, the minimum edit distance will be the length of the
    // current subsequence of str2.
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    
    // Iteratively fill in the rest of the dp table.
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If the character in str1 matches the character in str2, no edits are required. Move to next character in str1 and str2.
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // If the character str1 does not match the character in str2, add 1 to the edit distance, perform all three edit
            // operations, and store the lowest result in dp.
            else
                dp[i][j] = 1 + min({
                    dp[i][j - 1],               // Insert
                    dp[i - 1][j],               // Remove
                    dp[i - 1][j - 1]            // Replace
                });
        }
    }

    // dp[m][n] holds the minimum edit distance.
    return dp[m][n];
}

// Wrapper for editDistTabulation().
int minEditDistance(string str1, string str2)
{
    int m = str1.length();          // Length of string 1.
    int n = str2.length();          // Length of string 2.

    // DP table that stores the number of edits needed edits needed to convert every subsequence of str1 into every correlating
    // subsequence of str2 (i.e., a table of subproblem results); size of dp is (m+1) * (n+1) because we need an extra row to store the
    // subproblem results when str1 is empty and an extra column to store the subproblem results when str2 is empty.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    return editDistTabulation(str1, str2, m, n, dp);    
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