/*
Structure:          Singly Linked List 
Task:               Create a data structure that sorts integers in ascending order without duplicate values.
Solution:           Use a singly linked list class that can be used to store any given integers in ascneding order. Integers are
                    entered into the linked list as ListNodes, which are structs that can hold a data value and a pointer to the next
                    ListNode in the list. This data structure utilizes operations for inserting ListNodes into the list, removing ListNodes
                    from the list, printing out the data values of the list, and returning the number of values the list holds all
                    while keeping the data values sorted in ascending order.
Resources:          https://www.geeksforgeeks.org/singly-linked-list-tutorial/
*/

#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
    int data;               // Integer value of a ListNode.
    ListNode* next;         // Pointer to next ListNode in a linked list

    // Constructor for ListNode struct.
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    
    ListNode* _head;        // The head ListNode of the list.
    int _size;          // The number of ListNodes in the list.

public:
    // Constructor for SinglyLinkedList class
    SinglyLinkedList()
    {
        _head = nullptr;
        _size = 0;
    }

    // Destructor for SinglyLinkedList class.
    ~SinglyLinkedList()
    {
        clearList();
    }

    // Consecutively delete all ListNodes from the list beginning at the head ListNode.
    void clearList()
    {
        ListNode* current = _head;       // The current head ListNode of the linked list.
		
		while (_head != nullptr)	
		{
			_head = _head->next;
			delete current;
			current = _head;
		}

		_size = 0;
    }

    // Insert a new ListNode with new data into the linked list.
    bool insert(int newData)
    {
        // If the linked list does not exist, insert the new ListNode as the head of the list
        if (!_head)
        {
            ListNode* newListNode = new ListNode(newData);          // ListNode to be inserted.
            _head = newListNode;
            _size++;

            return true;
        }
        else
        {
            ListNode* current = _head;               // Pointer to the current ListNode being checked in the search.

            // Starting at the head ListNode, search for the ListNode in the list with a value that is grater than/equal to the new data.
            while (current != nullptr && newData > current->data)
                current = current->next;
            
            // Reject values that already exist in the list.
            if (current != nullptr && newData == current->data)
                return false;
            
            // If the head ListNode has a value that is less than/equal to the new data, insert the data as the new head ListNode.
            if (current == _head)
            {
                ListNode* newListNode = new ListNode(newData);      // ListNode with new data to be inserted.

                // Insert the new ListNode.
                newListNode->next = _head;
                _head = newListNode;
                _size++;

                return true;
            }
            // If no ListNode in the list has a value that is less than/equal to the new data, insert the data as a ListNode at the end of the
            // list.
            else if (current == nullptr)
            {
                ListNode* tail = _head;                      // The last ListNode of the list.
                ListNode* newListNode = new ListNode(newData);       // ListNode to be inserted.
                
                // Traverse the list to find the last ListNode.
                while (tail->next != nullptr)
                    tail = tail->next;

                // Insert the ListNode.
                tail->next = newListNode;
                _size++;

                return true;
            }
            // Otherwise, insert the data as a ListNode between the current ListNode and the ListNode before the current ListNode.
            else
            {
                ListNode* newListNode = new ListNode(newData);      // ListNode to be inserted.
                ListNode* prevListNode = _head;                 // ListNode before the current ListNode.

                // Traverse the linked list to find the ListNode before the current ListNode.
                while (prevListNode->next != current)
                    prevListNode = prevListNode->next;

                // Insert the new ListNode in between the current ListNode and the ListNode that comes after the current ListNode.
                prevListNode->next = newListNode;
                newListNode->next = current;
                _size++;

                return true;
            }
        }
    }

    // Remove a ListNode from the linked list.
    bool remove(int target)
    {
        // If the list does not exist, return false.
        if (!_head)
            return false;
        else
        {
            ListNode* current = _head;          // Pointer to the current ListNode being checked in the search.

            // Starting at the head ListNode, search for the ListNode in the list with data equal to the target value.
            while (current != nullptr && current->data != target)
                current = current->next;
            
            // If the target value was not found in the linked list, return false.
            if (current == nullptr)
                return false;
            else
            {
                // If the target is the head ListNode, make the second ListNode in the list the new head ListNode and delete the old head ListNode.
                if (current == _head)
                {
                    _head = _head->next;
                    delete current;
                    _size--;

                    return true;
                }
                // If the target ListNode is the last ListNode, find the penultimate ListNode in the list
                else if (current->next == nullptr)
                {
                    ListNode* secondLast = _head;            // Second to last ListNode in the list.
                    
                    // Traverse the list to find the second to last ListNode
                    while (secondLast->next->next != nullptr)
                        secondLast = secondLast->next;
                    
                    delete (secondLast->next);
                    secondLast->next = nullptr;
                    _size--;

                    return true;
                }
                else
                {
                    ListNode* prevListNode = _head;                  // ListNode before the current ListNode.
                    ListNode* nextListNode = current->next;          // ListNode after the current ListNode.
                    
                    // Traverse the list to find the note before the current ListNode.
                    while (prevListNode->next != current)
                        prevListNode = prevListNode->next;
                    
                    delete current;
                    prevListNode->next = nextListNode;
                    _size--;

                    return true;
                }
            }
        }
    }

    // Print out all the ListNodes of the linked list.
    void printList()
    {
        ListNode* current = _head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Getter for the _size of the list.
    int getLength() { return _size; }
};

int main()
{
    SinglyLinkedList numList;
    (numList.insert(4)) ? printf("Insert %d successful.\n", 4) : printf("Insert %d failed.\n", 4);
    (numList.insert(4)) ? printf("Insert %d successful.\n", 4) : printf("Insert %d failed.\n", 4);
    (numList.insert(8)) ? printf("Insert %d successful.\n", 7) : printf("Insert %d failed.\n", 7);
    (numList.insert(7)) ? printf("Insert %d successful.\n", 8) : printf("Insert %d failed.\n", 8);
    (numList.insert(0)) ? printf("Insert %d successful.\n", 0) : printf("Insert %d failed.\n", 0);
    (numList.insert(1)) ? printf("Insert %d successful.\n", 1) : printf("Insert %d failed.\n", 1);
    (numList.remove(0)) ? printf("Remove %d successful.\n", 0) : printf("Remove %d failed.\n", 0);
    (numList.remove(2)) ? printf("Remove %d successful.\n", 2) : printf("Remove %d failed.\n", 2);
    (numList.remove(8)) ? printf("Remove %d successful.\n", 8) : printf("Remove %d failed.\n", 8);
    (numList.remove(4)) ? printf("Remove %d successful.\n", 4) : printf("Remove %d failed.\n", 4);
    (numList.insert(9)) ? printf("Insert %d successful.\n", 9) : printf("Insert %d failed.\n", 9);
    numList.printList();
    cout << "List length: " << numList.getLength() << endl;
    return 0;
}