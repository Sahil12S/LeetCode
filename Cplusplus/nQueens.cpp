// Given n Queens, find ways to place them in n x n chess board

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

vector< vector<int>> solveQueens(int n);
void helper(int n, int row, vector<int>& currPlacement, vector< vector<int>>& result);
bool isValid(vector<int> currPlacement);
void Print(vector< vector<int>> placements);

vector< vector<string>> solveQueens2(int n);
void helper2(int n, int row, vector<string>& currPlacement, vector< vector<string>>& result);
bool isValid2(vector<string> currPlacement);
void Print2(vector< vector<string>> placements);
int indexOfQ(string s);


int main(int argc, char const *argv[])
{
    
    // vector<vector<int>> placements = solveQueens(4);
    vector<vector<string>> placements = solveQueens2(4);
    // Print(placements);
    Print2(placements);

    return 0;
}

void Print(vector< vector<int>> placements)
{
    for (vector<int> sol : placements)
    {
        for (int pos : sol)
        {
            cout << pos << " ";
        }
        cout << endl;
    }
}

void Print2(vector< vector<string>> placements)
{
    for (vector<string> sol : placements)
    {
        for (string pos : sol)
        {
            cout << pos << endl;
        }
        cout << endl;
    }
}


vector< vector<int>> solveQueens(int n)
{
    vector< vector<int>> result;
    vector<int> currPlacement;

    vector< vector<string>> result2;
    // string
    vector<string> currPlacement2;
    helper(n, 0, currPlacement, result);
    return result;
}

vector< vector<string>> solveQueens2(int n)
{
    vector< vector<string>> result;
    vector<string> currPlacement;

    // vector< vector<string>> result2;
    // string
    // vector<string> currPlacement2;
    helper2(n, 0, currPlacement, result);
    return result;
}


void helper(int n, int row, vector<int>& currPlacement, vector< vector<int>>& result)
{
    if (row == n)
    {
        result.emplace_back(currPlacement);
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            currPlacement.emplace_back(col);
            if (isValid(currPlacement))
            {
                helper(n, row + 1, currPlacement, result);
            }
            currPlacement.pop_back();
        }
    }
}


bool isValid(vector<int> currPlacement)
{
    int row_id = currPlacement.size() - 1;

    for (int i = 0; i < row_id; i++)
    {
        int diff = abs(currPlacement[i] - currPlacement[row_id]);
        
        if (diff == 0 || diff == row_id - i)
        {
            return false;
        }
    }
    return true;
}

void helper2(int n, int row, vector<string>& currPlacement, vector< vector<string>>& result)
{
    if (row == n)
    {
        result.emplace_back(currPlacement);
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            string str(n, '.');
            str[col] = 'Q';
            currPlacement.push_back(str);
            
            if (isValid2(currPlacement))
            {
                helper2(n, row + 1, currPlacement, result);
            }
            currPlacement.pop_back();

        }
    }
    
}

bool isValid2(vector<string> currPlacement)
{
    int row_id = currPlacement.size() - 1;

    for (int i = 0; i < row_id; i++)
    {
        int index_i = indexOfQ(currPlacement[i]);
        int index_rid = indexOfQ(currPlacement[row_id]);
        int diff = abs(index_i - index_rid);
        
        if (diff == 0 || diff == row_id - i)
        {
            return false;
        }
    }
    return true;
}

int indexOfQ(string s)
{
    auto  found = s.find('Q');
    int index = -1;
    if (found != string::npos)
    {
        index = static_cast<int>(found);
    }
    return index;
}