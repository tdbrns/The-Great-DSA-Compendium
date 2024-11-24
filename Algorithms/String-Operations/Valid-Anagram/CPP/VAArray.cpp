/*
Algorithm:          Valid Anagram using Array (LeetCode Problem #242)

Task:               Given two string "s" and "t", return "true" if "t" is an anagram of "s", and "false" otherwise. "s" and "t" consist 
                    of lowercase English letters.

Solution:           An anagram should have the same character frequency as the original word or phrase. Use a array to record the 
                    frequency of the characters in string s and the subract the frequency of characters in s by the frequency of 
                    characters in t. If the value of each character frequency in the array is 0, then t is an anagram of s because 
                    they both have the same character frequency; otherwise, t is not an anagram of s.

Time complexity:    O(N)
                        N = number of characters in s or t

Space complexity:   O(N)
                        N = number of characters stored in the array

Auxiliary space:    O(N)
                        N = number of characters stored in the array

Resources:          https://leetcode.com/problems/valid-anagram/description/
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool isAnagram(string s, string t) 
{
    int charHz[26] = {0};       // Stores the frequency of characters from 'a' to 'z'

    // Record the frequency of each character in s.
    for(char c : s)
        charHz[c - 'a']++;

    // Subtract the frequency of characters in s by the frequency of characters in t.
    for(char d : t)
        charHz[d - 'a']--;

    
    for(int i = 0 ; i < 26 ; i++)
    {
        if(charHz[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";
    (isAnagram(s, t)) ? printf("t is an anagram of s.\n") : printf("t is not an anagram of s.\n");

    s = "rat";
    t = "car";
    (isAnagram(s, t)) ? printf("t is an anagram of s.\n") : printf("t is not an anagram of s.\n");

    return 0;
}