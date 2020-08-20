#include <iostream>
#include <vector>

using namespace std;

void travelMatrix(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, vector<vector<bool>>& visited);
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

int main()
{
    // vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> image = {{0,0,0}, {0,1,1}};
    int sr = 1, sc = 1, newColor = 1;
    auto result = floodFill(image, sr, sc, newColor);

    for (auto row : result)
    {
        for (auto val : row)
        {
            cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void travelMatrix(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor)
{
    int numR = image.size();
    int numC = image[1].size();

    image[sr][sc] = newColor;
    if (sr - 1 >= 0 && image[sr - 1][sc] == oldColor)
    {
        travelMatrix(image, sr - 1, sc, oldColor, newColor);
    }
    if (sr + 1 < numR && image[sr + 1][sc] == oldColor)
    {
        travelMatrix(image, sr + 1, sc, oldColor, newColor);
    }
    if (sc - 1 >= 0 &&  image[sr][sc - 1] == oldColor)
    {
        travelMatrix(image, sr, sc - 1, oldColor, newColor);
    }
    if (sc + 1 < numC && image[sr][sc + 1] == oldColor)
    {
        travelMatrix(image, sr, sc + 1, oldColor, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int val = image[sr][sc];
    int numR = image.size();
    int numC = image[1].size();

    if (val != newColor)
    {
        travelMatrix(image, sr, sc, val, newColor);
    }

    return image;
}
