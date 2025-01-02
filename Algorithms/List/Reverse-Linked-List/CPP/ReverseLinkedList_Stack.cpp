/*
Algorithm:          Reverse Linked List using Stack (LeetCode Problem #206)

Task:               Given the head of a singly linked list, reverse the list, and return the reversed list.

Solution:           Starting at the head of the list, iteratively push the value of each node in the list onto a stack. Then create a 
                    new linked list that stores each value of the original list in reverse order by iteratively storing the top value
                    on the stack into the linked list and popping the top value from the stack.

Time complexity:    O(N)
                        N = number of nodes in the linked list

Space complexity:   O(N)
                        N = number of nodes in the linked list / size of the stack

Auxiliary space:    O(N)
                        N = size of the stack

Resources:          https://www.geeksforgeeks.org/reverse-a-linked-list/
                    https://leetcode.com/problems/reverse-linked-list/solutions/
*/


#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) 
{
    // If the list is empty, return nullptr.
    if (!head)
        return nullptr;
    
    // Store the values of the input list into a stack.
    stack<int> stack;
    while (head != nullptr)
    {
        stack.push(head->val);
        head = head->next;
    }

    // Create the reverse list by iteratively popping the top of the stack.
    ListNode* revHead = new ListNode(stack.top());
    stack.pop();

    ListNode* current = revHead;
    
    while (!stack.empty())
    {   
        current->next = new ListNode(stack.top());
        stack.pop();
        current = current->next;
    }
    return revHead;
}

// Print the contents of the list.
void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Delete each node in the list.
void deleteList(ListNode* head)
{
    if (head != nullptr)
    {
        deleteList(head->next);
        delete head;
    }
}

int main()
{
    /* Test case 1. Create the linked list below:
        1 -> 2 -> 3 -> 4 -> 5
    */
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printList(head);
    printList(reverseList(head));

    deleteList(head);

    /* Test case 2. Create the linked list below:
        1 -> 2
    */
    head = new ListNode(1);
    head->next = new ListNode(2);
    printList(head);
    printList(reverseList(head));

    deleteList(head);

    // Test case 3. Reverse an empty list.
    head = nullptr;
    printList(head);
    printList(reverseList(head));

    return 0;
}