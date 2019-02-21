// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int findKthLargest(vector<int>& nums, int k);

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,1,5,6,4};

    cout << findKthLargest(nums, 3) << endl;
    
    return 0;
}

int findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int n : nums)
    {
        q.emplace(n);
        if (q.size() > k)
        {
            q.pop();
        }
    }
    return q.top();
}