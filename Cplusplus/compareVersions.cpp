/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.
You may assume the default revision number for each level of a version number to be 0. 
For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. 
Its third and fourth level revision number are both 0.
*/

#include <iostream>
#include <queue>

using namespace std;

int compareVersion( string version1, string version2 );

// queue<int> convert( string version );

int main(int argc, char const *argv[])
{
    // string version1 = "1.0.1";
    // string version2 = "1";
    // string version1 = "0.1";
    // string version2 = "1.1";
    // string version1 = "7.5.2.4";
    // string version2 = "7.5.3";
    // string version1 = "1.01";
    // string version2 = "1.001";
    string version1 = "1";
    string version2 = "0";

    cout << compareVersion( version1, version2 ) << endl;

    return 0;
}
/*
int compareVersion( string version1, string version2 )
{
    queue<int> v1 = convert( version1 );
    queue<int> v2 = convert( version2 );

    while ( !v1.empty() && !v2.empty() )
    {
        cout << "v1: " << v1.front() << endl;
        cout << "v2: " << v2.front() << endl;
        if ( v1.front() < v2.front() )
        {
            return -1;
        }
        else if ( v1.front() > v2.front() )
        {
            return 1;
        }
        
        v1.pop();
        v2.pop();
    }

    if ( v2.empty() )
    {
        while( !v1.empty() )
        {
            if ( v1.front() > 0 )
            {
                return 1;
            }
            v1.pop();
        }
    }

    if ( v1.empty() )
    {
        while( !v2.empty() )
        {
            if ( v2.front() > 0 )
            {
                return -1;
            }
            v2.pop();
        }
    }
    return 0;
}

queue<int> convert( string version )
{
    queue<int> q;
    
    string s;

    for ( char c : version )
    {
        if ( c == '.' )
        {
            q.push( stoi( s ) );
            s = "";
        }
        else
        {
            s += c;
        }   
    }
    q.push( stoi( s ) );

    return q;
}
*/

int compareVersion( string version1, string version2 )
{
    int nums1 = 0;
    int nums2 = 0;

    int i = 0;
    int j = 0;

    while ( i < version1.size() || j < version2.size() )
    {
        while ( i < version1.size() && version1[i] != '.' )
        {
            nums1 += nums1 * 10 + (version1[i] - '0');
            i++;
        }

        while ( j < version2.size() && version2[j] != '.' )
        {
            nums2 += nums2 * 10 + (version2[j] - '0');
            j++;
        }

        if ( nums1 > nums2 )
        {
            return 1;
        }
        if ( nums2 > nums1 )
        {
            return -1;
        }

        nums1 = 0;
        nums2 = 0;
        i++;
        j++;
    }
    return 0;
}