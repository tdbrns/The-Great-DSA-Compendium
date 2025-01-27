'''
Algorithm:          Well-Ordered Numbers

Task:               A well-ordered number is a number with digits that are in strictly increasing order from left to right (e.g., 123, 
                    124, 3589, etc.). Given a number of digits n, find all well-ordered number with n digits. n can be any number from
                    1 to 9.

Solution:           Use a recursive function to print out each possible well-ordered number with n digits.

Time complexity:    O(N * 2^N)
                        N = number of digits n
                        2^N = number of n-digit numbers to be generated

Space complexity:   O(N)
                        N = maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/generate-k-digit-numbers-digits-strictly-increasing-order/
'''


'''Variables:
    num = current number that may be printed. Initialized at 0.
    x = number of digits from 1 to 9 that cannot be considered. Initialized at 0.
    n = number of digits left to be considered.
    i = the digit from 1 to 9 being considered with each iteration of the for loop. The number of digits to be considered will 
        decrease as x increases.
'''
def print_well_ordered_numbers(num, x, n):
    # Base case; if n equals 0, num is a well-ordered number with n digits.
    if n == 0:
        print(num)
        return

    # Recursively call print_well_ordered_numbers() until all well-ordered numbers have been printed.
    for i in range(x + 1, 10):
        print_well_ordered_numbers(num * 10 + i, i, n - 1)

''' print_well_ordered_numbers() when n = 2:
    init.   print_well_ordered_numbers(0, 0, 2)
    1.      print_well_ordered_numbers(1, 1, 1)
    2.      print_well_ordered_numbers(12, 2, 0) -> print 12; return
    3.      print_well_ordered_numbers(13, 3, 0) -> print 13; return
    4.      print_well_ordered_numbers(14, 4, 0) -> print 14; return
    5.      print_well_ordered_numbers(15, 5, 0) -> print 15; return
    6.      print_well_ordered_numbers(16, 6, 0) -> print 16; return
    7.      print_well_ordered_numbers(17, 7, 0) -> print 17; return
    8.      print_well_ordered_numbers(18, 8, 0) -> print 18; return
    9.      print_well_ordered_numbers(19, 9, 0) -> print 19; return
    10.     print_well_ordered_numbers(2, 2, 1)
    11.     print_well_ordered_numbers(23, 3, 0) -> print 23; return
    12.     print_well_ordered_numbers(24, 4, 0) -> print 24; return
    ...
'''

# Wrapper for print_well_ordered_numbers().
def get_well_ordered_numbers(n):
    print_well_ordered_numbers(0, 0, n)

if __name__ == "__main__":
    # Test case 1.
    n = 2
    get_well_ordered_numbers(n)
