/**
 * We are given that the string "abc" is valid.

 * From any valid string V, we may split V into two pieces X and Y
 * such that X + Y (X concatenated with Y) is equal to V.  (X or Y may be empty.)
 * Then, X + "abc" + Y is also valid.
 *
 * If for example S = "abc",
 * then examples of valid strings are: "abc", "aabcbc", "abcabc", "abcabcababcc".
 * Examples of invalid strings are: "abccba", "ab", "cababc", "bac".
 *
 * Return true if and only if the given string S is valid.
*/

#include <iostream>
#include <vector>
#include <stack>

bool isValid(std::string S);

int main()
{
    // std::string S = "abcabcababcc";
    // std::string S = "aabcbc";
    // std::string S = "abccba";
    std::string S = "cababc";
    std::cout << isValid(S) << '\n';
    return 0;
}

bool isValid(std::string S)
{
    // std::vector<char> counts;
    std::stack<char> stk;

    for (auto c : S)
    {
        if (c == 'c')
        {
            int n = stk.size();
            // if (n < 2 || counts[n - 1] != 'b' || counts[n - 2] != 'a')
            if (n < 2)
            {
                return false;
            }
            char b = stk.top();
            stk.pop();
            char a = stk.top();
            stk.pop();

            if (b != 'b' || a != 'a')
            {
                return false;
            }
            // counts.pop_back();
            // counts.pop_back();
        }
        else
        {
            // counts.push_back(c);
            stk.push(c);
        }
    }
    // return counts.size() == 0;
    return stk.size() == 0;

    /**
    bool isModified = true;

    while (S.size() > 0 && isModified)
    {
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'a' && i + 2 < S.size())
            {
                if (S[i + 1] == 'b' && S[i + 2] == 'c')
                {
                    S = S.substr(0, i) + S.substr(i + 3);
                    std::cout << S << std::endl;
                    isModified = true;
                    break;
                }
            }
            else
            {
                isModified = false;
            }
        }
    }
    return S.size() == 0;
*/
}