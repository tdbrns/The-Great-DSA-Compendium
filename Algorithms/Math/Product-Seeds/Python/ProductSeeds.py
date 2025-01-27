'''
Algorithm:          Find the Product Seeds of an Integer

Task:               A "product seed" of a positive integer is a number that, when multiplied by the product of its digits, equals the
                    original number (e.g., 12 is a product seed of 24 because 1 * 2 * 12 = 24). Write a function that takes a positive
                    integer as input and returns all of its product seeds. If the integer has no product seeds, indicate that there 
                    are none.

Solution:           Since the product seed of an integer should be a factor of the integer, find all the factors of the integer and store
                    them in a list. Then check each factor to see if it is a product seed of the integer.

Time complexity:    O(N)
                        N = number of integers in range 1 to sqrt(num) and the number of digits in the input number
                        • get_factors() has time complexity O(sqrt(N))
                        • get_digit_products() has time complexity O(N)
                        • print_product_seeds() has time complexity O(N)

Space complexity:   O(N)
                        N = number of factors of num and the number of seeds of num

Auxiliary space:    O(N)
                        N = number of factors of num and the number of seeds of numS

Resources:          https://www.geeksforgeeks.org/seeds-or-seed-roots-of-a-number/
'''


from math import sqrt

# Find all factors of a number and return them in a list.
def get_factors(num):
    factors = []

    for i in range(1, int(sqrt(num)) + 1):
        if num % i == 0:
            quotient = int(num / i)
            if (quotient == i):
                factors.append(i)
            else:
                factors.append(i)
                factors.append(quotient)
    return factors    

# Calculate the product of each digit in a number and return the product.
def get_digit_products(num):
    product = 1

    while num > 0:
        product *= num % 10     # Multiply the digit currently in the one place of num by product.
        num = num // 10         # Divide num by 10 to move all digits down by 1 place.

    return product

def print_product_seeds(num):
    if num < 10:
        print(f"No product seeds found for {num}")
    else:
        seeds: list[int] = []
        factors: list[int] = get_factors(num)

        # Check each factor of num to see if it is a product seed.
        for i in range(0, len(factors)):
            if factors[i] * get_digit_products(factors[i]) == num:
                seeds.append(factors[i])
        
        # If the integer has product seeds, print each of them.
        if len(seeds) != 0:
            print(f"Product seeds for {num}:", end=" ")
            for seed in seeds:
                print(seed, end=" ")
            print()
        else:
            print(f"No product seeds found for {num}")

if __name__ == "__main__":
    # Test case 1.
    num = 138
    print_product_seeds(num)

    # Test case 2.
    num = 4977
    print_product_seeds(num)

    # Test case 3.
    num = 11
    print_product_seeds(num)

    # Test case 4.
    num = 9
    print_product_seeds(num)
