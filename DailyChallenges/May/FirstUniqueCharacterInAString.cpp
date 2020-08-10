#include  <iostream>
#include <vector>

using namespace std;

int firstUniquChar(string s);

int main()
{
    string s = "a";
    cout << firstUniquChar(s) << endl;
    return 0;
}

int firstUniquChar(string s)
{
    vector<int> charCount(26, 0);

    for (char c : s)
    {
        charCount[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (charCount[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}
