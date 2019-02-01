// Implement queue using stack.

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> myStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tempStack;
        while (!myStack.empty()) {
            tempStack.push(myStack.top());
            myStack.pop();
        }
        myStack.push(x);
        while (!tempStack.empty()) {
            myStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = myStack.top();
        myStack.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        return myStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return myStack.empty();
    }
};


int main() {
    MyQueue obj;

    obj.push(4);
    obj.push(8);
    obj.push(3);
    obj.push(1);
    obj.push(6);
    cout << obj.peek() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
    
    return 0;
}