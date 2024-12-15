/*
Algorithm:          Merge Two Sorted Lists (LeetCode Problem #21)

Task:               You are given two linked lists "list1" and "list2" that are sorted in nondecreasing order. Merge the two lists into 
                    one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of 
                    the merged linked list.

Solution:           To merge the two sorted lists into one sorted list, we basically need to perform a typical insert operation for linked
                    lists, where each of the nodes in list1 and list2 are iteratively inserted into a the new list one by one in 
                    nondecreasing order. First, we check whether list1 or list2 is empty, in which case we would simply return the head of
                    the other list. Then we compare the head node of list1 with the head node of list2 and assign the node with the 
                    lowest value as the head of the new list. After that, we iteratively insert the nodes of list1 and list2 into the new 
                    list in nondecreasing order until all the nodes from either list1 or list2 have been inserted. The rest of the nodes
                    in the list that still has nodes after the iterative insert operation are appended to the new list, and the head of
                    the new list is returned.

Time complexity:    O(M + N)
                        N = number of nodes in list1
                        M = number of nodes in list2

Space complexity:   O(M + N)
                        M = number of nodes in list1
                        N = number of nodes in list2

Auxiliary space:    O(M + N)
                        M + N = size of the merged list

Resources:          https://leetcode.com/problems/merge-two-sorted-lists/description/
                    https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
*/

#include <iostream>
using std::cout;
using std::endl;

// Definition for singly-linked list.
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    // If one of the lists is empty, return the head of the other list.
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    
    ListNode* head = new ListNode();    // Head of the merged list.

    // If list1.val is less than or equal to list2.val, assign the head of list1 as head and move to the next list1 node.
    if (list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;    // Visit the next node in list1.
    }
    // If list2.val is less than list1.val, assign the head of list2 as head and move to the next list2 node.
    else if (list1->val > list2->val)
    {
        head = list2;
        list2 = list2->next;    // Visit the next node in list2.
    }

    ListNode* mergedList = head;        // Pointer to the head node the merged list, which will either be the head of list1 or list2.
    ListNode* current = mergedList;     // Pointer to the node that will point to the next node to be inserted into the merged list.

    // NOTE: Since mergedList, head, and current point to the same address, changing the ->next attribute
    // of any of those pointers will change the ->next attribute for all the pointers.

    // Iteratively insert the rest of the nodes of the merged list.
    while (list1 != nullptr && list2 != nullptr)
    {
        // If list1.val is less than or equal to list2.val, insert it into the merged list and move to the next list1 node.
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        // If list2.val is less than list1.val, insert it into the merged list and move to the next list2 node.
        else if (list1->val > list2->val)
        {
            current->next = list2;
            list2 = list2->next; 
        }

        // Set the newly inserted node as the current node.
        current = current->next;
    }

    // If there are any nodes left in either list after the while loop, append the rest of the nodes in that list to the merged list.
    if (list1 == nullptr)
        current->next = list2;
    else if (list2 == nullptr)
        current->next = list1;
    
    return mergedList;
}

void printList(ListNode* list)
{
    ListNode* current = list;

    cout << "Merged list: ";
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
         
    cout << endl;
}

int main()
{
    // Test case 1.
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = mergeTwoLists(list1, list2);
    printList(list3);

    // Delete dynamically allocated pointers.
    delete list1;
    delete list2;


    // Test case 2.
    list1 = nullptr;
    list2 = nullptr;
    list3 = mergeTwoLists(list1, list2);
    printList(list3);


    // Test case 3.
    list1 = nullptr;
    list2 = new ListNode(0);
    list3 = mergeTwoLists(list1, list2);
    printList(list3);

    delete list2;
    

    return 0;
}