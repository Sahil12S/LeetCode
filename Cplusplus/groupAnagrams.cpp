// Given an array of strings, group anagrams together.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <lis

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main(int argc, char const *argv[])
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    for (vector<string> str : ans)
    {
        for (string s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> myMap;

    for (string s : strs)
    {
        string temp = s;
        sort(temp.begin(), temp.end());

        myMap[temp].emplace_back(s);
    }

    vector<vector<string>> ans;

    for (auto const& it : myMap)
    {
        ans.emplace_back(it.second);
    }
    return ans;
}