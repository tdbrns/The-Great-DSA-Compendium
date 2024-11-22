/*
Algorithm:          Find the Product Seeds of an Integer

Task:               A "product seed" of a positive integer is a number that, when multiplied by the product of its digits, equals the
                    original number (e.g., 12 is a product seed of 24 because 1 * 2 * 12 = 24). Write a function that takes a positive
                    integer as input and returns all of its product seeds. If the integer has no product seeds, indicate that there 
                    are none.

Solution:           Since the product seed of an integer should be a factor of the integer, find all the factors of the integer and 
                    check each factor to see if it is a product seed of the integer.

Time complexity:    O(N)
                        M = number of integers in range 1 to sqrt(num) and the number of digits in the input number

Space complexity:   O(N)
                        N = number of factors of num and the number of seeds of num

Auxiliary space:    O(N)
                        N = number of factors of num and the number of seeds of numS

Resources:          https://www.geeksforgeeks.org/seeds-or-seed-roots-of-a-number/
*/

#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::sqrt;

// getFactors() has time complexity of O(sqrt(N)).
vector<int> getFactors(int num)
{
    vector<int> factors;

    for (int i = 1; i < sqrt(num); i++)
    {
        // If num is divisible by i, add it to factors.
        if (num % i == 0)
        {
            if (num / i == i)
                factors.push_back(i);
            else
            {
                factors.push_back(i);
                factors.push_back(num / i);
            }
        }
    }

    return factors;
}

// getDigitProduct() has time complexity O(N)
int getDigitProduct(int num)
{
    int product = 1;        // Product of the digits of an integer. Must be initialized to 1.
    while (num > 0)
    {
        product *= num % 10;    // Multiply the digit currently in the one place of num by product.
        num /= 10;              // Divide num by 10 to move all digits down by 1 place.
    }
        
    return product;
}

// printProductSeeds() has time complexity O(N).
void printProductSeeds(int num)
{
    vector<int> seeds;

    // If the integer only has 1 digit, it has no product seeds.
    if (num < 10)
        cout << "No product seeds found for " << num;
    else
    {
        vector<int> factors = getFactors(num);      // Vector containing all the factors of num.

        // Check each factor of num to see if it is a product seed.
        for (int i = 0; i < factors.size(); i++)
        { 
            if (factors[i] * getDigitProduct(factors[i]) == num)
                seeds.push_back(factors[i]);
        }

        if (seeds.size() == 0)
            cout << "No product seeds found for " << num;
        else
        {
            cout << "Product seeds for " << num << ": ";
            for (int i = 0; i < seeds.size(); i++)
                cout << seeds[i] << " ";
        }
    }
}

int main()
{
    int num = 138;
    printProductSeeds(num);
    cout << endl;

    num = 4977;
    printProductSeeds(num);
    cout << endl;

    num = 11;
    printProductSeeds(num);
    cout << endl;

    num = 9;
    printProductSeeds(num);
    cout << endl;
    
    return 0;
}