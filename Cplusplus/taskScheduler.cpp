/*
 * Given a char array representing tasks CPU need to do.
 * It contains capital letters A to Z where different letters represent different tasks.
 * Tasks could be done without original order. Each task could be done in one interval.
 * For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two same tasks,
 * there must be at least n intervals that CPU are doing different tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int leastInterval( std::vector<char>& tasks, int n );

int main(int argc, char const *argv[])
{
    std::vector<char> tasks = {'A','A','A','B','B','B','C','C' };
    int n = 2;

    std::cout << leastInterval( tasks, n ) << '\n';
    return 0;
}

int leastInterval( std::vector<char>& tasks, int n )
{
    std::vector< int > taskCounts(26);

    int count = 0;

    // Find task with max count
    for( char task : tasks )
    {
        taskCounts[ task - 'A' ]++;
        count = std::max( count, taskCounts[ task - 'A' ] );
    }

    // Find total time until last cycle
    int time = ( count - 1 ) * ( n + 1 );

    // Calculate time for last cycle
    for( auto e : taskCounts )
    {
        if( e == count )
        {
            time++;
        }
    }

    return std::max( (int)tasks.size(), time );
}