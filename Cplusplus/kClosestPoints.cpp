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
    map<double, vector< vector<int>>> distPoints;

    for (vector<int> point : points)
    {
        double dist = distance(point[0], point[1]);

        if (distPoints.count(dist) == 0)
        {
            distPoints[dist].push_back(point);
        }
    }

    vector< vector<int>> ans;
    
    auto it = distPoints.begin();

    for (;it != distPoints.end() && K > 0; it++)
    {
        for (vector<int> point : it->second)
        {
            K--;
            ans.push_back(point);
        }
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