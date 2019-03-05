/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
private:
    struct Comparison
    {
        bool operator() (Interval c1, Interval c2)
        {
            return c2.end < c1.end;
        }
    };
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](auto& left, auto& right) {
            return left.start < right.start;
        });
        
        if (!intervals.size())
        {
            return 0;
        }
        
        priority_queue<Interval, vector<Interval>, Comparison> q;
        
        q.push(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < q.top().end)
            {
                q.push(intervals[i]);
            }
            else
            {
                q.pop();
                q.push(intervals[i]);
            }
        }

        return q.size();
    }
};