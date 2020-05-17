// https://leetcode.com/problems/letter-case-permutation/
#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCasePermutation(string S);
void helper(vector<string>& ans, int idx, string S);

int main()
{
    string S = "a1b2";  // ["a1b2", "a1B2", "A1b2", "A1B2"]
    vector<string> res = letterCasePermutation(S);

    for  (string word : res)
    {
        cout << word << " ";
    }
    cout << "\n";

}

vector<string> letterCasePermutation(string S)
{
    vector<string> ans;
    int startIdx = 0;
    helper(ans, startIdx, S);
    return ans;
}

void helper(vector<string>& ans, int idx, string S)
{
    ans.push_back(S);

    for (int i = idx; i < S.size(); i++)
    {
        if (isalpha(S[i]))
        {
            S[i] ^= 32;
            cout << S[i] << endl;
            helper(ans, i + 1, S);
            S[i] ^= 32;
        }
    }
}
// abc -> abc, abC, aBc, aBC