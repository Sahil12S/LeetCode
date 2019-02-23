// Implement Tower of Hanoi

#include <iostream>
#include <array>
#include <stack>
#include <vector>

using namespace std;

const int kNumPegs = 3;

void towerOfHanoiRecursion(int disks_to_move, array< stack<int>, kNumPegs>& pegs, 
                            int fromPeg, int toPeg, int auxPeg, vector< vector<int>>* result_ptr);

int main(int argc, char const *argv[])
{
    int fromPeg = 0, toPeg = 1, auxPeg = 2;
    array< stack<int>, kNumPegs> pegs;

    for (int i = kNumPegs; i > 0; i--)
    {
        pegs[0].push(i);
    }
    vector< vector<int>> result;

    towerOfHanoiRecursion(kNumPegs, pegs, fromPeg, toPeg, auxPeg, &result);

    // for (vector<int> nums : result)
    // {
    //     for (int num : nums)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

void towerOfHanoiRecursion(int disks_to_move, array< stack<int>, kNumPegs>& pegs, 
                            int fromPeg, int toPeg, int auxPeg, vector< vector<int>>* result_ptr)
{
    if (disks_to_move > 0)
    {
        // cout << "done: " << disks_to_move << endl;
        // cout << "from: " << fromPeg << ", to: " << toPeg << ", aux: " << auxPeg << endl;
        towerOfHanoiRecursion(disks_to_move - 1, pegs, fromPeg, auxPeg, toPeg, result_ptr);
        cout << "Move disk " << pegs[fromPeg].top() << " from peg " << fromPeg << " to peg " << toPeg << endl;
        pegs[toPeg].push(pegs[fromPeg].top());
        pegs[fromPeg].pop();
        // cout << "pushed and popped" << endl;
        result_ptr->emplace_back(vector<int>{fromPeg, toPeg});
        towerOfHanoiRecursion(disks_to_move - 1, pegs, auxPeg, toPeg, fromPeg, result_ptr);
    }
}