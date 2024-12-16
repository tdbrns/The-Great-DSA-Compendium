/*
Structure:          Queue using Stacks (LeetCode Problem #232)

Task:               Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the 
                    functions of a normal queue (push, peek, pop, and empty).
                    Implement the MyQueue class:
                        • void push(int x): Pushes element x to the back of the queue.
                        • int pop(): Removes the element from the front of the queue and returns it.
                        • int peek(): Returns the element from the front of the queue.
                        • boolean empty(): Returns true if the queue is empty, false otherwise.
                    NOTE:
                        • You must use only standard operations of a stack, which means only "push to top", "peek/pop from top", "size", and
                          "is empty" operations are valid.
                    
Solution:           Create a queue by storing its elements into two separate stacks:
                        _stack
                            • Stores the elements in the order in which they were pushed into the queue.
                            • Front of queue = Bottom of stack; Back of queue = Top of stack
                        _revStack
                            • Stores the elements of _stack, but in reverse; used to pop the element at the front of the queue and return
                              it.
                            • Front of queue = Top of stack; Back of queue = Bottom of stack
                    In this approach, we recreate _revStack whenever a new element is pushed into the back of the queue, and we recreate 
                    _stack whenever an element is popped from the front of the queue element is popped the queue. Since we use two integer 
                    vectors as stacks, push_back(), pop_back(), size(), and empty() are the only std::vector functions that can be utilized.

Method Analysis:    push()
                        • Time complexity:      O(N); N = number of elements in the queue
                        • Space complexity:     O(N); N = number of elements in the queue
                    pop()
                        • Time complexity:      O(N); N = number of elements in the queue
                        • Space complexity:     O(N); N = number of elements in the queue
                    peek()
                        • Time complexity:      O(1)
                        • Space complexity:     O(1)
                    empty()
                        • Time complexity:      O(1)
                        • Space complexity:     O(1)

Resources:          https://leetcode.com/problems/implement-queue-using-stacks/solutions/
*/


#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class MyQueue {
private:
    vector<int> _stack;     // Stack storing the queue elements.
    vector<int> _revStack;  // Stack storing the queue elements in reverse.
public:
    MyQueue() { }
    
    // Push x into queue by pushing it into _stack and storing the updated _stack into _revStack in reverse.
    void push(int x) 
    {
        _stack.push_back(x);
        _revStack.clear();
        
        for (int i = _stack.size() - 1; i >= 0; i--)
            _revStack.push_back(_stack[i]);
    }
    
    // Pop the front element from the queue by popping the top of _revStack and storing the updated _revStack into _stack in reverse.
    int pop() 
    {
        int x = peek();
        _revStack.pop_back();
        _stack.clear();

        for (int i = _revStack.size() - 1; i >= 0; i--)
            _stack.push_back(_revStack[i]);

        return x;
    }
    
    // Get the front element of the queue by returning the top element of _revStack.
    int peek() 
    {
        return _revStack.back();
    }
    
    // Determine if the queue is empty by determining if both _stack and _revStack are empty.
    bool empty() 
    {
        if (_stack.empty() && _revStack.empty())
            return true;
        return false;
    }
};

int main()
{
    // Test case 1
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    (obj->empty()) ? cout << "The queue is empty\n" : cout << "The queue is not empty\n";

    return 0;
}