/*
Algorithm:          Longest Palindrome using Hashmap (LeetCode Problem #409)

Task:               Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that 
                    can be built with those letters. Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Solution:           Iteratively store the frequency of each character in string s into a hashmap. Whenever the frequency value of a 
                    character becomes divisible by 2, add 2 to the longest palindrome length. After recording the character frequency,
                    check each element in the hashmap to see if its value if divisible by 2. If there is a value that is not divisible
                    by 2, then the longest palindrome has an odd number of characters (e.g., kayak, abcba) instead of an even number of
                    character (e.g., noon, acca); to account for this, we add 1 to the longest palidrome length.

Time complexity:    O(N)
                        N = length of input string

Space complexity:   O(N)
                        N = number of elements in the hashmap / number of characters in the string

Auxiliary space:    O(N)
                        N - number of elements in the hashmap

Resources:          https://leetcode.com/problems/longest-palindrome/solutions/
                    https://www.geeksforgeeks.org/longest-palindromic-substring/
*/


#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;

class Solution {
public:
    int longestPalindrome(string s) {
        // Iteratively record the character frequency of the input string. Whenever the frequency of a character is divisible by 2, 
        // add 2 to length.
        
        unordered_map<char, int> charHz;    // Store the character frequency of s (key = character; value = frequency value).
        int length = 0;                     // Length of longest palindrome.

        // 
        for (int i = 0; i < s.length(); i++)
        {
            charHz[s[i]]++;
            
            if (charHz[s[i]] % 2 == 0)
                length += 2;
        }

        for (auto itr = charHz.begin(); itr != charHz.end(); itr++)
        {
            if (itr->second % 2 != 0)
            {
                length += 1;
                break;
            }
        }
        
        return length;
    }
};