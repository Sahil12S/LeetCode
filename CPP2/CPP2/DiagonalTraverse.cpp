#include <iostream>

#include "DiagonalTraverse.h"

using namespace std;

vector<int> DiagonalTraverse::findDiagonalOrder(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0)
	{
		return vector<int>();
	}
	int n = matrix[0].size();

	if (n == 0)
	{
		return vector<int>();
	}

	vector<int> result = vector<int>(m*n);

	int direction = 1;
	int i = 0;
	int j = 0;
	int idx = 0;
	
	while (i < m && j < n)
	{
		result[idx++] = matrix[i][j];

		int n_row = i + (direction == 1 ? -1 : 1);
		int n_col = j + (direction == 1 ? 1 : -1);

		if (n_row < 0 || n_row >= m || n_col < 0 || n_col >= n)
		{
			if (direction == 1)
			{
				i += (j == n - 1 ? 1 : 0);
				j += (j < n - 1 ? 1 : 0);
			}
			else
			{
				j += (i == m - 1 ? 1 : 0);
				i += (i < m - 1 ? 1 : 0);
			}
			direction *= -1;
		}
		else
		{
			i = n_row;
			j = n_col;
		}
	}
	return result;
}

void DiagonalTraverse::RunDiagonalTraverse()
{
	vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6 }, { 7, 8, 9 } };
	vector<int> res = findDiagonalOrder(matrix);
	for (int val : res)
	{
		cout << val << " ";
	}
	cout << endl;
}