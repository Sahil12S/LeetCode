// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1,
// then the ith and jth students are direct friends with each other, otherwise not.
// And you have to output the total number of friend circles among all the students

#include <iostream>
#include <vector>

using namespace std;
/*
class DS
{
private:
    int* parent;
    int* rank;
    int n;
    int distinctCount;
    
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    void print()
    {
        cout  << "Printing rank: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;

        cout << "Printing parent: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        
    }

public:
    DS(int n)
    {
        this->n = n;
        this->distinctCount = n;
        parent = new int[this->n];
        rank = new int[this->n];
        makeSet();
    }
    ~DS()
    {
        delete[] parent;
        delete[] rank;
    }

    int find(int X)
    {
        if (X < 0 || X >= n)
        {
            return -1;
        }

        if (parent[X] == -1)
        {
            return X;
        }
        
            // parent[X] = find(parent[X]);
        return find(parent[X]);
    }

    void doUnion(int X, int Y)
    {
        int rootX = find(X), rootY = find(Y);

        if (find(X) == find(Y) && rootX != -1)
        {
            return;
        }

        if (rank[X] < rank[Y])
        {
            cout << "X < Y" << endl;
            parent[X] = Y;
            rank[Y] += rank[X];
            this->distinctCount--;
            print();
            cout << "Distinct count: " << this->distinctCount << endl;
        }
        else
        {
            cout << "X >= Y" << endl;
            parent[Y] = X;
            rank[X] += rank[Y];
            this->distinctCount--;  
            print();
            cout << "Distinct count: " << this->distinctCount << endl;
        }
    }

    int getDistinctCount()
    {
        return this->distinctCount;
    }

};
*/

int findCircleNum(vector< vector<int>>& M);
void dfsHelper(vector< vector<int>>& M, int i, vector<bool>& visited);


int main(int argc, char const *argv[])
{
    vector< vector<int>> M = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    // vector< vector<int>> M = {
    //     {1, 1, 0},
    //     {1, 1, 1},
    //     {0, 1, 1}
    // };

    cout << findCircleNum(M) << endl;
    
    return 0;
}

int findCircleNum(vector< vector<int>>& M)
{
/*    int n = M.size();

    DS sets(n);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (M[r][c] == 1)
            {
                cout << "Sending: " << r << ", " << c << endl;
                sets.doUnion(r, c);
                M[r][c] = 0, M[c][r] = 0;
            }
        }
    }

    return sets.getDistinctCount();
*/

    int n = M.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsHelper(M, i, visited);
            count++;
        }
    }
    return count;
}

void dfsHelper(vector< vector<int>>& M, int i, vector<bool>& visited)
{
    for (int j = 0; j < M.size(); j++)
    {
        if (M[i][j] == 1 && !visited[j])
        {
            visited[j] = true;
            dfsHelper(M, j, visited);
        }
    }
}