/*
Algorithm:          Ransom Note (LeetCode Problem #383)

Task:               Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from 
                    magazine and false otherwise. Each letter in magazine can only be used once in ransomNote.

Solution:           Use a hashmap to record the frequency of each character in magazine and the use the hashmap to determine if ransomNote
                    can be constructed with the characters presented in magazine.

Time complexity:    O(N)
                        N = number of characters in magazine and ransomNote

Space complexity:   O(N)
                        N = number of characters from magazine that are stored in the hashmap

Auxiliary space:    O(N)
                        N = number of character from magazine that are stored in the hashmap

Resources:          https://leetcode.com/problems/ransom-note/solutions/
*/


#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Use a hashmap to keep track of characters and their frequency of occurence in ransomNote and magazine.
        unordered_map<char, int> magazineMap;
        for (int i = 0; i < magazine.length(); i++)
            magazineMap[magazine[i]]++;
        
        // Use magazineMap to determine if there are enough characters in magazine to construct ransomNote.
        for (int i = 0; i < ransomNote.length(); i++)
        {
            // If the current character in ransomNote has occurred more than 0 times magazineMap, subtract 1 from the character's frequency
            // value in magazineMap. Otherwise, return false.
            if (magazineMap[ransomNote[i]] > 0)
                magazineMap[ransomNote[i]]--;
            else
                return false;
        }
        return true;
    }
};