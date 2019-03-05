// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
// There is at least one empty seat, and at least one person sitting.
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
// Return that maximum distance to closest person.

#include <iostream>
#include <vector>

using namespace std;

int maxDistToClosest(vector<int>& seats);

int main(int argc, char const *argv[])
{
    vector<int> seats = {1,0,0,0,1,0,1};
    cout << maxDistToClosest(seats) << endl;
    return 0;
}

int maxDistToClosest(vector<int>& seats)
{
    int n = seats.size();
    int prev = -1, next = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (seats[i] == 1)
        {
            prev = i;
        }
        else
        {
            while (next < n && seats[next] == 0 || next < i)
            {
                next++;
            }
            int l = prev == -1 ? n : i - prev;
            int r = next == n ? n : next - i;
            ans = max(ans, min(l, r));
        }
        
    }
    return ans;
}