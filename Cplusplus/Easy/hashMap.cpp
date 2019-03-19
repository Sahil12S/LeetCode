// Implement hash map.

#include <vector>
#include <list>
#include <utility>
#include <iostream>
// #include <array>

using namespace std;

class MyHashMap {
private:
vector <list <pair <int, int>>> myMap;
int m_size = 10000;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        myMap.resize(m_size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {

        for (pair<int, int> &p : myMap[key % m_size]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        
        myMap[key % m_size].emplace_back(key, value);

    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (pair<int, int> p : myMap[key % m_size]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list< pair<int, int>> l = myMap[key % m_size];
        list < pair<int, int>>::iterator it;
        for (it = myMap[key % m_size].begin(); it != myMap[key % m_size].end(); ++it) {
            if (it->first == key) {
                cout << "Found key" << endl;
                break;
            }
        }
        myMap[key % m_size].erase(it);
    }

    void print() {
        vector <list <pair <int, int>>>::iterator mapItr;
        cout << "Printing values: " << endl;
        for (list <pair <int, int>> l : myMap) {
            for (pair<int, int> item : l) {
                cout << item.first << ", " << item.second << endl;
            }
        }
        cout << "---------" << endl;
    }
};

int main(int argc, char const *argv[])
{
    MyHashMap obj;
    obj.put(1, 1);
    obj.put(2, 2);
    obj.print();
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    obj.put(2, 5);
    obj.print();
    // obj.print();
    cout << obj.get(2) << endl;
    obj.remove(2);
    obj.print();
    cout << obj.get(2) << endl;

    // cout << "----------" << endl;
    // list <pair <int, int>> l;
    // pair <int, int> p;
    // p = make_pair(2, 4);
    // l.push_back(make_pair(2, 4));
    // l.push_back(make_pair(1, 5));
    // l.push_back(make_pair(6, 2));

    // list<int> a = {1, 2, 3, 4};
    // list<pair<int, int>>::iterator it;
    // for (it = l.begin(); it != l.end(); ++it) {
    //     if (it->first == 1) {
    //         break;
    //     }
    // }

    // l.erase(it);
    // for (list<pair<int, int>>::iterator it = l.begin(); it != l.end(); ++it) {
    //     cout << it->first << endl;
    // }

    // f
    
    return 0;
}
