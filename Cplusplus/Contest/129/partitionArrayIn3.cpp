/*
    Given an array A of integers, return true if and only if 
    we can partition the array into three non-empty parts with equal sums.
    Formally, we can partition the array if we can find indexes i+1 < j 
    with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool canThreePartsEqualSum( vector<int>& A );

int main(int argc, char const *argv[])
{
    // vector<int> A = {0,2,1,-6,6,-7,9,1,2,0,1};       // True
    // vector<int> A = {0,2,1,-6,6,7,9,-1,2,0,1};       // False
    // vector<int> A = {3,3,6,5,-2,2,5,1,-9,4};         // True
    // vector<int> A = {0,0,0,0,0,0};                   // True
    // vector<int> A = {-1,-1,2,-1,-1,2,2,-1,-1};       // True
    vector<int> A = {18,12,-18,18,-19,-1,10,10};       // True
    
    cout << canThreePartsEqualSum( A ) << endl;
    return 0;
}

bool canThreePartsEqualSum( vector<int>& A )
{
    //  Minimum 3 elements are required
    if ( A.size() <= 2 )
    {
        return false;
    }

    long sum = 0;
    for ( int a : A )
    {
        sum += a;
    }
    sum /= 3;
    cout << "S: " << sum << endl;

    int l = 0, r = A.size() - 1;
    // int sumL = numeric_limits<int>::min(), sumR = numeric_limits<int>::min();
    int sumL = 0, sumR = 0;

    do
    {
        sumL += A[l];
        l++;
    } while ( l < r && sumL != sum );

    cout << "L: " << l << ", " << sumL << endl;

    do
    {
        sumR += A[r];
        r--;
    } while ( l < r && sumR != sum );

    cout << "R: " << r << ", " << sumR << endl;

    if ( sumL != sum || sumR != sum )
    {
        return false;
    }

    for ( int m = l; m <= r; m++ )
    {
        sum -= A[m];
    }

    if ( sum == 0 )
    {
        return true;
    }
    return false;
}