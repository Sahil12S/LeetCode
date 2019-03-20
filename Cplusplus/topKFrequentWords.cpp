// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest.
// If two words have the same frequency, then the word with the lower alphabetical order comes first.

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int, string> a, pair<int, string> b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};


vector<string> topKFrequent(vector<string>& words, int k);

int main(int argc, char const *argv[])
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    // vector<string> words = {"the", "day", "is", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    // int k = 4;
    vector<string> ans = topKFrequent(words, k);
    for (string w : ans)
    {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}

vector<string> topKFrequent(vector<string>& words, int k)
{
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
    unordered_map<string, int> myMap;

    for (string word : words)
    {
        myMap[word]++;
    }

    auto it = myMap.begin();

    while (it != myMap.end())
    {
        pq.push(make_pair(it->second, it->first));
        // cout << pq.top().first << " " << pq.top().second << endl;    
        if (pq.size() > k)
        {
            pq.pop();
        }
        it++;
    }

    vector<string> ans;
    while (!pq.empty())
    {
        ans.emplace_back(pq.top().second);
        // cout << ans.back() << endl;
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}