// https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s);

int main()
{
    // vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    // vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> s = {};
    reverseString(s);
    for (char c : s)
    {
        cout << c << ' ';
    }
    cout << '\n';
    return 0;
}

void reverseString(vector<char>& s)
{
    int N = s.size();
    for (int i = 0; i < N/2; i++)
    {
        char temp = s[i];
        s[i] = s[N - 1 - i];
        s[N - 1 - i] = temp;
    }
}