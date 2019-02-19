// A rectangle is represented as a list [x1, y1, x2, y2],
// where (x1, y1) are the coordinates of its bottom-left corner,
// and (x2, y2) are the coordinates of its top-right corner.

// Given two (axis-aligned) rectangles, return whether they overlap.

#include <iostream>
#include <vector>

using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2);

int main(int argc, char const *argv[])
{
    // vector<int> rec1 = {0,0,2,2};
    // vector<int> rec2 = {1,1,3,3};
    vector<int> rec1 = {0,0,1,1};
    vector<int> rec2 = {1,0,2,1};

    if (isRectangleOverlap(rec1, rec2))
    {
        cout << "Overlap" << endl;
    }
    else
    {
        cout << "Doesn't overlap" << endl;
    }
    

    return 0;
}

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
    return !(rec2[2] <= rec1[0] ||
            rec2[0] >= rec1[2] ||
            rec2[3] <= rec1[1] ||
            rec2[1] >= rec1[3]);
}