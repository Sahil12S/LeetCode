#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class TimeMap
{
private:
    std::map<std::string, std::vector<std::pair<int, std::string>>> m;

    struct Compare
    {
    public:
        bool operator()(const std::pair<int, std::string> &p1, const std::pair<int, std::string> &p2)
        {
            return p1.first < p2.first;
        }
    };

public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }

    void set(std::string key, std::string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp)
    {
        std::string ans = "";
        auto up_itr = std::upper_bound(m[key].begin(), m[key].end(), std::pair<int, std::string>(timestamp, ""), Compare());

        return up_itr == m[key].begin() ? "" : std::prev(up_itr)->second;
    }
};

int main()
{
    TimeMap *obj = new TimeMap();
    // obj->set("foo", "bar", 1);
    // std::cout << obj->get("foo", 1) << '\n';
    // std::cout << obj->get("foo", 3) << '\n';
    // obj->set("foo", "bar2", 4);
    // std::cout << obj->get("foo", 4) << '\n';
    // std::cout << obj->get("foo", 5) << '\n';

    obj->set("love", "high", 10);
    obj->set("love", "low", 20);
    std::cout << obj->get("love", 5) << '\n';
    std::cout << obj->get("love", 10) << '\n';
    std::cout << obj->get("love", 15) << '\n';
    std::cout << obj->get("love", 20) << '\n';
    std::cout << obj->get("love", 25) << '\n';
    return 0;
}