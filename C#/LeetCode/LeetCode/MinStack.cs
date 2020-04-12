using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class MinStack
    {
        Stack<int> valueStack;
        Stack<int> minValStack;
        public MinStack()
        {
            valueStack = new Stack<int>();
            minValStack = new Stack<int>();
        }

        public void Push(int x)
        {
            valueStack.Push(x);
            if (minValStack.Count == 0 || minValStack.Peek() >= x)
            {
                minValStack.Push(x);
            }
        }

        public void Pop()
        {
            int val = valueStack.Peek();
            valueStack.Pop();
            
            if (val == minValStack.Peek())
            {
                minValStack.Pop();
            }
        }

        public int Top()
        {
            return valueStack.Peek();
        }

        public int GetMin()
        {
            return minValStack.Peek();
        }
    }
}
