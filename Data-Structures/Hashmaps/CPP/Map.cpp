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

template <class K, class V>
class OrderedMap
{
private:
    map<K, V> _mp;

public:
    OrderedMap() {
        initializeMap();
    }

    void initializeMap(T data)
    {
        
    }
};

// Insert char-int key-value pairs into an unordered hash map.
void initializeMap(map<char, int>& mp, string str)
{
    // Each key is a character in str; each value is the index of the character in str.
    for (int i = 0; i < str.size(); i++)
        mp[str[i]] = i;
    cout << "Created hash map with " << mp.size() << " elements." << endl;
}

// Create a temporary key-value pair and copy it into a hash map.
void insertPair(map<char, int>& mp, char key, int val)
{
    pair<char, int> newPair (key, val); 
    mp.insert(newPair);
    
    // Another way...
    //uMp.insert(std::make_pair(key, val));
}

// Insert a new key-value pair into a hash map without creating a temporary key-value pair.
void emplacePair(map<char, int>& mp, char key, int val)
{
    mp.emplace(key, val);
}

// Check if a specific key in a hash map have has a specific value.
void checkValue(map<char, int>& mp, char key, int targetVal)
{
    // NOTE: if key does not exist in mp, it will automatically be added to mp with value '0'.
    if (mp[key] == targetVal)
        cout << "'" << key << "' does have the corresponding value '" << targetVal << "'" << endl;
    else
        cout << "'" << key << "' does not have the corresponding value '" << targetVal << "'" << endl;
}

// Print out the contents of a hash map.
void printMap(map<char, int>& mp)
{
    // Print each key-value pair in mp. 
    // NOTE: itr is an iterator for mp of type map<char, int>::iterator
    cout << "Hash map:" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << "["<< itr->first << ":" << itr->second << "]" << endl;
}

// Determine if a specific key exists within the hash map and remove it.
void removePair(map<char, int>& mp, char targetKey)
{
    // Search for the target key in the unordered hash map. If found, remove it with erase().
    // NOTE: find() returns an iterator of type map<char, int>::iterator.
    if (mp.find(targetKey) != mp.end())
    {
        mp.erase(targetKey);
        cout << "Found and removed element with key '" << targetKey << "'" << endl;
    }   
    else 
        cout << "Could not find element with key '" << targetKey << "'" << endl;
}

// Determine if a specific key exists within the hash map. If it does extract its node handle from the hash map and then put it 
// back into the hash map.
void extractPair(map<char, int>& mp, char targetKey)
{
    if (mp.find(targetKey) != mp.end())
    {
        auto nodeHandle = mp.extract(targetKey);
        cout << "Extracted element [" << nodeHandle.key() << ":" << nodeHandle.mapped() <<"]" << endl;

        // Put the node handle back into mp with move().
        mp.insert(std::move(nodeHandle));
    }
    else
        cout << "Could not find element with key '" << targetKey << "'" << endl;
}

// Determine the frequency of individual characters in a string.
void printCharFrequency(map<char, int>& mp, string str)
{
    // Iterate through each character in str; if a character appears more than once, add 1 to its frequency value.
    for (int i = 0; i < str.length(); i++)
        mp[str[i]]++;
    
    // Print each character that is in str along with its frequency value.
    cout << "Character frequency:" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
}

// Determine the frequency of individual words in a string.
void printWordFrequency(map<string, int>& mp, string str)
{
    stringstream ss(str);       // Used to break down the string into words (substrings separated by spaces).
    string word;                // An individual word from str2.

    // Iterate through each word in str; if a word appears more than once, add 1 to its frequency value.
    while (ss >> word)
        mp[word]++;
    
    // Print each word that is in str along with its frequency value.
    cout << "Word frequency:" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << "[" << itr->first << ":" << itr->second << "]" << endl;
}

int main()
{
    map<char, int> mp;                  // Stores characters as keys and their corresponding values are integers.
    initializeMap(mp, "Hello");         // Fill mp with each character in "Hello".
    cout << endl;
    
    insertPair(mp, '!', 5);

    emplacePair(mp, '?', 6);

    checkValue(mp, 'v', 7);
    cout << endl;

    extractPair(mp, '!');
    cout << endl;

    printMap(mp);
    cout << endl;

    removePair(mp, 'v');                // Remove element with key 'v' from mp.
    removePair(mp, 'v');                // Remove element with key 'v' from mp again.
    cout << endl;

    mp.clear();                         // Remove all key-value pairs from mp.

    string str = "abcba";
    map<char, int> charFreq;            // Stores each character in str as a key and the frequency of each word as a value.
    printCharFrequency(charFreq, str);
    cout << endl;

    str = "die die die death destruction turmoil turmoil death die";
    map<string, int> wordFreq;    // Stores each word in str as a key and the frequency of each word as a value.
    printWordFrequency(wordFreq, str);
    cout << endl;

    return 0;
}