/*
A string S of lowercase letters is given. 
We want to partition this string into as many parts as possible 
so that each letter appears in at most one part, 
and return a list of integers representing the size of these parts.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Compare
{
    bool operator() (pair<int, int> i,pair<int, int> j)
    {
        return ( i.first < j.first );
    }
} compare;

vector<int> partitionLabels( string S );
vector<int> partitionLabels2( string S );

int main(int argc, char const *argv[])
{
    string S = "baabcbacadefegdehijhklij";

    vector<int> r = partitionLabels2( S );

    for ( auto val : r )
    {
        cout << val << endl;
    }

    return 0;
}

vector<int> partitionLabels( string S )
{
    vector< pair<int, int> > vec( 26, make_pair( -1, -1 ) );

    for ( int i = 0; i < S.length(); i++ )
    {
        if ( vec[S[i] - 'a'].first == -1 )
        {
            vec[S[i] - 'a'].first = i;
        }

        if ( i > vec[S[i] - 'a'].second )
        {
            // cout << "here" << endl;
            vec[S[i] - 'a'].second = i;
        }
    }

    sort( vec.begin(), vec.end(), compare );

    priority_queue<pair<int, int>, vector< pair<int, int>>, Compare> pq;

    int count = 0;

    int i = 0;

    while( vec[i].first == -1 && i < 26)
    {
        i++;
    }

    if ( i >= 26 )
    {
        return {};
    }

    pq.push( vec[i++] );

    vector<int> result;

    for ( ; i < 26; i++ )
    {
        if ( vec[i].first < pq.top().second )
        {
            if ( vec[i].second > pq.top().second )
            {
                auto t = pq.top();
                pq.pop();
                t.second = vec[i].second;
                pq.push( t );
            }
        }
        else
        {
            result.emplace_back( pq.top().second - pq.top().first + 1);
            pq.pop();
            pq.push( vec[i] );
        }        
    }

    while ( !pq.empty() )
    {
        result.emplace_back(pq.top().second - pq.top().first + 1);
        pq.pop();
    }

    return result;
}

vector<int> partitionLabels2( string S )
{
    vector< int > vec( 26 );
    vector<int> result;

    for ( int i = 0; i < S.length(); i++ )
    {
        vec[S[i] - 'a'] = i;
    }
    
    pair<int, int> partition = make_pair( 0, 0 );
    
    for ( int i = 0; i < S.length(); i++ )
    {
        partition.second = max( partition.second, vec[S[i] - 'a'] );
        if ( i == partition.second )
        {
            result.emplace_back( i - partition.first + 1 );
            partition.first = i + 1;
        }
    }
    return result;
}