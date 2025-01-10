/*
Structure:          Hashmap (unordered)

Task:               Create a data structure that can store key-value pairs. Duplicate keys should not be accepted.

Solution:           Use an unordered hash map, which stores key-value pairs in an arbitrary order. Unordered hash maps do not allow 
                    duplicate keys; if a new key being added to the hash map is a duplicate of a key that already exists in the hash
                    map, the pre-existing key-value pair will be overwritten with the new key and its value.
                    
Resources:          https://en.cppreference.com/w/cpp/container/unordered_map
                    https://www.geeksforgeeks.org/map-vs-unordered_map-c/
*/


#include <iostream>
#include <unordered_map>
#include <sstream>
using std::cout;
using std::endl;
using std::unordered_map;
using std::pair;
using std::string;
using std::stringstream;

int main()
{
    /***********************************************************************************************************************************/
    // 1. Create an unordered map (uMp) that has char keys and int values.
    unordered_map<char, int> uMp;


    /***********************************************************************************************************************************/
    // 2. Store each character from a string into uMp as a key; store each character's index in the string as a value. 
    string str = "Hello";
    for (int i = 0; i < str.length(); i++)
        uMp[str[i]] = i;
    cout << "Created hash map with " << uMp.size() << " elements." << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 3. Print the number of buckets in uMp and the bucket in which each element of uMp has been placed. A hash function is performed 
    //    on each element to determine the bucket it will be placed into. The bucket count of a hash map will always increase to 
    //    accommodate the number of elements being inserted.
    cout << "Bucket count: " << uMp.bucket_count() << endl;
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "Element [" << itr->first << ":" << itr->second << "] is in bucket #" << uMp.bucket(itr->first) << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 4. Create a temporary key-value pair and copy it into uMp.
    char key = '!';
    int val = 5;
    pair<char, int> newPair (key, val); 
    uMp.insert(newPair);
    // Another way...
    //uMp.insert(std::make_pair(key, val));


    /***********************************************************************************************************************************/
    // 5. Insert a new key-value pair into uMp without creating a temporary key-value pair.
    key = '?';
    val = 6;
    uMp.emplace(key, val);

    /***********************************************************************************************************************************/
    // 6. Check if a specific key in uMp have has a specific value. If key does not exist in mp, it will automatically be added to 
    //    uMp with value 0.
    char targetKey = '?';
    int targetVal = 6;
    if (uMp[targetKey] == targetVal)
        cout << "'" << targetKey << "' has the corresponding value '" << targetVal << "'" << endl;
    else
        cout << "'" << targetKey << "' does not have the corresponding value '" << targetVal << "'" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 7. Print out each key-value pair in mp. "itr" is and iterator for std::unordered_map with the type 
    //    unordered_map<char, int>::iterator.
    cout << "Hash map:" << endl;
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "["<< itr->first << ":" << itr->second << "]" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 8. Determine if a specific key exists within the uMp and remove it. Search for the target key in uMp; if found, remove it with 
    //    erase(). find() returns an iterator of type unordered_map<char, int>::iterator.
    targetKey = '?';
    if (uMp.find(targetKey) != uMp.end()) {
        uMp.erase(targetKey);
        cout << "Found and removed element with key '" << targetKey << "'" << endl;
    }   
    else 
        cout << "Could not find element with key '" << targetKey << "'" << endl;
    cout << endl;


    /***********************************************************************************************************************************/
    // 9. Determine the frequency of characters in a string (i.e., count the number of times a each character appears in a string).
    str = "abcba";
    unordered_map<char, int> charHz;            // Stores each character in str as a key and the frequency of each character as a value.

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
    unordered_map<string, int> wordHz;      // Stores each word in str as a key and the frequency of each word as a value.
    stringstream ss(str);                   // Used to break down the string into words (substrings separated by spaces).
    string word;                            // An individual word from str2.

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