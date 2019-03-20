// Find common interest with the least list index sum

#include <iostream>
#include <map>
#include <vector>
#include <limits>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);

int main() {
    // vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    // vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> list1 = {"Shogun", "Tapioca Express", "KFC", "Burger King"};
    vector<string> list2 = {"Burger King", "KFC", "Chipotle", "Shogun"};

    vector<string> ans = findRestaurant(list1, list2);

    for (string item : ans) {
        cout << item << endl;
    }

    return 0;
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    map<string, int> listMap;

    for (int i = 0; i < list1.size(); ++i) {
        listMap[list1[i]] = i;
    }

    int minIndex = numeric_limits<int>::max();
    string dish;

    vector<string> ans;

    for (int j = 0; j < list2.size(); ++j) {
        if (listMap.count(list2[j]) > 0) {
            int index = j + listMap[list2[j]];
            if (index < minIndex) {
                minIndex = j + listMap[list2[j]];
                ans.clear();
                ans.push_back(list2[j]);
            } else if (index == minIndex) {
                ans.push_back(list2[j]);
            }
        }
    }
    return ans;
}