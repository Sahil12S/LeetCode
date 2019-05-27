/**
 * We are given a list schedule of employees, which represents the working time for each employee.
 * Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
 * Return the list of finite intervals representing common,
 * positive-length free time for all employees, also in sorted order.
 * 
 * Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 * Output: [[3,4]]
 * Explanation:
 * There are a total of three employees, and all common
 * free time intervals would be [-inf, 1], [3, 4], [10, inf].
 * We discard any intervals that contain inf as they aren't finite.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> employeeFreeTime(std::vector<std::vector<std::vector<int>>> &schedule);

int main()
{
    // std::vector<std::vector<std::vector<int>>> schedule = {{{5, 6}, {1, 2}}, {{1, 3}}, {{4, 10}}};
    std::vector<std::vector<std::vector<int>>> schedule = {{{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};
    std::vector<std::vector<int>> res = employeeFreeTime(schedule);
    for (auto &v : res)
    {
        std::cout << v[0] << " " << v[1] << std::endl;
    }
    return 0;
}

std::vector<std::vector<int>> employeeFreeTime(std::vector<std::vector<std::vector<int>>> &schedule)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> start_time;
    std::priority_queue<int, std::vector<int>, std::greater<int>> end_time;
    std::vector<std::vector<int>> res;

    for (auto &emp : schedule)
    {
        for (auto &time : emp)
        {
            start_time.push(time[0]);
            end_time.push(time[1]);
        }
    }

    start_time.pop();
    while (!start_time.empty())
    {
        if (end_time.top() < start_time.top())
        {
            res.emplace_back(std::vector<int>{end_time.top(), start_time.top()});
        }
        start_time.pop();
        end_time.pop();
    }

    return res;
}