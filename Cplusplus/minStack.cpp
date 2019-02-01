// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {}

    void push (int x) {
        s.push(x);
        if (minStack.empty() || x <= getMin()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (s.top() == getMin()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};