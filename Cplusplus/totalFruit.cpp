#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int totalFruit(vector<int>& tree);

int main(int argc, char const *argv[])
{

    // vector<int> tree = {1, 2, 1};
    // vector<int> tree = {0,1,2,2};
    // vector<int> tree = {1,2,3,2,2};
    // vector<int> tree = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> tree = {0,0,1,1};


    cout << totalFruit(tree) << endl;

    return 0;
}

int totalFruit(vector<int>& tree) {
    // Store fruit number and their count.
    pair<int, int> basket1 = {-1, 0};
    pair<int, int> basket2 = {-1, 0};

    int maxFruitCount = 0;
    int treeIndex = 0;
    int lastFruitChangeIndex = -1;

    while (treeIndex < tree.size()) {
        // First basket is empty
        if (!basket1.second) {
            basket1.first = tree[treeIndex];
            cout << "First basket: " << basket1.first << endl;
            basket1.second++;
        }
        // Second basket is empty
        else if (!basket2.second && basket1.first != tree[treeIndex]) {
            basket2.first = tree[treeIndex];
            cout << "Second basket: " << basket2.first << endl;
            basket2.second++;
            lastFruitChangeIndex = treeIndex;
        }
        // Same fruit as in basket1
        else if (tree[treeIndex] == basket1.first) {
            basket1.second++;
        }
        // Same fruit as in basket2
        else if (tree[treeIndex] == basket2.first) {
            basket2.second++;
        } 
        // Third type of fruit
        else {
            int totalFruit = basket1.second + basket2.second;
            if (totalFruit > maxFruitCount) {
                maxFruitCount = totalFruit;
            }
            basket1 = {basket2.first, 1};
            basket2 = {-1, 0};
            treeIndex = lastFruitChangeIndex;
        }
        treeIndex++;
    }

    int totalFruit = basket1.second + basket2.second;
    if (totalFruit > maxFruitCount) {
        maxFruitCount = totalFruit;
    }    

    return maxFruitCount;
}