/**
 * You have a lock in front of you with 4 circular wheels.
 * Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
 * The wheels can rotate freely and wrap around:
 * for example we can turn '9' to be '0', or '0' to be '9'.
 * Each move consists of turning one wheel one slot.
 * 
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 * 
 * You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
 * the wheels of the lock will stop turning and you will be unable to open it.
 * 
 * Given a target representing the value of the wheels that will unlock the lock,
 * return the minimum total number of turns required to open the lock, or -1 if it is impossible.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

int openLock1(std::vector<std::string> &deadends, std::string target);
int openLock2(std::vector<std::string> &deadends, std::string target);
std::vector<std::string> find_neighbors(std::string s);

int main(int argc, char const *argv[])
{
    // std::vector<std::string> deadends = {"0000"};
    // std::string target = "8888";
    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    std::string target = "0202";
    std::cout << openLock2(deadends, target) << '\n';
    return 0;
}

// Bidirectional BFS
int openLock2(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> dends(deadends.begin(), deadends.end());
    std::unordered_set<std::string> first, second, temp, visited;

    if (dends.count("0000") > 0 || dends.count(target) > 0)
    {
        return -1;
    }
    int count = 0;
    visited.insert("0000");
    first.insert("0000");
    second.insert(target);

    while (!first.empty() && !second.empty())
    {
        if (first.size() > second.size())
        {
            std::swap(first, second);
        }

        temp.clear();
        for (auto t : first)
        {
            std::vector<std::string> neighbors = find_neighbors(t);
            for (auto val : neighbors)
            {
                if (second.count(val))
                {
                    return ++count;
                }
                // Check if we already visited this combination
                if (visited.count(val) > 0)
                {
                    continue;
                }
                // Check if current value is a deadend or not
                if (dends.count(val) == 0)
                {
                    temp.insert(val);
                    visited.insert(val);
                }
            }
        }
        std::swap(first, temp);
        count++;
    }
    return -1;
}

int openLock1(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> dends(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;
    std::queue<std::string> q;

    if (dends.count("0000") > 0 || dends.count(target) > 0)
    {
        return -1;
    }

    int count = 0;

    q.push("0000");
    visited.insert("0000");

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            std::string curr = q.front();
            q.pop();

            std::vector<std::string> neighbors = find_neighbors(curr);

            for (auto val : neighbors)
            {
                // If it's target, then increment our count
                if (val == target)
                {
                    return ++count;
                }
                // Check if we already visited this combination
                if (visited.count(val) > 0)
                {
                    continue;
                }
                // Check if current value is a deadend or not
                if (dends.count(val) == 0)
                {
                    q.push(val);
                    visited.insert(val);
                }
            }
        }
        // Increment number of steps we have taken so far
        count++;
    }
    return -1;
}

// Find all the steps that we can take from current step
std::vector<std::string> find_neighbors(std::string s)
{
    std::vector<std::string> retval;
    for (int i = 0; i < 4; i++)
    {
        std::string temp = s;
        // Increment one
        temp[i] = (s[i] - '0' + 1) % 10 + '0';
        retval.emplace_back(temp);
        // Decrement one
        temp[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
        retval.emplace_back(temp);
    }
    return retval;
}