/*
Algorithm:          Two Sum using Hashmap (LeetCode Problem #1)

Task:               Given an array of integers nums and a target value, return indices of the two numbers such that they add up to 
                    target. Assume that each input would have exactly one solution, and the same element cannot be used twice.

Solution:           Iteratively subtract every integer in the array from the target value and store each difference (compliment) 
                    into a hash map. With each iteration, check the hash map to see if the current difference exists in the hash map;
                    if it does exist, then the current difference is a compliment of the current number in the array that will add up
                    to target.

Time complexity:    O(N)
                        N = number of integers in the array

Space complexity:   O(N)
                        N = number of integers in the array and the hash map

Auxiliary space:    O(N)
                        N = number of integers in the hash map

Resources:          https://leetcode.com/problems/two-sum/solutions/
*/

#include <iostream>
#include <vector>       
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> uMp;            // Stores each integer in nums as a key and each integer's index in nums as a value.
    
    for (int i = 0; i < nums.size(); i++)
    {
        int compliment = target - nums[i];   // Potential integer that, when added to nums[i], would equal target.
        
        // If the compliment exists in the map, return the index of compliment and nums[i].
        if(uMp.find(compliment) != uMp.end())
            return {uMp[compliment], i};
        // Otherwise, store nums[i] and its index in uMp.
        else
            uMp[nums[i]] = i;
    }

    // If no pair is found, return {-1, -1}.
    return {-1, -1};
}

int main() 
{
    vector<int> numVect = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]";

    numVect = {3, 2, 4};
    target = 6;
    result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;

    numVect = {2, 2};
    target = 4;
    result = twoSum(numVect, target);
    cout << "[" << result.at(0) << ", " << result.at(1) << "]" << endl;

    return 0;
}