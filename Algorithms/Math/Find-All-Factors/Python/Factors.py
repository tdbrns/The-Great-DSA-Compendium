'''
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
'''

from math import sqrt

def print_factors(num):
    print(f"Factors of {num}:", end=" ")

    # If num if 0, print 0.
    if num == 0:
        print("0")
        return
    # If num is 1, print 1.
    elif num == 1:
        print("1")
        return

    # Find all factor pairs of num.
    for i in range(1, int(sqrt(num) + 1)):
        if num % i == 0:
            quotient = int(num / i)
            
            # If the numbers in the factor pair are the same, only print one of them; otherwise, print both of them.
            if quotient == i:
                print(f"{i}", end=" ")
            else:
                print(f"{i} {quotient}", end=" ")
    print()

if __name__ == "__main__":
    # Test case 1.
    num = 0
    print_factors(num)

    # Test case 2.
    num = 144
    print_factors(num)

    # Test case 3.
    num = 71
    print_factors(num)
