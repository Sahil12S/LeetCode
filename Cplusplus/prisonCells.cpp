#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> prisonAfterNDays( vector<int>& cells, int N );
void changeCell( vector<int>& cells );
void printCell( vector<int>& cells );

int main(int argc, char const *argv[])
{
    
    return 0;
}


void changeCell( vector<int>& cells )
{
    int prev = cells[0];
    cells[0] = 0;
    for ( int i = 1; i < cells.size() - 1; i++ )
    {
        int temp = cells[i];
        cells[i] = ( prev == cells[i + 1] );
        prev = temp;
    }
    cells[cells.size() - 1] = 0;
}

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    
    map<int, vector<int>> myMap;
    
    for ( int i = 1; i <=14; i++ )
    {
        changeCell( cells );
        myMap[i] = cells;
    }
    int idx = N % 14 == 0 ? 14 : N % 14;
    return myMap[ idx ];
}

void printCell( vector<int>& cells )
{
    for ( int c : cells )
    {
        cout << c << " ";
    }
    cout << endl;
}