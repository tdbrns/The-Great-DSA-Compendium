/*
Algorithm:          Valid Anagram using Hash Map (LeetCode Problem #242)

Task:               Given two string "s" and "t", return "true" if "t" is an anagram of "s", and "false" otherwise.

Solution:           An anagram should have the same character frequency as the original word or phrase. Use a hash map to record the 
                    frequency of the characters in string s and the subract the frequency of characters in s by the frequency of 
                    characters in t. If the value of each character frequency in the hash map is 0, then t is an anagram of s because 
                    they both have the same character frequency; if the value of each character frequency is less than 0, t is not an 
                    anagram of s.

Time complexity:    O(N)
                        N = number of characters in s or t

Space complexity:   O(N)
                        N = number of characters stored in the hash map

Auxiliary space:    O(N)
                        N = number of characters stored in the hash map

Resources:          https://leetcode.com/problems/valid-anagram/description/
*/

#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

bool isAnagram(string s, string t)
{
    // If s and t are not the same length, t is not an anagram of s.
    if (s.length() != t.length())
        return false;
    
    bool result = true;
    unordered_map<char, int> uMp;        // Stores character frequencies.

    // Record the frequency of each character in s.
    for (int i = 0; i < s.length(); i++)
        uMp[s[i]]++;

    // Subtract the frequency of characters in s by the frequency of characters in t.
    for (int i = 0; i < t.length(); i++)
    {
        uMp[t[i]]--;

        // If a character has a value less than 0, t is not an anagram of s.
        if (uMp[t[i]] < 0)
        {
            result = false;
            break;
        }
    }

    return result;
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