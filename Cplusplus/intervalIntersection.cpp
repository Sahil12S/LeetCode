/**
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
 * Return the intersection of these two interval lists.
 * 
 * Input:   A = [[0,2],[5,10],[13,23],[24,25]],
 *          B = [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> intervalIntersection(
    std::vector<std::vector<int>> &A,
    std::vector<std::vector<int>> &B);

int main()
{
    std::vector<std::vector<int>> A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    std::vector<std::vector<int>> B = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    std::vector<std::vector<int>> res = intervalIntersection(A, B);

    for (auto vec : res)
    {
        std::cout << vec[0] << " " << vec[1] << '\n';
    }

    return 0;
}

std::vector<std::vector<int>> intervalIntersection(
    std::vector<std::vector<int>> &A,
    std::vector<std::vector<int>> &B)
{
    std::vector<std::vector<int>> res;

    if (A.size() == 0 || B.size() == 0)
    {
        return res;
    }

    int i = 0;
    int j = 0;

    while (i < A.size() && j < B.size())
    {
        // Check for starting index & ending index
        int l = std::max(A[i][0], B[j][0]);
        int r = std::min(A[i][1], B[j][1]);

        // Check if one list's starting val is greater than second list's ending index
        if (l <= r)
        {
            res.emplace_back(std::vector<int>{l, r});
        }

        // Increase one that is smaller
        if (A[i][1] > B[j][1])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return res;
}