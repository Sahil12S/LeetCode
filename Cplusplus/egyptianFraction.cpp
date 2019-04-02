/*
Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.

Following are few examples:
    Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
    Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
    Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void findEgyptianFraction( pair<int, int>& fraction, vector< pair<int, int>>& result );

int main(int argc, char const *argv[])
{
    pair<int, int> fraction = { 6, 14 };
    vector< pair<int, int>> result;
    findEgyptianFraction( fraction, result );

    for ( auto p : result )
    {
        cout << p.first << "/" << p.second << endl;
    }
    return 0;
}

void findEgyptianFraction( pair<int, int>& fraction, vector< pair<int, int>>& result )
{
    // Return when either numerator or denominator is 0.
    if ( fraction.first == 0 || fraction.second == 0 )
    {
        return;
    }

    // If numerator divides denominator, then make division
    if ( fraction.second % fraction.first == 0 )
    {
        fraction.second /= fraction.first;
        fraction.first = 1;
        result.emplace_back( fraction );
        return;
    }

    // If denominator divides numerator, then its not a fraction
    if ( fraction.first % fraction.second == 0 )
    {
        result.emplace_back( make_pair( fraction.first / fraction.second, 1 ) );
        return;
    }

    // If numerator is greater than denominator
    if ( fraction.first > fraction.second )
    {
        result.emplace_back( make_pair( fraction.first / fraction.second, 1 ) );
        fraction.first %= fraction.second;
        findEgyptianFraction( fraction, result );
        return;
    }

    // Else 
    int p = fraction.second / fraction.first + 1;
    result.emplace_back( make_pair( 1, p ) );

    fraction.first = fraction.first * p - fraction.second;
    fraction.second = fraction.second * p;

    findEgyptianFraction( fraction, result );
}