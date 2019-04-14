/*
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot,
and two sightseeing spots i and j have distance j - i between them.
The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : 
the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


using namespace std;

int maxScoreSigthseeingPair( vector<int>& A );
void printVector( vector<int> vec );
#include "../../logger.cpp"
int main(int argc, char const *argv[])
{
    // vector<int> A = {8,1,5,2,6};
    // vector<int> A = {1,2};
    vector<int> A = {3,7,2,3};
    cout << maxScoreSigthseeingPair( A ) << endl;
    return 0;
}

int maxScoreSigthseeingPair( vector<int>& A )
{
    int maxScore = numeric_limits<int>::min();

    vector<int> arrI( A.size() );
    vector<int> arrJ( A.size() );
    vector<int> maxVal( A.size(), numeric_limits<int>::min() );

    for ( int i = 0, j = A.size() - 1; i < A.size(); i++, j-- )
    {
        arrI[i] = A[i] + i;
        arrJ[j] = A[j] - j;

        if ( j == A.size() - 1 )
        {
            maxVal[j] = arrJ[j];
        }
        else
        {
            maxVal[j] = max( arrJ[j], maxVal[j + 1] );
            
        }
    }

    for ( int i = 0; i < A.size() - 1; i++ )
    {
        maxScore = max( arrI[i] + maxVal[i + 1], maxScore );
    }
    
    return maxScore;

}
