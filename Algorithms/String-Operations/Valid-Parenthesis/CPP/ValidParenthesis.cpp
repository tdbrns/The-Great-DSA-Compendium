/*
Algorithm:          Valid Parenthesis (LeetCode Problem #20)

Task:               Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is 
                    valid. An input string is valid if:
                        • Open brackets are closed by the same type of brackets.
                        • Open brackets are closed in the correct order.
                        • Every close bracket has a corresponding open bracket of the same type.

Solution:           We can solve this problem by using a stack. Iterate through each character of the string from the first character to
                    the last. When an open bracket - '(', '{', or '[' - is found, push it onto the top of a stack. When a close bracket 
                    - ')', '}', or ']' - is found, compare it to the open bracket at the top of the stack. If the close bracket is the 
                    same type as the open bracket, pop the open bracket from the stack; if the close bracket is not the same type as the
                    open bracket, then the string is invalid since the open bracket does not have a matching close bracket.
                    The string can also be invalid in a case where there are more open brackets than close brackets or vice versa. We
                    can check for this case by checking the size of the stack. If the stack is empty while the for-loop is still running,
                    then there are too many close brackets; if the stack is not empty after the for-loop is finished, then there are too
                    many open brackets. 

Time complexity:    O(N)
                        N = length of input string

Space complexity:   O(N)
                        N = length of input string / number of open brackets stored in the stack

Auxiliary space:    O(N)
                        N = number of open brackets stored in the stack

Resources:          https://leetcode.com/problems/valid-parentheses/solutions/
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool isValid(string s) 
{
    vector<char> charStack;         // Stack containing each open bracket in s in order of appearance.

    for (int i = 0; i < s.length(); i++)
    {
        // Store open brackets into the stack.
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            charStack.push_back(s[i]); 
        else if (!charStack.empty())
        {
            // Check if the close bracket is the same type as the open bracket; if not, return false
            if (s[i] == ')' && charStack.back() == '(')
                charStack.pop_back();
            else if (s[i] == '}' && charStack.back() == '{')
                charStack.pop_back();
            else if (s[i] == ']' && charStack.back() == '[')
                charStack.pop_back();
            else
                return false;
        }
        // If charStack is empty here, there are too many close brackets.
        else
            return false;
    }

    // If charStack is mpty here, there are too many open brackets
    if (!charStack.empty())
        return false;
    else
        return true;
}

int main()
{
    string validStr = "()";
    (isValid(validStr)) ? printf("The 1st string is valid.\n") : printf("The 1st string is invalid.\n");

    validStr = "[()]";
    (isValid(validStr)) ? printf("The 2nd string is valid.\n") : printf("The 2nd string is invalid.\n");

    validStr = "[[({[()]})]]";
    (isValid(validStr)) ? printf("The 3rd string is valid.\n") : printf("The 3rd string is invalid.\n");

    string invalidStr = "{(])}";
    (isValid(invalidStr)) ? printf("The 4th string is valid.\n") : printf("The 4th string is invalid.\n");

    invalidStr = "{";
    (isValid(invalidStr)) ? printf("The 5th string is valid.\n") : printf("The 5th string is invalid.\n");

    invalidStr = ")";
    (isValid(invalidStr)) ? printf("The 6th string is valid.\n") : printf("The 6th string is invalid.\n");

    return 0;
}