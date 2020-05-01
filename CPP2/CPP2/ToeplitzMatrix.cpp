#include "ToeplitzMatrix.h"

bool ToeplitzMatrix::isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
{
	int M = matrix.size();
	int N = matrix[0].size();

	/*int dir = 1;

	int r = M - 1;
	int c = 0;
	int prev_val;
	int startR = r;
	int startC = c;

	while (r < M && c < N)
	{
		prev_val = matrix[r][c];
		int n_r = r + dir;
		int n_c = c + dir;

		if (n_r < M && n_c < N)
		{
			if (matrix[n_r][n_c] != prev_val)
			{
				return false;
			}
			r = n_r;
			c = n_c;
		}
		else
		{
			c = startC + (startR == 0 ? dir : 0);
			r = startR - (startR > 0 ? dir : 0);
			startR = r, startC = c;
		}
	}
	return true;*/

	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (r > 0 && c > 0 && matrix[r][c] != matrix[r - 1][c - 1])
			{
				return false;
			}
		}
	}
	return true;
}

void ToeplitzMatrix::runToeplitzMatrix()
{
	std::vector<std::vector<int>> matrix = { {1,2,3,4}, {5,1,2,3}, {9,5,1,2} };
	//std::vector<std::vector<int>> matrix = { {1,2}, {2,2} };
	//std::vector<std::vector<int>> matrix = { {0, 19, 54, 9}, { 47, 9, 19, 54 }, { 11, 47, 9, 19 }};
	std::cout << isToeplitzMatrix(matrix) << std::endl;
}