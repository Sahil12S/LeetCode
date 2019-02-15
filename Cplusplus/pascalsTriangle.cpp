// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows);
void printTriangle(vector< vector<int>> triangle);

int main(int argc, char const *argv[])
{
    int numRows = 5;

    printTriangle(generate(numRows));
    
    return 0;
}

vector<vector<int>> generate(int numRows)
{
    vector< vector<int>> triangle(numRows);

    for (int i = 0; i < numRows; i++)
    {
        vector<int> rows(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                rows[j] = 1;
            }
            else
            {
                rows[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        triangle[i] = rows;
    }
    return triangle;
}

void printTriangle(vector< vector<int>> triangle)
{
    for (vector<int> rows : triangle)
    {
        for (int vals : rows)
        {
            cout << " " << vals;
        }
        cout << endl;
    }
}