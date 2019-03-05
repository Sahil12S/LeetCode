// Given a string S, we can transform every letter individually
// to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCasePermutation(string S);
void helper(string& S, int i, vector<string>& ans);

int main(int argc, char const *argv[])
{
    string S = "a1b2";
    vector<string> ans = letterCasePermutation(S);
    for (string a : ans)
    {
        cout << a << endl;
    }
    return 0;
}

vector<string> letterCasePermutation(string S)
{
    vector<string> ans;
    helper(S, 0, ans);
    return ans;
}

void helper(string& S, int i, vector<string>& ans)
{
    if (i == S.length())
    {
        ans.emplace_back(S);
        return;
    }

    helper(S, i + 1, ans);

    if (isalpha(S[i]))
    {
        S[i] ^= 32;
        helper(S, i + 1, ans);
    }
}