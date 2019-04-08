/*
There is a vector of sorted integers from 1 to n. Starting from left to right,
remove the first number and every other number afterward until you reach the end of the vector.
Repeat the previous step again, but this time from right to left,
remove the right most number and every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Find the last number that remains starting with a vector of length n.
*/

#include <iostream>

using namespace std;

int lastRemaining( int n );

int main(int argc, char const *argv[])
{
    int n = 9; // ans: 6
    cout << lastRemaining( n ) << endl;

    return 0;
}

int lastRemaining( int n )
{    
    bool movingLeft = true;
    int start = 1;
    int step = 1;
    int remainingNum = n;

    while ( remainingNum > 1 )
    {
        if ( movingLeft || remainingNum % 2 == 1 )
        {
            start += step;
        }
        remainingNum /= 2;
        step *= 2;
        movingLeft = !movingLeft;
    }
    return start;

}