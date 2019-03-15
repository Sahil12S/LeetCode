// Given two lists Aand B, and B is an anagram of A.
// B is an anagram of A means B is made by randomizing the order of the elements in A.
// We want to find an index mapping P, from A to B.
// A mapping P[i] = j means the ith element in A appears in B at index j.
// These lists A and B may contain duplicates.
// If there are multiple answers, output any of them.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> anagramMapping(vector<int>& A, vector<int>& B);

int main(int argc, char const *argv[])
{
    vector<int> A = {12, 28, 46, 32, 50};
    vector<int> B = {50, 12, 32, 46, 28};
    vector<int> ans = anagramMapping(A, B);
    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

vector<int> anagramMapping(vector<int>& A, vector<int>& B)
{
    unordered_map<int, int> myMap;

    for (int i = 0; i < B.size(); i++)
    {
        myMap[B[i]] = i;
    }

    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        ans.emplace_back(myMap[A[i]]);
    }
    return ans;
}