#include <iostream>
#include <vector>

using namespace std;

int numJewelsInStones(string J, string S);

int main()
{
    string J = "c";
    string S = "aAAbbbb";
    cout << numJewelsInStones(J, S) << '\n';
    return 0;
}

int numJewelsInStones(string J, string S)
{
    vector<char> letters(256, 0);
    int count = 0;
    for (char c : S)
    {
        letters[c]++;
    }
    for (char c : J)
    {
        count += letters[c];
    }
    return count;
}