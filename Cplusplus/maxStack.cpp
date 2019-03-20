// Design a max stack that supports push, pop, top, peekMax and popMax.

#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
private:
    stack<int> s;
    stack<int> maxStack;

public:
    MaxStack() {}

    void push(int x) {
        s.push(x);
        if (maxStack.empty() || x >= peekMax()) {
            maxStack.push(x);
        }
    }

    int pop() {
        int val = s.top();
        s.pop();

        if (val == peekMax()) {
            maxStack.pop();
        }

        return val;
    }

    int top() {
        return s.top();
    }

    int peekMax() {
        return maxStack.top();
    }

    int popMax() {
        int max = maxStack.top();
        maxStack.pop();

        stack<int> tempStack;

        while (s.top() != max) {
            tempStack.push(s.top());
            s.pop();
        }
        s.pop();
        
        while (!tempStack.empty()) {
            s.push(tempStack.top());
            if (maxStack.empty() || tempStack.top() >= peekMax()) {
                maxStack.push(tempStack.top());
            }
            tempStack.pop();
        }
        return max;
    }
};

void testCase1 (MaxStack stack);
void testCase2 (MaxStack stack);

int main(int argc, char const *argv[])
{
    MaxStack stack;
    testCase2(stack);

    return 0;
}

void testCase1 (MaxStack stack) {
    stack.push(5);
    stack.push(1);
    stack.push(5);
    cout << stack.top() << endl;
    cout << stack.popMax() << endl;
    cout << stack.top() << endl;
    cout << stack.peekMax() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
}

void testCase2 (MaxStack stack) {
    stack.push(5);
    stack.push(1);
    stack.push(-5);
    cout << stack.popMax() << endl;
    cout << stack.popMax() << endl;
    cout << stack.top() << endl;

}