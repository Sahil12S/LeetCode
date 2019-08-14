/**
 * Design and implement LFU (Least Frequently Used) Cache
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>

class LFUCache
{
private:
    std::unordered_map<int, int> m_KeyCount;                                    // maps keys to their frequency
    std::map<int, std::deque<std::pair<int, int>>> m_CountValue;                // maps counts and values
    std::unordered_map<int, std::deque<std::pair<int, int>>::iterator> m_itMap; // Maps key with iterator
    int m_Capacity;
    int m_CurrCount;

public:
    LFUCache(int capacity)
    {
        m_Capacity = capacity;
        m_CurrCount = 0;
    }

    int get(int key)
    {
        // std::cout << "Accessing key: " << key << '\n';
        if (m_KeyCount.find(key) == m_KeyCount.end())
        {
            return -1;
        }

        // Accessing the element, increases it's frequency
        int freq = m_KeyCount[key]++;
        // int retVal = -1;
        std::pair<int, int> val = *m_itMap[key];
        m_CountValue[freq].erase(m_itMap[key]);

        if (m_CountValue[freq].size() == 0)
        {
            m_CountValue.erase(freq);
        }

        m_CountValue[freq + 1].push_back(val);
        m_itMap[key] = std::prev(m_CountValue[freq + 1].end());

        // std::cout << "Current frequency: " << freq << ", new: " << m_KeyCount[key] << '\n';

        return val.first;
    }

    void put(int key, int value)
    {
        if (m_Capacity == 0)
        {
            return;
        }
        // std::cout << "Received- k: " << key << ", v: " << value << '\n';

        // If we are adding a new key, value
        if (m_KeyCount.find(key) == m_KeyCount.end())
        {
            if (m_CurrCount == m_Capacity)
            {
                m_CurrCount--;
                auto &it = *m_CountValue.begin();
                auto k = it.second.front().first;
                it.second.pop_front();

                if (it.second.size() == 0)
                {
                    m_CountValue.erase(m_CountValue.begin());
                }

                m_KeyCount.erase(k);
                m_itMap.erase(k);
            }
            // std::cout << "Added key: " << key << '\n';
            m_KeyCount[key] = 1;
            m_CountValue[1].push_back({key, value});
            m_itMap[key] = std::prev(m_CountValue[1].end());
            m_CurrCount++;
            // std::cout << "New size: " << m_CountValue[1].size() << " " << m_CountValue[1].front().first << "\n";
        }
        else
        {
            // If we are only updating existing key,
            // we don't have to check for size of our cache
            int freq = m_KeyCount[key]++;
            int retVal = -1;

            // key already exists
            std::pair<int, int> val = *m_itMap[key];
            m_CountValue[freq].erase(m_itMap[key]);
            m_CountValue[freq + 1].push_back(val);
            m_itMap[key] = std::prev(m_CountValue[freq + 1].end());
        }
    }
};

void print(std::vector<int> vec);

int main()
{
    LFUCache *cache = new LFUCache(3);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    std::cout << cache->get(4) << '\n'; // returns 4
    std::cout << cache->get(3) << '\n'; // returns 3
    std::cout << cache->get(2) << '\n'; // returns 2
    std::cout << cache->get(1) << '\n'; // returns -1 (not found)
    cache->put(5, 5);
    std::cout << cache->get(1) << '\n'; // returns -1 (not found)
    std::cout << cache->get(2) << '\n'; // returns 2
    std::cout << cache->get(3) << '\n'; // returns 3
    std::cout << cache->get(4) << '\n'; // returns -1 (not found)
    std::cout << cache->get(5) << '\n'; // returns 5

    return 0;
}

void print(std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << '\n';
        it++;
    }
}