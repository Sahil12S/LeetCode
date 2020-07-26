#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeDuplicates(string S);

int main()
{
    string S = "abbaca";
    cout << removeDuplicates(S) << endl;
    return 0;
}

string removeDuplicates(string S)
{
    vector<char> vec;
    if (S.size() == 0)
    {
        return S;
    }
    vec.push_back(S[0]);

    for (int i = 1; i < S.size(); i++)
    {
        if (vec.back() != S[i])
        {
            vec.push_back(S[i]);
        }
        else
        {
            vec.pop_back();
        }
    }
    string S1 = "";
    for (char c : vec)
    {
        S1 += c;
    }
    return S1;
}
