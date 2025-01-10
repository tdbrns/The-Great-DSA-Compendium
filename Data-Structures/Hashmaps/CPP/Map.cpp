/*
Structure:          Hashmap (ordered)

Task:               Create a data structure that can store key-value pairs. Duplicate keys should not be accepted.

Solution:           Use an ordered hash map, which stores key-value pairs in a specific order. Ordered hash maps in C++ organize
                    elements in ascending order by default using a binary search tree. Ordered hash maps do not allow duplicate keys; 
                    if a new key being added to the hash map is a duplicate of a key that already exists in the hash map, the 
                    pre-existing key-value pair will be overwritten with the new key and its value.
                    
Resources:          https://cplusplus.com/reference/map/map/
*/


#include <iostream>
#include <map>
#include <sstream>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::stringstream;

int main() 
{
    /***********************************************************************************************************************************/
    // 1. Create an ordered map (mp) that has char keys and int values.
    map<char, int> mp;


    /***********************************************************************************************************************************/
    // 2. Store each character from a string into the map as a key; store each character's index in the string as a value. 
    string str = "Hello";
    for (int i = 0; i < str.length(); i++)
        mp[str[i]] = i;
    cout << "Created hash map with " << mp.size() << " elements." << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 3. Create a temporary key-value pair and copy it into mp.
    char key = '!';
    int val = 5;
    pair<char, int> newPair (key, val); 
    mp.insert(newPair);
    // Another way...
    //uMp.insert(std::make_pair(key, val));


    /***********************************************************************************************************************************/
    // 4. Insert a new key-value pair into mp without creating a temporary key-value pair.
    key = 'v';
    val = 6;
    mp.emplace(key, val);


    /***********************************************************************************************************************************/
    // 5. Check if a specific key in mp have has a specific value. If key does not exist in mp, it will automatically be added to 
    //    mp with value 0.
    char targetKey = 'v';
    int targetVal = 6;
    if (mp[targetKey] == targetVal)
        cout << "'" << targetKey << "' has the corresponding value '" << targetVal << "'" << endl;
    else
        cout << "'" << targetKey << "' does not have the corresponding value '" << targetVal << "'" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 6. Print out each key-value pair in mp. "itr" is and iterator for std::map with the type map<char, int>::iterator.
    cout << "Hash map:" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << "["<< itr->first << ":" << itr->second << "]" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 7. Determine if a specific key exists within the mp and remove it. Search for the target key in mp; if found, remove it with 
    //    erase(). find() returns an iterator of type map<char, int>::iterator.
    targetKey = 'v';
    if (mp.find(targetKey) != mp.end()) {
        mp.erase(targetKey);
        cout << "Found and removed element with key '" << targetKey << "'" << endl;
    }   
    else 
        cout << "Could not find element with key '" << targetKey << "'" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 8. Remove all key-value pairs from mp.
    mp.clear();


    /***********************************************************************************************************************************/
    // 9. Determine the frequency of characters in a string (i.e., count the number of times a each character appears in a string).
    str = "abcba";
    map<char, int> charHz;            // Stores each character in str as a key and the frequency of each character as a value.

    // Iterate through each character in str; if a character appears more than once, add 1 to its frequency value.
    for (int i = 0; i < str.length(); i++)
        charHz[str[i]]++;
    
    // Print each character that is in str along with its frequency value.
    cout << "Character frequency:" << endl;
    for (auto itr = charHz.begin(); itr != charHz.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 10. Determine the frequency of individual words in a string.
    str = "die die die death destruction turmoil turmoil death die";
    map<string, int> wordHz;      // Stores each word in str as a key and the frequency of each word as a value.
    stringstream ss(str);           // Used to break down the string into words (substrings separated by spaces).
    string word;                    // An individual word from str2.

    // Iterate through each word in str; if a word appears more than once, add 1 to its frequency value.
    while (ss >> word)
        wordHz[word]++;
    
    // Print each word that is in str along with its frequency value.
    cout << "Word frequency:" << endl;
    for (auto itr = wordHz.begin(); itr != wordHz.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
    cout << endl;

    return 0;
}