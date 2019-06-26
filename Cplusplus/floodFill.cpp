/**
 * An image is represented by a 2-D array of integers,
 * each integer representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
 * and a pixel value newColor, "flood fill" the image.

 * To perform a "flood fill", consider the starting pixel,
 * plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
 * plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel),
 * and so on. Replace the color of all of the aforementioned pixels with the newColor.
 *
 * At the end, return the modified image.
 */

#include <iostream>
#include <vector>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VVI floodFill(VVI &image, int sr, int sc, int newColor);

int main()
{
    VVI image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    auto ans = floodFill(image, sr, sc, newColor);
    for (auto vec : ans)
    {
        for (int val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
    return 0;
}

VVI floodFill(VVI &image, int sr, int sc, int newColor)
{
    if (image.empty())
    {
        return image;
    }

    int rows = image.size();
    int cols = image[0].size();

    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});

    int startPixel = image[sr][sc];
    image[sr][sc] = newColor;

    VVI dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        std::pair<int, int> point = q.front();
        q.pop();

        FORI(0, 4)
        {
            int nr = point.first + dirs[i][0];
            int nc = point.second + dirs[i][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == startPixel && image[nr][nc] != newColor)
            {
                q.push({nr, nc});
                image[nr][nc] = newColor;
            }
        }
    }
    return image;
}