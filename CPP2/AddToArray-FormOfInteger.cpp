#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K);

int main()
{
    vector<int> A = {2, 1, 5};
    int K = 806;

    auto ans = addToArrayForm(A, K);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

vector<int> addToArrayForm(vector<int>& A, int K)
{
    reverse(A.begin(), A.end());
    int i = 0;
    A[0] += K;
    for (int i = 0; i < A.size(); i++)
    {
        int q = A[i] / 10;
        cout << "q: " << q << endl;
        A[i] %= 10;
        cout << "A: " << A[i] << endl;
        if (q > 0)
        {
            if (i == A.size() - 1)
            {
                A.push_back(q);
            }
            else
            {
                A[i + 1] += q;
            }
        }
    }
    reverse(A.begin(), A.end());
    return A;
}