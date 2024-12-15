/*
Algorithm:          Linked List Cycles (LeetCode Problem #141)

Task:               Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list
                    if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos 
                    is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a 
                    parameter. Return true if there is a cycle in the linked list. Otherwise, return false.
                    NOTE:
                        • If the linked list is empty, it does not have a cycle.

Solution:           Use Floyd's cycle finding algorithm, which involves traversing the linked list with two pointers moving at different
                    speeds. 
                    In this solution, we use a pointer that traverses the list 1 node at a time and a pointer that traverses the list 2 
                    nodes at a time. Both pointers start at the head of the list and traverse the linked list at their respective speeds 
                    until one of them becomes null or both of them point to the same node in the list. This can be used to indicate a 
                    cycle.
                    NOTE:
                        • If at least one of the pointers becomes null, the linked list has no cycles.
                        • If both pointers point to the same node, then the linked list has a cycle.

Time complexity:    O(N)
                        N = number of nodes in the linked list

Space complexity:   O(N)
                        N = number of nodes in the linked list

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/linked-list-cycle/solutions/
*/

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;

// Description for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) 
{
    // If the list is empty, return false.
    if (head == nullptr)
        return false;
    
    ListNode* oneNode = head;       // Pointer that traverses the linked list 1 node at a time.
    ListNode* twoNode = head;       // Pointer that traverses the linked list 2 nodes at a time.

    // Traverse the linked list with the two pointers.
    while (oneNode != nullptr && twoNode != nullptr)
    {
        oneNode = oneNode->next;
        twoNode = twoNode->next;
        if (twoNode != nullptr)
            twoNode = twoNode->next;
        
        // If oneNode and twoNode point to the same node and the node, we have a cycle.
        if (oneNode == twoNode && oneNode != nullptr)
            return true;
    }

    return false;
}

// Delete all nodes in a linked list that may or may not have a cycle.
void clearList(ListNode* head)
{
    unordered_map<ListNode*, int> nodeAddresses;       // Stores addresses of deleted nodes as keys and their frequency as values.

    // Traverse the linked list and delete each visited node. If the node has already been deleted, end the loop.
    while (head != nullptr)
    {
        ListNode* nextNode = head->next;
        if (nodeAddresses[head] == 0)
        {
            nodeAddresses[head]++;
            delete head;
            head = nextNode;
        }
        else
            head = nullptr;
    }
}

int main()
{
    // Test case 1
    /* Create linked list below:
        3 → 2 → 0 → -4
            ↑        ↓
            ↑   ←    ←
    */
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    (hasCycle(head)) ? cout << "There is a cycle in the list.\n" : cout << "There is not a cycle in the list.\n";
    clearList(head);

    // Test case 2
    /* Create linked list below:
        1 → 2
        ↑   ↓
        ↑   ←
    */
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    (hasCycle(head)) ? cout << "There is a cycle in the list.\n" : cout << "There is not a cycle in the list.\n";
    clearList(head);

    // Test case 3
    /* Create linked list below:
        1 → 
    */
    head = new ListNode(1);
    (hasCycle(head)) ? cout << "There is a cycle in the list.\n" : cout << "There is not a cycle in the list.\n";
    clearList(head);

    return 0;
}