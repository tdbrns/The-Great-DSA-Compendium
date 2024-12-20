/*
Structure:          Optimized Queue using Stacks (LeetCode Problem #232)

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
                        inStack
                            • Stores the elements in the order in which they were pushed into the queue.
                        outStack
                            • Stores the elements of inStack, but in reverse; used to pop the element at the front of the queue and return
                              it.
                    In this approach, we push new elements into the back of the queue by pushing them onto the top of inStack, and we
                    return and/or pop the element at the front of the queue by popping each element from inStack, pushing it onto outStack,
                    and returning/popping the element at the top of outStack. This approach is more optimized because it removes the need to
                    recreate one of the stacks whenever an element is added or removed from the queue.
                    We use two integer vectors as stacks, so push_back(), pop_back(), size(), and empty() are the only std::vector 
                    functions that can be utilized. 

Method Analysis:    push()
                        • Time complexity:      O(1)
                        • Space complexity:     O(N); N = number of elements in the queue
                    pop()
                        • Time complexity:      O(N); N = number of elements in the queue
                        • Space complexity:     O(N); N = number of elements in the queue
                    peek()
                        • Time complexity:      O(N); N = number of elements in the queue
                                                      NOTE: worst-case occurs when inStack has N elements and outStack is empty
                        • Space complexity:     O(N); N = number of elements in the queue
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
    vector<int> _inStack;     // Stack storing the queue elements.
    vector<int> _outStack;    // Stack storing the queue elements in reverse.
public:
    MyQueue() { }

    // Push x into queue by pushing it into _inStack and storing the updated _inStack into _outStack in reverse.
    void push(int x) 
    {
        _inStack.push_back(x);
    }
    
    // Pop the front element from the queue by popping the top of _outStack and storing the updated _outStack into _inStack in reverse.
    int pop() 
    {
        int x = peek();
        _outStack.pop_back();
        return x;
    }
        
    // Get the front element of the queue by returning the top element of _outStack. If _outStack is empty, pop each element from 
    // _inStack and push it onto _outStack.
    int peek() 
    {
        if (_outStack.empty())
        {
            while (!_inStack.empty())
            {
                _outStack.push_back(_inStack.back());
                _inStack.pop_back();
            }
        }
        return _outStack.back();
    }
    
    // Determine if the queue is empty by determining if both _inStack and _outStack are empty.
    bool empty() 
    {
        if (_inStack.empty() && _outStack.empty())
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