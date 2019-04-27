/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > combinationSum2( vector<int>& candidates, int target );
void helper( vector<int>& candidates, int target, vector<int>& temp, vector< vector<int> >& result, int idx );

int main(int argc, char const *argv[])
{
    // vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
    // int target = 8;
    // vector<int> candidates = { 2,5,2,1,2,1 };
    // int target = 6;
    vector<int> candidates = {4,2,5,2,5,3,1,5,2,2};
    int target = 9;


    auto ans = combinationSum2( candidates, target );

    for ( auto vec : ans )
    {
        for ( int val : vec )
        {
            cout << val << " ";
        }
        cout << '\n';
    }
    return 0;
}

vector< vector<int> > combinationSum2( vector<int>& candidates, int target )
{
    sort( candidates.begin(), candidates.end() );

    vector<int> temp;
    vector< vector<int> > result;

    helper( candidates, target, temp, result, 0 );

    return result;
}


void helper( vector<int>& candidates, int target, vector<int>& temp, vector< vector<int> >& result, int idx )
{
    if ( target == 0 )
    {
        result.emplace_back( temp );
        return;
    }

    for (int i = idx; i < candidates.size(); i++ )
    {
        if ( candidates[i] > target )
        {
            return;
        }

        if ( i && candidates[i] == candidates[i - 1] && i > idx )
        {
            continue;
        }
        temp.emplace_back( candidates[i] );
        helper( candidates, target - candidates[i], temp, result, i + 1 );
        temp.pop_back();
    }
}