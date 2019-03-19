// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
// The integer division should truncate toward zero.

#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

int calculate(string s);

int main(int argc, char const *argv[])
{
    string s = " 3+2-2+ 3 ";
    // string s = "3+2/2*2";
    // string s = " 3+5 / 2 ";
    // string s = "3+2*2";
    // string s = "42";
    
    cout << calculate(s) << endl;
    return 0;
}

int calculate(string s)
{
    stack<int> nums;
    char sign = '+';
    int temp = 0;
    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            temp = temp*10 + (s[i] - '0');
        }

        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.length() - 1)
        {
            if (sign == '-')
            {
                nums.push(-temp);
            }
            else if (sign == '+')
            {
                nums.push(temp);
            }
            else
            {
                if (sign == '*')
                {
                    nums.top() *= temp;
                }
                else
                {
                    nums.top() /= temp;
                }
            }
            sign = s[i];
            temp = 0;
        }
    }

    while (!nums.empty())
    {
        res += nums.top();
        nums.pop();
    }
    return res;
}