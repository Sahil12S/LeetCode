/**
 * Problem description:
 * https://leetcode.com/problems/the-skyline-problem/
 */

#include <iostream>
#include <vector>
#include <list>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VB = std::vector<bool>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;
using LVI = std::list<VI>;

VVI getSkyline(VVI &buildings);
LVI getSkyline(VVI &buildings, int low, int high);
LVI mergeSkylines(LVI &leftSkyline, LVI &rightSkyline);

int main()
{
    VVI buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    VVI ans = getSkyline(buildings);
    for (auto p : ans)
    {
        std::cout << p[0] << ", " << p[1] << '\n';
    }
    return 0;
}

VVI getSkyline(VVI &buildings)
{
    auto res = getSkyline(buildings, 0, buildings.size() - 1);
    VVI ans(res.begin(), res.end());
    return ans;
}

LVI getSkyline(VVI &buildings, int low, int high)
{
    LVI skyline;

    if (low < high)
    {
        int mid = low + (high - low) / 2;

        LVI leftSkyline = getSkyline(buildings, low, mid);
        LVI rightSkyline = getSkyline(buildings, mid + 1, high);

        return mergeSkylines(leftSkyline, rightSkyline);
    }
    else if (low == high)
    {
        int left_x = buildings[low][0];
        int right_x = buildings[low][1];
        int h = buildings[low][2];

        // Two key points will be Top-Left and Bottom-Right
        // we add them to the list
        skyline.push_back({left_x, h});
        skyline.push_back({right_x, 0});
    }

    return skyline;
}

LVI mergeSkylines(LVI &leftSkyline, LVI &rightSkyline)
{
    int h1 = 0; // latest height encountered for left skyline
    int h2 = 0; // latest height encountered for right skyline

    LVI merged;

    while (true)
    {
        // if any one vector is empty
        if (leftSkyline.empty() || rightSkyline.empty())
        {
            break;
        }

        VI point1 = leftSkyline.front();
        VI point2 = rightSkyline.front();

        // Store new x-coordinate and height
        VI newPoint(2);

        // When first skyline's x-coordinate is less than that of second skyline
        if (point1[0] < point2[0])
        {
            newPoint[0] = point1[0];
            newPoint[1] = point1[1];

            // Check if current height is less than
            // previously encountered height from other skyline
            if (point1[1] < h2)
            {
                newPoint[1] = h2;
            }

            // Update this skyline's height
            h1 = point1[1];

            leftSkyline.pop_front();
        }
        else if (point1[0] > point2[0])
        {
            // When first skyline's x-coordinate is greater than that of second skyline
            newPoint[0] = point2[0];
            newPoint[1] = point2[1];

            // Check if current height is less than
            // previously encountered height from other skyline
            if (point2[1] < h1)
            {
                newPoint[1] = h1;
            }

            // Update this skyline's height
            h2 = point2[1];

            rightSkyline.pop_front();
        }
        else
        {
            newPoint[0] = point1[0];
            newPoint[1] = std::max(point1[1], point2[1]);

            h1 = point1[1];
            h2 = point2[1];

            // Remove used elements
            leftSkyline.pop_front();
            rightSkyline.pop_front();
        }

        // Add newly found point
        merged.push_back(newPoint);
    }

    // Add remaining points
    if (leftSkyline.empty())
    {
        while (!rightSkyline.empty())
        {
            merged.push_back(rightSkyline.front());
            rightSkyline.pop_front();
        }
    }
    if (rightSkyline.empty())
    {
        while (!leftSkyline.empty())
        {
            merged.push_back(leftSkyline.front());
            leftSkyline.pop_front();
        }
    }

    // Remove redundant points

    int current = 0;
    auto it = merged.begin();
    int prev_y = (*it)[1];
    it++;

    // Remove any consecutive elements from same level
    // and only keep starting element of that level
    for (; it != merged.end(); it++)
    {
        while (!merged.empty() && (*it)[1] == prev_y)
        {
            it = merged.erase(it);
        }
        if (!merged.empty())
        {
            prev_y = (*it)[1];
        }
    }

    return merged;
}