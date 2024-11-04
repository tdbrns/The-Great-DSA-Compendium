/*
Structure:          Doubly Linked List 

Task:               Create a linked list that sorts integers in ascending order without duplicate values.

Solution:           Use a doubly linked list class that can be used to store any given integers in ascneding order. Integers are
                    entered into the linked list as ListNodes, which are structs that can hold a data value, a pointer to the next
                    ListNode in the list, and a pointer to the previous ListNode in the list. This data structure utilizes operations for 
                    inserting ListNodes into the list, removing ListNodes from the list, printing out the data values of the list, and
                    returning the number of values the list holds all while keeping the data values sorted in ascending order.
                    
Resources:          https://www.geeksforgeeks.org/doubly-linked-list/
*/

#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
    int data;               // Integer value of a ListNode.
    ListNode* next;         // Pointer to next ListNode in a linked list.
    ListNode* previous;     // Pointer to previous ListNode in a linked list.

    // Constructor for ListNode struct.
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class DoublyLinkedList
{
private:
    ListNode* _head;
    ListNode* _tail;
    int _size;

public:
    // Construtor for DoublyLinkedList class.
    DoublyLinkedList()
    {
        _head = _tail = nullptr;
        _size = 0;
    }
    // Destructor for DoublyLinkedList class.
    ~DoublyLinkedList()
    {
        clearList();
    }

    // Consecutively delete all ListNodes from the list beginning at the head ListNode.
    void clearList()
    {
        ListNode* current = _head;

        while (current != nullptr)
        {
            _head = _head->next;
            delete current;
            current = _head;
        }
        _size = 0;
    }

    bool insert(int newData)
    {
        if (!_head)
        {
            ListNode* newListNode = new ListNode(newData);
            _head = newListNode;
            _tail = newListNode;
            _size++;

            return true;
        }
        else
        {
            ListNode* current = _head;          // Pointer to the current ListNode being checked in the search.

            // Starting at the head ListNode, search for the ListNode in the list with a value that is grater than/equal to the new data.
            while(current != nullptr && newData > current->data)
                current = current->next;

            // Reject values that already exist in the list.
            if (current != nullptr && newData == current->data)
                return false;
            
            if (current == _head)
            {
                ListNode* newListNode = new ListNode(newData);      // ListNode with new data to be inserted.

                // Insert the new ListNode.
                _head->previous = newListNode;
                newListNode->next = _head;
                _head = newListNode;
                _size++;

                return true;
            }
            else if (current == nullptr)
            {
                ListNode* newListNode = new ListNode(newData);

                _tail->next = newListNode;
                newListNode->previous = _tail;
                _tail = newListNode;
                _size++;

                return true;
            }
            else
            {
                ListNode* newListNode = new ListNode(newData);
                ListNode* prevNode = current->previous;

                prevNode->next = newListNode;
                newListNode->previous = prevNode;
                current->previous = newListNode;
                newListNode->next = current;
                _size++;

                return true;
            }
        }
    }

    bool remove(int target)
    {
        if (!_head)
            return false;
        else
        {
            ListNode* current = _head;

            while (current != nullptr && current->data != target)
                current = current->next;
            
            if (current == nullptr)
                return false;
            else
            {
                if (current == _head)
                {
                    _head = _head->next;
                    delete current;
                    _head->previous = nullptr;
                    _size--;

                    return true;
                }
                else if (current->next == nullptr)
                {
                    _tail = _tail->previous;
                    delete current;
                    _tail->next = nullptr;
                    _size--;

                    return true;
                }
                else
                {
                    ListNode* prevNode = current->previous;
                    ListNode* nextNode = current->next;
                    
                    delete current;
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    _size--;

                    return true;
                }
            }
        }
    }

    bool search()
    {
        
    }

    void printListForward()
    {
        ListNode* current = _head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printListReverse()
    {
        ListNode* current = _tail;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->previous;
        }
        cout << endl;
    }

    int getLength() { return _size; }
};

int main()
{
    DoublyLinkedList numList;
    (numList.insert(4)) ? printf("Insert 4 successful.\n") : printf("Insert 4 failed.\n");
    (numList.insert(4)) ? printf("Insert 4 successful.\n") : printf("Insert 4 failed.\n");
    (numList.insert(8)) ? printf("Insert 7 successful.\n") : printf("Insert 7 failed.\n");
    (numList.insert(7)) ? printf("Insert 8 successful.\n") : printf("Insert 8 failed.\n");
    (numList.insert(0)) ? printf("Insert 0 successful.\n") : printf("Insert 0 failed.\n");
    (numList.insert(1)) ? printf("Insert 1 successful.\n") : printf("Insert 1 failed.\n");
    
    (numList.remove(0)) ? printf("Remove 0 successful.\n") : printf("Remove 0 failed.\n");
    (numList.remove(2)) ? printf("Remove 2 successful.\n") : printf("Remove 2 failed.\n");
    (numList.remove(8)) ? printf("Remove 8 successful.\n") : printf("Remove 8 failed.\n");
    (numList.remove(4)) ? printf("Remove 4 successful.\n") : printf("Remove 4 failed.\n");

    (numList.insert(9)) ? printf("Insert 9 successful.\n") : printf("Insert 9 failed.\n");
    (numList.insert(5)) ? printf("Insert 5 successful.\n") : printf("Insert 5 failed.\n");

    numList.printListForward();
    numList.printListReverse();
    cout << "List length: " << numList.getLength() << endl;

    return 0;
}