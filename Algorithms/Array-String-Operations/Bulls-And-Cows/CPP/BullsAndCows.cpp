/*
Algorithm:          Identify the Number of "Bulls" and "Cows" (Leetcode Problem #299)

Task:               You are playing Bulls and Cows with a friend. You write down a secret number and ask your friend to guess what the
                    number is. When your friend makes a guess, you provide them a hint by showing them how many "bulls" and "cows" are
                    in their guess. "Bulls" are digits in the guess that are in the correct position, and "cows" are digits in the 
                    guess that are in your secret number but are located in the wrong position (i.e., the non-bull digits in the guess
                    that could be rearranged such that they become bulls). Given the secret number and your friend's guess, return the
                    hint for your friend's guess.

                    The hint should be formatted as "xAyB", where "x" is the number of bulls and "y" is the number of cows. Both the
                    secret and the guess may contain duplicate digits. The secret and the guess are always of equal length.
Solution:           Iteratively compare the digits in the secret to the digits in the guess (i.e., compare the 1st secret digit
                    to the 1st guess digit, the 2nd secret digit to the 2nd guess digit, and so on) to determine the number of bulls
                    in the guess. Use two <char, int> hashmaps to record the occurence of non-bull digits in the secret and 
                    the guess to determine the number of cows in the guess.

Time complexity:    O(N); N = length of the secret number 

Space complexity:   O(N); N = size of the hashmaps (worst-case scenario occurs when the guess number has no bulls or cows)

Resources:          https://leetcode.com/problems/bulls-and-cows/description/
*/

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

string getHint(string secret, string guess) 
{
    int bulls = 0;                          // Number of bulls in the guess.
    int cows = 0;                           // Number of cows in the guess.
    unordered_map<char, int> secretMp;      // Hashmap that records the occurence of non-bull digits in the secret number.
    unordered_map<char, int> guessMp;       // Hashmap that records the occurence of non-bull digits in the guess number.

    // NOTE: we created two empty hashmaps with character keys and integer values that are initialized as 0. The values are 
    // used to determine whether the current non-bull digit is a cow or not. When non-bull digits are added to either hashmap, 
    // they are given a value of 1. If the current non-bull digit being processed is a key in a hashmap with the value 1, it
    // is considered a cow and 1 is subtracted from its value; if the current non-bull digit being processed is not in a hashmap,
    // it is added to a hashmap with a value of 1. 

    for (int i = 0; i < secret.length(); i++)
    {
        // If the current digit of the guess is in the correct position, its is a bull.
        if (secret[i] == guess[i])
            bulls++;
        else
        {
            // If the current digit of the guess is already in secretMp, consider it a cow.
            if (secretMp[guess[i]] > 0)
            {
                // Subtract 1 from the value of the matching key and increment cows.
                secretMp[guess[i]]--;
                cows++;
            }
            else
                // Otherwise, add the current digit of the guess to guessMp.
                guessMp[guess[i]]++;
            
            // If the current digit of the secret is already in guessMp, consider it a cow.
            if (guessMp[secret[i]] > 0)
            {
                // Subtract 1 from the value of the matching key and increment cows.
                guessMp[secret[i]]--;
                cows++;
            }
            else
                // Otherwise, add the current digit of the secret to secretMp.
                secretMp[secret[i]]++;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main()
{
    string secret = "1123";
    string guess = "0111";
    cout << getHint(secret, guess);

    return 0;
}