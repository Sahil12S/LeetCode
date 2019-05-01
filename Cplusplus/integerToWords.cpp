// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

#include <iostream>
#include <string>

using namespace std;

string ones( int num );
string elevens( int num );
string tens( int num );
string tensHelp( int num );
string hunderedsHelp( int num );
string numberToWord( int num );

int main(int argc, char const *argv[])
{
    // int num = 123;
    // int num = 12345;
    // int num = 1234567;
    int num = 1234567891;
    cout << numberToWord( num ) << '\n';
    return 0;
}

string ones( int num )
{
    switch( num )
    {
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
    }
    return "";
}

string elevens( int num )
{

    switch ( num )
    {
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
    }
    return "";
}

string tens( int num )
{
    switch( num )
    {
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
    }
    return "";
}

string tensHelp( int num )
{
    if ( num == 0 )
    {
        return "";
    }
    if ( num < 10 )
    {
        return ones( num );
    }
    else if ( num < 20 )
    {
        return elevens( num );
    }
    else
    {
        int ten = num / 10;
        int rest = num - ten * 10;
        if ( rest != 0 )
        {
            return tens( ten ) + " " + ones( rest );
        }
        else
        {
            return tens( ten );
        }
    }
}

string hunderedsHelp( int num )
{
    int hundered = num / 100;
    int rest = num - hundered * 100;

    if ( hundered != 0 && rest != 0 )
    {
        return ones( hundered ) + " Hundred " + tensHelp( rest );
    }
    else if ( hundered != 0 && rest == 0 )
    {
        return ones( hundered ) + " Hundered";
    }
    else if ( hundered == 0 && rest != 0 )
    {
        return tensHelp( rest );
    }
    
    return "";
}

string numberToWord( int num )
{
    int billions = num / 1000000000;
    int millions = ( num - billions * 1000000000 ) / 1000000;
    int thousands = ( num - billions * 1000000000 - millions * 1000000 ) / 1000;
    int rest = ( num - billions * 1000000000 - millions * 1000000 - thousands * 1000 );

    string result = "";

    if ( billions != 0 )
    {
        result += hunderedsHelp( billions ) + " Billion";
    }

    if ( millions != 0 )
    {
        if ( !result.empty() )
        {
            result += " ";
        }
        result += hunderedsHelp( millions ) + " Million";
    }

    if ( thousands != 0 )
    {
        if ( !result.empty() )
        {
            result += " ";
        }
        result += hunderedsHelp( thousands ) + " Thousand";
    }

    if ( rest != 0 )
    {
        if ( !result.empty() )
        {
            result += " ";
        }
        result += hunderedsHelp( rest );
    }
    return result.empty() ? "Zero" : result;
}