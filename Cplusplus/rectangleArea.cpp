/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner.
*/

#include <iostream>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
bool intersects( int A, int B, int C, int D, int E, int F, int G, int H );


int main(int argc, char const *argv[])
{
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    cout << computeArea( A, B, C, D, E, F, G, H ) << endl;

    return 0;
}


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = abs( C - A ) * abs( D - B );
    
    int area2 = abs( G - E ) * abs( H - F );
    
    int intersectionArea = 0;
    if ( intersects( A, B, C, D, E, F, G, H ) )
    {
        intersectionArea = abs( min( C, G ) - max( A, E ) ) * abs( min( D, H ) - max( B, F ) );
    }
    
    return area1 - intersectionArea + area2;
}

bool intersects( int A, int B, int C, int D, int E, int F, int G, int H )
{
    if ( A >= G || C <= E || B >= H || D <= F )
    {
        return false;
    }
    return true;
}