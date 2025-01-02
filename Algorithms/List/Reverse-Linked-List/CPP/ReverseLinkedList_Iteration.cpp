/*
Algorithm:          Reverse Linked List using Iteration (LeetCode Problem #206)

Task:               Given the head of a singly linked list, reverse the list, and return the reversed list.

Solution:           Starting from the head node, reverse the linked list by iteratively reversing the pointer of each node in the list. 
                    At the end of the operation, the next pointer of each node should point to the previous node in the list instead 
                    of the next node in the list.

Time complexity:    O(N)
                        N = number of nodes in the linked list

Space complexity:   O(N)
                        N = number of nodes in the linked list

Auxiliary space:    O(1)

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
    ListNode* prev = nullptr;       // Previous node.
    ListNode* curr = head;          // Current node.
    ListNode* next = nullptr;       // Next node.

    while (curr != nullptr)
    {
        // 1 - 2 - 3 - 4 - 5
        // Store the next node of current 
        next = curr->next;      // Store the next node of curr into next.
        curr->next = prev;      // Set the next pointer of curr to point to the previous node
        
        // Move to reverse the next node in the list by setting prev to curr and curr to next.
        prev = curr;
        curr = next;
    }

    // Return the head node of the reversed linked list.
    return prev;
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