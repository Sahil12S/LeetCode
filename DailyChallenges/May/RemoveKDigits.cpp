#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string removeKDigits(string num, int k);

int main()
{
    string num = "10";
    int k = 1;

    cout << removeKDigits(num, k) << endl;

    return 0;
}

string removeKDigits(string num, int k)
{
    if (k >= num.size())
    {
        return "0";
    }

    stack<char> stk;;
    stk.push(num[0]);

    for (int i = 1; i < num.size(); i++)
    {
        if (stk.empty())
            stk.push(num[i]);
        else if (stk.top() < num[i])
            stk.push(num[i]);
        else
        {
            while (!stk.empty() && stk.top() > num[i] && k > 0)
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        
    }
    // Remove remaining digits
    while (k-- > 0 && !stk.empty())
        stk.pop();
    
    string res = "";
    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    // Since string is reversed, we remove any zeroes from end
    int i = res.size() - 1;
    while ( i >= 0 && res[i] == '0')
        i--;
    
    res = res.substr(0, i + 1);
    reverse(res.begin(), res.end());

    return res.size() > 0 ? res : "0";
}