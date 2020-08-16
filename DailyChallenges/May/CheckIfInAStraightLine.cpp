#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates);

int main()
{
    // vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    // vector<vector<int>> coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    vector<vector<int>> coordinates = {{0, 0}, {0, 1}, {0, -1}};
    cout << checkStraightLine(coordinates) << endl;
    return 0;
}

bool checkStraightLine(vector<vector<int>>& coordinates)
{
    if (coordinates.size() == 2)
    {
        return true;
    }
    
    int d1 = coordinates[1][0] - coordinates[0][0];
    int d2 = coordinates[1][1] - coordinates[0][1];

    for (int i = 2; i < coordinates.size(); i++)
    {
        int currD1 = coordinates[i][0] - coordinates[i - 1][0];;
        int currD2 = coordinates[i][1] - coordinates[i - 1][1];
        
        
        if (currD1 * d2 != currD2 * d1)
        {
            return false;
        }
    }
    return true;
}