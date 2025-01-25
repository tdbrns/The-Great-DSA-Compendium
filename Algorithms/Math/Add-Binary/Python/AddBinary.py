'''
Algorithm:          Add Binary (LeetCode Problem #409)

Task:               Given two binary strings a and b, return their sum as a binary string.

Solution:           Iteratively perform binary addition with a[i], b[j], and the value carried from the preceding binary addition
                    operation. 
                    First convert the characters a[i] and b[j] into their integer form by subtracting the ASCII value of '0' (48) from 
                    the ASCII value of the characters. Then we add the resulting integers together along with the value that was carried 
                    over from the previous binary addition operation. If the resulting sum is greater than 1, then the sum is set to 0
                    and a value of 1 is carried over to the binary addition operation of the next iteration. Then the final sum is 
                    inserted to the front of the result string. This process is repeated until each character in a and b has been 
                    processed. 
                    If the carried value is still 1 after all the characters in a and b have been processed, insert "1" at the front 
                    result string. Finally, return the result.

Time complexity:    O(max(M, N))
                        M = length of string a
                        N = length of string b

Space complexity:   O(M + N)
                        M = length of string a
                        N = length of string b

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/add-binary/solutions/
'''


def addBinary(a, b):
    i = len(a) - 1      # Index of string a.
    j = len(b) - 1      # Index of string b.
    carry = 0           # The carried value.
    result = ""         # Result string.

    # Iteratively perform binary addition until all binary digits have been processed.
    while (i >= 0 or j >= 0):
        sum = carry         # Sum of the current set of binary digits.

        # Get the ASCII value of a[i] and b[i], subtract the ASCII value of '0' (48) from each both values, and add the two differences
        # together.
        if (i >= 0):
            sum = sum + (ord(a[i]) - ord('0'))
        if (j >= 0):
            sum = sum + (ord(b[j]) - ord('0'))
        
        # If the sum is greater than 1, set carry to 1; otherwise, set carry to 0.
        carry = 1 if sum > 1 else 0

        # Insert the result of sum % 2 at the front of the result string.
        ''' Example
             if sum = 0; 0 % 2 = 0
             if sum = 1; 1 % 2 = 1
             if sum = 2; 2 % 2 = 0
             if sum = 3; 3 % 2 = 1
        '''
        result = str(sum % 2) + result

        # Decrement i and j by 1.
        i = i - 1
        j = j - 1
    
    # If carry equals 1, insert it at the front of the result string.
    if carry == 1:
        result = str(carry) + result

    return result


# Test case 1.
a = "11"
b = "1"
print(f"The sum of {a} and {b} is {addBinary(a, b)}")

# Test case 2.
a = "1010"
b = "1011"
print(f"The sum of {a} and {b} is {addBinary(a, b)}")