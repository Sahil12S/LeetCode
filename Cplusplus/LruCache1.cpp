class LRUCache {
private:
    struct DList
    {
        // private:
        int key;
        int value;
        DList* next;
        DList* prev;
        DList() : key(0), value(0), next(nullptr), prev(nullptr) {}
        DList(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    };
    
    void addNode(DList* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        // head = node;
    }
    
    void removeNode(DList* node)
    {
        // DList* temp = node
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        // delete node;
    }
    
    void moveToFront(DList* node)
    {
        removeNode(node);
        addNode(node);
    }
    
    DList* removeTail()
    {
        DList* temp = tail->prev;
        removeNode(temp);
        return temp;
    }
    
    DList* head, *tail;
    // list<pair<int, int>> l;
    int capacity, size;
    map<int, DList*> keyNode;
    // int size = 0;
    
public:
    LRUCache(int capacity) {
        // lruList.resize(capacity);
        // itr = lru.begin();
        this->capacity = capacity;
        size = 0;
        
        head = new DList();
        tail = new DList();
        
        cout << typeid(tail).name() << endl;
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        /*auto itr = keyNode.find(key);
        if (itr == keyNode.end())
        {
            return -1;
        }
        else
        {
            cout << typeid(*itr).name() << endl;
            
            int value = (*(*itr)->second).second;
            lruList.erase(*itr);
            lruList.push_back(make_pair(key, value));
            keyNode[key] = lruList.end() - 1;
            return value;
        }*/
        
        if (!keyNode.count(key))
        {
            return -1;
        }
        else
        {
            DList* node = keyNode[key];
            moveToFront(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        /*auto itr = keyNode.find(key);
        // key doesn't exist
        if (itr == keyNode.end())
        {
            if (lruList.size() < capacity)
            {
                lruList.push_back(make_pair(key, value));
                keyNode[key] = lruList.end() - 1;
            }
            else
            {
                lruList.pop_front();
                keyNode.erase(key);
                lruList.push_back(make_pair(key, value));
                keyNode[key] = lruList.end() - 1;
            }
        }
        else
        {
            lruList.erase(itr->second);
            lruList.push_back(make_pair(key, value));
            keyNode[key] = lruList.end() - 1;
        }*/
        
        if (!keyNode.count(key))
        {
            DList* node = new DList(key, value);
            addNode(node);
            keyNode[key] = node;
            size++;
            
            if (size > capacity)
            {
                DList* temp = removeTail();
                size--;
                keyNode.erase(temp->key);
            }
        }
        else
        {
            removeNode(keyNode[key]);
            DList* node = new DList(key, value);
            addNode(node);
            keyNode[key] = node;
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */