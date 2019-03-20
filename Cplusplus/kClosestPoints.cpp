// Find k Closest points to origin

#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector< vector<int>> kClosest(vector< vector<int>> points, int K);
double distance(int x, int y);
void print(vector< vector<int>> points);


int main()
{
    // vector< vector<int>> points = {{1, 3}, {-2, 2}};
    vector< vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int K = 2;

    print(kClosest(points, K));

    return 0;
}

vector< vector<int>> kClosest(vector< vector<int>> points, int K)
{
    map<double, int> distPoints;

    for (int i = 0; i < points.size(); i++)
    {
        double dist = distance(points[i][0], points[i][1]);

        if (distPoints.count(dist) == 0)
        {
            distPoints[dist] = i;
        }
    }

    vector< vector<int>> ans;
    
    auto it = distPoints.begin();

    for (;it != distPoints.end() && K > 0; it++)
    {
        K--;
        ans.push_back(points[it->second]);
    }
    return ans;
}

double distance(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y ,2));
}

void print(vector< vector<int>> points) {

    for (vector<int> point : points)
    {
        for (int coord : point)
        {
            cout << coord << ", ";
        }
        cout << endl;
    }
    // cout << endl;
}