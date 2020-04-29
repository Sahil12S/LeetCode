#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortTheMatrixDiagonally
{
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
	{
		int m = mat.size();
		int n = mat[0].size();

		vector<int> arrayToSort;
		vector<pair<int, int>> indicesInSortList;
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0, k = i; k < m && j < n; j++, k++)
			{
				arrayToSort.push_back(mat[k][j]);
				indicesInSortList.push_back({ k, j });
			}

			sort(arrayToSort.begin(), arrayToSort.end());

			for (int t = 0; t < arrayToSort.size(); t++)
			{
				int x = indicesInSortList[t].first;
				int y = indicesInSortList[t].second;
				mat[x][y] = arrayToSort[t];
			}
			arrayToSort.clear();
			indicesInSortList.clear();
		}

		for (int j = 1; j < n; j++)
		{
			for (int i = 0, k = j; i < m && k < n; i++, k++)
			{
				arrayToSort.push_back(mat[i][k]);
				indicesInSortList.push_back({ i, k });
			}
			sort(arrayToSort.begin(), arrayToSort.end());
			for (int t = 0; t < arrayToSort.size(); t++)
			{
				int x = indicesInSortList[t].first;
				int y = indicesInSortList[t].second;
				mat[x][y] = arrayToSort[t];
			}
			arrayToSort.clear();
			indicesInSortList.clear();
		}
		return mat;
	}

	void printVector(vector<int> vec)
	{
		for (int val : vec)
		{
			cout << val << " ";
		}
		cout << endl;
	}

	void RunSortTheMatrixDiagonally()
	{
		vector<vector<int>> mat = { {3,3,1,1}, {2,2,1,2}, {1,1,1,2} };
		for (vector<int> row : mat)
		{
			printVector(row);
		}
		cout << "Solution:" << endl;
		mat = diagonalSort(mat);
		for (vector<int> row : mat)
		{
			printVector(row);
		}
	}
};