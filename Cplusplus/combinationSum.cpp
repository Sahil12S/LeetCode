// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& temp, int idx);

int main(int argc, char const *argv[])
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector< vector<int>> result = combinationSum(candidates, target);

    for (vector<int> nums : result)
    {
        for(int n : nums)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    vector< vector<int>> result;
    vector<int> temp;

    helper(candidates, target, result, temp, 0);
    return result;
}

void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& temp, int idx)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        result.push_back(temp);
        return;
    }

    while (idx < candidates.size() && candidates[idx] <= target)
    {
        temp.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], result, temp, idx);
        idx++;

        temp.pop_back();
    }

}