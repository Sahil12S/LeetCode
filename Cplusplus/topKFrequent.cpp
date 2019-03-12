// Given a non-empty array of integers, return the k most frequent elements.

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int n : ans) {
        cout << n << endl;
    }
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    map<int, int> numFreq;

    for (int n : nums) {
        numFreq[n]++;
    }

    priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> topK;

    auto it = numFreq.begin();

    while (it != numFreq.end()) {
        topK.push(make_pair (it->first, it->second));

        if (topK.size() > k) {
            topK.pop();
        }
        // cout << it->first << ": " << it->second << endl;
        it++;
    }

    vector<int> ans(k);

    int i = 0;

    while (!topK.empty()) {
        ans[i] = topK.top().first;
        topK.pop();
        i++;
    }

    return ans;
}