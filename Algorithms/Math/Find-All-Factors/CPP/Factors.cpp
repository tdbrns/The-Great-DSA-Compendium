/*
Algorithm:          Find All the Factors of an Integer.

Task:               Print all the factors of a given positive integer.

Solution:           Factors typically come in pairs of integers that, when multiplied together, will produce the given positive integer.
                    For example, {1, 12}, {2, 6}, {3, 4} are factor pairs of 12 because the numbers in each pair will produce 12 when
                    they are multiplied together. We can use factor pairs to find all of the factors of any positive integer.

Time Complexity:    O(sqrt(N))
                        N = the given positive integer

Space Complexity:    O(1)

Auxiliary space:     O(1)

Resources:          https://www.geeksforgeeks.org/find-all-factors-of-a-natural-number/
*/

#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::sqrt;

void printFactors(int num)
{
    cout << "Factors of " << num << ": ";

    // If num is 0, print 0.
    if (num == 0)
    {
        cout << "0";
        return;
    }
    // If num is 1, print 1.
    else if (num == 1)
    {
        cout << "1";
        return;
    }

    // Find all the factor pairs of num.
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            // If the numbers in the factor pair are the same, only print one of them.
            if (num == i)
                cout << i << " ";
            // If the numbers in the factor pair are different, print both of them
            else
                cout << i << " " << num / i << " ";
        }
    }
}

int main()
{
    int num = 0;
    printFactors(num);
    cout << endl;

    num = 144;
    printFactors(num);
    cout << endl;

    num = 71;
    printFactors(num);
    cout << endl;

    return 0;
}