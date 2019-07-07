/**
 * We are given an array A of N lowercase letter strings, all of the same length.
 * 
 * Now, we may choose any set of deletion indices,
 * and for each string, we delete all the characters in those indices.
 * 
 * For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3},
 * then the final array after deletions is ["bef", *  "vyz"],
 * and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].
 * (Formally, the c-th column is [A[0][c], A[1][c], ...,  * A[A.length-1][c]].)
 * 
 * Suppose we chose a set of deletion indices D such that after deletions,
 * each remaining column in A is in non-decreasing sorted order.
 * 
 * Return the minimum possible value of D.length.
 */

#include <iostream>
#include <vector>
#include <set>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VS = std::vector<std::string>;

int minDeletionSize(VS &A);

int main()
{
    // VS A = {"cba", "daf", "ghi"};
    // VS A = {"zyx", "wvu", "tsr"};
    VS A = {"rrjk", "furt", "guzm"};
    std::cout << minDeletionSize(A) << '\n';
    return 0;
}

int minDeletionSize(VS &A)
{
    // std::set<int> removeIdx;
    int count = 0;
    FORI(0, A[0].size())
    {
        FORJ(1, A.size())
        {
            if (A[j - 1][i] > A[j][i])
            {
                // removeIdx.insert(j);
                count++;
                break;
            }
        }
    }
    // return static_cast<int>(removeIdx.size());
    return count;
}