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
    std::unordered_map<int, int> m_KeyCount;                     // maps keys to their frequency
    std::map<int, std::deque<std::pair<int, int>>> m_CountValue; // maps counts and values
    // std::unordered_map<int, int>;
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
        std::cout << "Accessing key: " << key << '\n';
        if (m_KeyCount.find(key) == m_KeyCount.end())
        {
            return -1;
        }

        // Accessing the element, increases it's frequency
        int freq = m_KeyCount[key]++;
        int retVal = -1;

        std::cout << "Current frequency: " << freq << ", new: " << m_KeyCount[key] << '\n';

        for (auto it = m_CountValue[freq].begin(); it != m_CountValue[freq].end(); it++)
        {
            if (it->first == key)
            {
                retVal = it->second;

                // Put element in new frequency.
                m_CountValue[freq + 1].push_back({it->first, it->second});
                // Remove the element from older list.
                m_CountValue[freq].erase(it);
                std::cout << "size for freq: " << freq << " after update: " << m_CountValue[freq].size() << " " << m_CountValue[freq].front().first << '\n';
                if (m_CountValue[freq].size() == 0)
                {
                    m_CountValue.erase(freq);
                }
                break;
            }
        }

        return retVal;
    }

    void put(int key, int value)
    {
        if (m_Capacity == 0)
        {
            return;
        }
        std::cout << "Received- k: " << key << ", v: " << value << '\n';

        if (m_KeyCount.find(key) == m_KeyCount.end())
        {
            if (m_CurrCount == m_Capacity)
            {
                m_CurrCount--;
                auto &it = *m_CountValue.begin();
                auto k = it.second.front().first;
                std::cout << "Removing key: " << k << " of freq: " << it.first << '\n';
                it.second.pop_front();
                if (it.second.size())
                {
                    std::cout << "New front val: " << it.second.front().first << '\n';
                }
                if (it.second.size() == 0)
                {
                    m_CountValue.erase(m_CountValue.begin());
                }

                m_KeyCount.erase(k);
            }
            std::cout << "Added key: " << key << '\n';
            m_KeyCount[key] = 1;
            m_CountValue[1].push_back({key, value});
            m_CurrCount++;
            std::cout << "New size: " << m_CountValue[1].size() << " " << m_CountValue[1].front().first << "\n";
        }
        else
        {
            int freq = m_KeyCount[key]++;
            int retVal = -1;

            std::cout << "Current frequency: " << freq << ", new: " << m_KeyCount[key] << '\n';

            for (auto it = m_CountValue[freq].begin(); it != m_CountValue[freq].end(); it++)
            {
                if (it->first == key)
                {
                    // Put element in new frequency.
                    m_CountValue[freq + 1].push_back({key, value});
                    // Remove the element from older list.
                    m_CountValue[freq].erase(it);
                    if (m_CountValue[freq].size() == 0)
                    {
                        m_CountValue.erase(freq);
                    }
                    break;
                }
            }
        }
    }
};

void print(std::vector<int> vec);

int main()
{
    LFUCache *cache = new LFUCache(3);
    cache->put(1, 1);
    std::cout << '\n';
    cache->put(2, 2);
    std::cout << '\n';
    cache->put(3, 3);
    std::cout << '\n';
    cache->put(4, 4);
    std::cout << '\n';
    std::cout << cache->get(4) << '\n'; // returns 1
    std::cout << '\n';
    std::cout << cache->get(3) << '\n'; // returns 1
    std::cout << '\n';
    std::cout << cache->get(2) << '\n'; // returns 1
    std::cout << '\n';
    std::cout << cache->get(1) << '\n'; // returns 1
    std::cout << '\n';
    cache->put(5, 5); // evicts key 2
    std::cout << '\n';
    std::cout << cache->get(1) << '\n'; // returns -1 (not found)
    std::cout << '\n';
    std::cout << cache->get(2) << '\n'; // returns 3.
    std::cout << '\n';
    std::cout << cache->get(3) << '\n'; // returns -1 (not found)
    std::cout << '\n';
    std::cout << cache->get(4) << '\n'; // returns 3
    std::cout << '\n';
    std::cout << cache->get(5) << '\n'; // returns 4
    std::cout << '\n';

    // std::deque<int> dq;
    // std::make_heap(dq.begin(), dq.end());
    // dq.push_back(1);
    // std::push_heap(dq.begin(), dq.end());
    // std::cout << dq.front() << '\n';
    // dq.push_back(2);
    // std::push_heap(dq.begin(), dq.end());
    // std::cout << dq.front() << '\n';

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