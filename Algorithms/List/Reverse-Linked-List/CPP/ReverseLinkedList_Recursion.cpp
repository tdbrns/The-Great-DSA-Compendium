/*
Algorithm:          Reverse Linked List using Recursion (LeetCode Problem #206)

Task:               Given the head of a singly linked list, reverse the list, and return the reversed list.

Solution:           First, recursively move to the tail node of the list. Then, from the tail node, recursively reverse the next pointer
                    of each node until the head of the original list is reached. At the end of the operation, the next pointer of each 
                    node should point to the previous node in the list instead of the next node in the list.

Time complexity:    O(N)
                        N = number of nodes in the linked list

Space complexity:   O(N)
                        N = number of nodes in the linked list / maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/reverse-a-linked-list/
                    https://leetcode.com/problems/reverse-linked-list/solutions/
*/


#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) 
{
    // Base case; when the end of the list has been reached, return head.
    if (head == nullptr || head->next == nullptr)
        return head;

    // The head of the reversed list, which is the last node in the original list.
    // NOTE: the head of revList is the last node in the original list.
    ListNode* revList = reverseList(head->next);        

    // Update the next pointer of the next node with head.
    head->next->next = head;        

    // Update the next pointer of head with nullptr to indicate that it is the current tail of the reversed list.
    head->next = nullptr;           

    // Return the current reversed list.
    return revList;
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