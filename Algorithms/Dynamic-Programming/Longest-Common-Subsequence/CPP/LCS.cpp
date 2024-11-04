/*
Algorithm:          Longest Common Subsequence using Tabulation/Bottom-Up Approach

Task:               Given two strings str1 and str2 with lengths m and n respectively, find the length of their longest common 
                    subsequence.

Solution:           Use DP Tabulation to determine the length of the longest common subsequence between str1 and str2.

Time complexity:    O(M*N); M = length of str1, N = length of str2

Space complexity:   O(M*N); M * N = size of LCS Table

Resources:          https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
                    https://www.youtube.com/watch?v=Ua0GhsJSlWM
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int LCS(string str1, string str2)
{
    int m = str1.size();        // Size of str1.
    int n = str2.size();        // Size of str2.

    // Dynamic programming table of size (m + 1)*(n + 1) initialized with 0s.
    // NOTE: we use m + 1 and n + 1 because we need the first row and the first column to always be filled with zeros.
    vector<vector<int>> lcsTable(m + 1, vector<int>(n + 1, 0));

    // Iterate through each position of the table in bottom-up fashion.
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If the character in str1 matches the character in str2, add 1 to the value to the upper left of 
            // lcs[i][j] and set the sum as lcsTable[i][j].
            if (str1[i - 1] == str2[j - 1])
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            // If the character in str1 does not match the character in str2, compare the value above lcsTable[i][j] 
            // and the value below lcsTable[i][j] and set the highest value as lcsTable[i][j].
            else
                lcsTable[i][j] = std::max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
        }
    }

    // Print out the final LCS table.
    cout << "LCS Table\n";
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << lcsTable[i][j] << " ";
        
        cout << endl;
    }

    // Since the bottom right position of the table holds the LCS length, return lcsTable[m][n].
    return lcsTable[m][n];
}

int main()
{
    string str1 = "abcde";      // String 1.
    string str2 = "ace";        // String 2.

    int lcsLength = LCS(str1, str2);
    cout << "The longest common subsequence is " << lcsLength;

    return 0;
}