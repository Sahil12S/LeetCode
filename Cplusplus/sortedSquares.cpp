// Given an array of integers A sorted in non-decreasing order,
// return an array of the squares of each number, also in sorted non-decreasing order.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& A);

int main(int argc, char const *argv[])
{
    // vector<int> A = {-4,-1,0,3,10};
    vector<int> A = {-7,-3,2,3,11};
    vector<int> ans = sortedSquares(A);

    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}

vector<int> sortedSquares(vector<int>& A)
{
    /*for (int i = 0; i < A.size(); i++)
    {
        A[i] *= A[i];
    }

    sort(A.begin(), A.end());

    return A;*/

    int N = A.size();
    int j = 0;
    
    while (j < N && A[j] < 0)
    {
        j++;
    }
    
    int i = j - 1;
    
    vector<int> ans(N);
    int t = 0;
    
    while (i >= 0 && j < N)
    {
        if (A[i] * A[i] < A[j] * A[j])
        {
            ans[t++] = A[i] * A[i];
            i--;
        }
        else
        {
            ans[t++] = A[j] * A[j];
            j++;
        }
    }
    
    while  (i >= 0)
    {
        ans[t++] = A[i] * A[i];
        i--;
    }
    while (j < N)
    {
        ans[t++] = A[j] * A[j];
        j++;
    }
    
    return ans;
}