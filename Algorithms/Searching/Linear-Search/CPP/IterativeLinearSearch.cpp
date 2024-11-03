/*
Algorithm:          Iterative Linear Search 
Characteristics:    Brute-force
Time complexity:    O(N)
Space complexity:   O(1)
Task:               Search for a specific value in a sorted array.
Solution:           Search for the target value in the sorted array using a Linear Search algorithm.
Resources:          https://www.geeksforgeeks.org/linear-search/
*/

#include <iostream>
using namespace std;

bool IterativeLinearSearch(int arr[], int size, int target)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            found = true;
            break;
        }
    }

    return found;
}


int main()
{
    int numArray[] = {5, 13, 24, 27, 33, 40, 41};
    int arrSize = sizeof(numArray) / sizeof(numArray[0]);
    int target1 = 33;
    int target2 = 32;

    auto targetFound = IterativeLinearSearch(numArray, arrSize, target1);
    (targetFound) ? cout << "First target found!\n" : cout << "First target not found.\n";

    targetFound = IterativeLinearSearch(numArray, arrSize, target2);
    (targetFound) ? cout << "Second target found!\n" : cout << "Second target not found.\n";

    return 0;
}