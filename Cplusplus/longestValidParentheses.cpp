/**
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class Compare
{
public:
    bool operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) const
    {
        return p1.first > p2.first;
    }
};

int longestValidParentheses(std::string s);
int longestValidParentheses2(std::string s);
int longestValidParentheses3(std::string s);

int main()
{
    // std::string s = "(()";           // 2
    // std::string s = ")()())"; // 4
    // std::string s = "()(())(()"; // 6
    // std::string s = "(())))))))"; // 4
    std::string s = "()(()"; // 2
    // std::string s = "((("; // 0
    std::cout << longestValidParentheses3(s) << std::endl;
    return 0;
}

int longestValidParentheses(std::string s)
{
    if (s.size() <= 1)
    {
        return 0;
    }

    std::stack<std::pair<char, int>> stk;
    int max_length = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

    for (int i = 0; i < s.size(); i++)
    {
        if (stk.empty() && s[i] == ')')
        {
            continue;
        }
        if (s[i] == '(')
        {
            stk.push(std::make_pair(s[i], i));
        }
        else if (s[i] == ')')
        {
            std::pair<int, int> p = std::make_pair(stk.top().second, i);
            stk.pop();
            pq.push(p);
        }
    }

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        if (pq.top().first < p.second && pq.top().second < p.second)
        {
            pq.pop();
            pq.push(p);
            continue;
        }
        if (pq.top().first - p.second == 1)
        {
            p.second = pq.top().second;
            pq.pop();
            pq.push(p);
        }
        else
        {
            max_length = std::max(max_length, p.second - p.first + 1);
        }
    }

    return max_length;
}

int longestValidParentheses2(std::string s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    int maxlen = 0;
    std::stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                maxlen = std::max(maxlen, i - stk.top());
            }
        }
    }
    return maxlen;
}

int longestValidParentheses3(std::string s)
{
    int leftB = 0;
    int rightB = 0;

    int maxlen = 0;

    // Travel from left to right
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            leftB++;
        }
        else
        {
            rightB++;
        }

        if (leftB == rightB)
        {
            maxlen = std::max(2 * rightB, maxlen);
        }
        else if (rightB >= leftB)
        {
            leftB = rightB = 0;
        }
    }

    leftB = rightB = 0;
    // Travel from right to left
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            rightB++;
        }
        else
        {
            leftB++;
        }

        if (rightB == leftB)
        {
            maxlen = std::max(2 * leftB, maxlen);
        }
        else if (leftB >= rightB)
        {
            rightB = leftB = 0;
        }
    }
    return maxlen;
}