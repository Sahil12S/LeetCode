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

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto &left, auto &right) {
            return left.start < right.start;
        });
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i-1].end)
            {
                return false;
            }
        }
        
        return true;
    }
};