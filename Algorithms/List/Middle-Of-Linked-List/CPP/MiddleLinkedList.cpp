/*
Algorithm:          Middle of the Linked List (LeetCode Problem #876)

Task:               Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, 
                    return the second middle node.

Solution:           Iteratively count each node in the list and store the sum in n. Next, divide n by 2 to get the position of the
                    middle node in the list. Then, traverse the list starting from the head until the node at the middle position 
                    is reach. Finally, return the middle node.

Time complexity:    O(N)
                        N = number of nodes in the linked list
                        NOTE: since the linked list must be traversed twice, the unsimplified time complexity would be O(N) + O(N/2).

Space complexity:   O(N)
                        N = number of nodes in the linked list

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/middle-of-the-linked-list/solutions/
                    https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
*/


#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int n = 0;                  // Number of nodes in the list.
    ListNode* current = head;   // Current node pointer.

    // Traverse the list to count all the nodes.
    while (current != nullptr) 
    {
        n++;
        current = current->next;
    }

    int mid = n / 2;            // Position of the middle node in the list.
    current = head;

    // Traverse the list to get the node at the middle position.
    for (int i = 0; i < mid; i++)
        current = current->next;
    
    return current;
}

// Delete all nodes in a linked list.
void clearList (ListNode* head) {
    ListNode* nextNode = head->next;

    while (head) 
    {
        nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main() {
    // Test case 1.
    /* Create the linked list below:
        1 -> 2 -> 3 -> 4 -> 5
    */
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