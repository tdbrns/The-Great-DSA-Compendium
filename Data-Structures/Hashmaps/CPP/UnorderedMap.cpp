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

// Insert char-int key-value pairs into a hash map.
void initializeMap(unordered_map<char, int>& uMp, string str)
{
    // Store the characters of str as key-value pairs in uMp.
    // Each key is a character in str; each value is the index of the character in str.
    for (int i = 0; i < str.length(); i++)
        uMp[str[i]] = i;
}

// Print the number of buckets in a hash map and bucket in which each element of the hash map has been placed.
// NOTE: a hash function is performed on each element to determine the bucket it will be placed into.
// NOTE: The bucket count of a hash map will always increase to accommodate the number of elements being inserted.
void printBucketInfo(unordered_map<char, int>& uMp)
{
    cout << "Bucket count: " << uMp.bucket_count() << endl;
    
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "Element [" << itr->first << ":" << itr->second << "] is in bucket #" << uMp.bucket(itr->first) << endl;
}

// Create a temporary key-value pair and copy it into a hash map.
void insertPair(unordered_map<char, int>& uMp, char key, int val)
{
    pair<char, int> newPair (key, val); 
    uMp.insert(newPair);
}

// Insert a new key-value pair into a hash map without creating a temporary key-value pair.
void emplacePair(unordered_map<char, int>& uMp, char key, int val)
{
    uMp.emplace(key, val);
}

// Check if a specific key in a hash map have has a specific value.
void checkValue(unordered_map<char, int>& uMp, char key, int targetVal)
{
    // NOTE: if key does not exist in uMp, it will automatically be added to uMp with value '0'.
    if (uMp[key] == targetVal)
        cout << "'" << key << "' does have the corresponding value '" << targetVal << "'" << endl;
    else
        cout << "'" << key << "' does not have the corresponding value '" << targetVal << "'" << endl;
}

// Print out the contents of a hash map.
void printMap(unordered_map<char, int>& uMp)
{
    // Print each key-value pair in uMp. 
    // NOTE: itr is an iterator for uMp of type unordered_map<char, int>::iterator
    cout << "hash map:" << endl;
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "["<< itr->first << ":" << itr->second << "]" << endl;
}

// Determine if a specific key exists within the hash map and remove it.
void removePair(unordered_map<char, int>& uMp, char targetKey)
{
    // Search for the target key in the unordered hash map. If found, remove it with erase().
    // NOTE: find() returns an iterator of type unordered_map<char, int>::iterator.
    if (uMp.find(targetKey) != uMp.end())
    {
        uMp.erase(targetKey);
        cout << "Found and removed element with key '" << targetKey << "'" << endl;
    }   
    else 
        cout << "Could not find element with key '" << targetKey << "'" << endl;
}

// Determine if a specific key exists within the hash map. If it does extract its node handle from the hash map and then put it 
// back into the hash map.
void extractPair(unordered_map<char, int>& uMp, char targetKey)
{
    if (uMp.find(targetKey) != uMp.end())
    {
        auto nodeHandle = uMp.extract(targetKey);
        cout << "Extracted element [" << nodeHandle.key() << ":" << nodeHandle.mapped() <<"]" << endl;

        // Put the node handle back into uMp with move().
        uMp.insert(std::move(nodeHandle));
    }
    else
        cout << "Could not find element with key '" << targetKey << "'" << endl;
}

// Determine the frequency of individual characters in a string.
void printCharFrequency(unordered_map<char, int>& uMp, string str)
{
    // Iterate through each character in str; if a character appears more than once, add 1 to its frequency value.
    for (int i = 0; i < str.length(); i++)
        uMp[str[i]]++;
    
    // Print each character that is in str along with its frequency value.
    cout << "Character frequency:" << endl;
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
}

// Determine the frequency of individual words in a string.
void printWordFrequency(unordered_map<string, int>& uMp, string str)
{
    stringstream ss(str);       // Used to break down the string into words (substrings separated by spaces).
    string word;                // An individual word from str2.

    // Iterate through each word in str; if a word appears more than once, add 1 to its frequency value.
    while (ss >> word)
        uMp[word]++;
    
    // Print each word that is in str along with its frequency value.
    cout << "Word frequency:" << endl;
    for (auto itr = uMp.begin(); itr != uMp.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
}

int main()
{
    string str = "Hello";
    unordered_map<char, int> uMp;           // Stores each character of str as a key and each character's index in str as a value.
    initializeMap(uMp, str);                // Fill uMp with each character in "Hello".

    printBucketInfo(uMp);
    cout << endl;

    insertPair(uMp, '!', 5);

    emplacePair(uMp, '?', 6);

    checkValue(uMp, 'v', 7);
    cout << endl;

    extractPair(uMp, '!');
    cout << endl;

    printMap(uMp);
    cout << endl;

    removePair(uMp, 'v');                   // Remove element with key 'v' from uMp.
    removePair(uMp, 'v');                   // Remove element with key 'v' from uMp again.
    cout << endl;

    uMp.clear();                            //  Remove all key-value pairs from uMp.

    string str = "abcba";
    unordered_map<char, int> charFreq;      // Stores each character in str as a key and the frequency of each word as a value.
    printCharFrequency(charFreq, str);
    cout << endl;

    str = "die die die death destruction turmoil turmoil death die";
    unordered_map<string, int> wordFreq;    // Stores each word in str as a key and the frequency of each word as a value.
    printWordFrequency(wordFreq, str);
    cout << endl;

    return 0;
}