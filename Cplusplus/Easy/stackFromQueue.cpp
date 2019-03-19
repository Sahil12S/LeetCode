// Implement stack from queue.

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

};

int main() {
    MyStack stack;
    stack.push(2);
    stack.push(6);
    cout << stack.pop() << endl;
    stack.push(10);
    cout << stack.top() << endl;
    stack.push(4);
    stack.push(9);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
}