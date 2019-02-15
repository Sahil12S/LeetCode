// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow (int rowIndex);
vector<int> getRow2 (int rowIndex);
void printTriangle (vector<int> row);

int main(int argc, char const *argv[])
{
    int rowIndex = 5;

    printTriangle(getRow2(rowIndex));
    
    return 0;
}

vector<int> getRow(int rowIndex)
{
    vector< vector<int>> triangle(rowIndex);

    for (int i = 0; i < rowIndex; i++)
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
    return triangle[rowIndex - 1];
}

vector<int> getRow2 (int rowIndex)
{
    vector<int> row(rowIndex + 1, 0);

    if (rowIndex + 1 > 0)
    {
        row[0] = 1;
    }
    int prevNum1 = 1, prevNum2 = 1;

    for (int i = 1; i < rowIndex + 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                row[j] = 1;
            }
            else
            {
                //prevNum1 = row[j > 0 ? (j - 1) : 0];
                prevNum2 = row[i > 1 ? j : 0];
                row[j] = prevNum1 + prevNum2;
            }

        prevNum1 = prevNum2;
        }
    }
    return row;
}

void printTriangle(vector<int> row)
{
    for (int vals : row)
    {
        cout << " " << vals;
    }
    cout << endl;
}