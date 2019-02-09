// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height);

int main(int argc, char const *argv[])
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}

int maxArea(vector<int>& height) {
    int left = 0,  right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        maxArea = (area > maxArea) ? area : maxArea;

        height[left] < height[right] ? left++ : right--;
    }

    return maxArea;
}