class LRUCache {
private:  
    list< pair<int, int>> lruList;
    map<int, list< pair<int, int>>::iterator> keyNode;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto itr = keyNode.find(key);
        if (itr == keyNode.end())
        {
            return -1;
        }
        else
        {   
            int value = (*itr->second).second;
            lruList.erase(itr->second);
            lruList.push_back(make_pair(key, value));
            keyNode[key] = --lruList.end();
            return value;
        }
    }
    
    void put(int key, int value) {
        auto itr = keyNode.find(key);
        // key doesn't exist
        if (itr == keyNode.end())
        {
            lruList.push_back(make_pair(key, value));
            keyNode[key] = --lruList.end();
            
            if (lruList.size() > capacity)
            {
                keyNode.erase(lruList.front().first);
                lruList.pop_front();
            }
        }
        else
        {
            lruList.erase(itr->second);
            lruList.push_back(make_pair(key, value));
            keyNode[key] = --lruList.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */