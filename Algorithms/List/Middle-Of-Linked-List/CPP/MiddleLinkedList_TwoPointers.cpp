/*
Algorithm:          Middle of the Linked List (LeetCode Problem #876)

Task:               Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, 
                    return the second middle node.

Solution:           Use the Tortoise and Hare algorithm to find the middle node. Create two pointers that iteratively traverse the list
                    at different speeds - a pointer that moves one node at a time and another pointer that moves two nodes at a time. 
                    When the faster pointer reaches the tail node of the list, the slower pointer will always land on the middle node of
                    the list. Return the node that the slower pointer lands on at the end of the iteration.

Time complexity:    O(N)
                        N = number of nodes in the linked list

Space complexity:   O(N)
                        N = number of nodes in the linked list

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/middle-of-the-linked-list/solutions/
                    https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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

ListNode* middleNode(ListNode* head) {
    ListNode* oneStep = head;       // Pointer that moves 1 node per iteration.
    ListNode* twoStep = head;       // Pointer that moves 2 nodes per iteration if possible.

    // Traverse the list with both pointers moving at their respective speeds. Note that twoStep always moves first because it is 
    // usually the pointer that determines when the tail node is reached and, thus, determines when the loop ends.
    while (oneStep != nullptr && twoStep != nullptr) {
        twoStep = twoStep->next;

        if (twoStep != nullptr) {
            oneStep = oneStep->next;
            twoStep = twoStep->next;
        }   
    }

    return oneStep;
}

// Delete all nodes in a linked list.
void clearList (ListNode* head) {
    ListNode* nextNode = head->next;

    while (head) {
        nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main() {
    // Test case 1.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "The middle node is " << middleNode(head)->val << endl;
    clearList(head);

    // Test case 2.
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    cout << "The middle node is " << middleNode(head)->val << endl;
    clearList(head);

    return 0;   
}