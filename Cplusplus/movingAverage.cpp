// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> nums;
    int windowSize;
    double sum;

public:

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        sum = 0.0;
    }

    double next(int val) {
        // double average = 0.0;
        // cout << "Size: " << nums.size() << endl;
        if (nums.size() + 1 > windowSize) {
            sum -= nums.front();
            // cout << "Popped " << nums.front() << endl;
            nums.pop();
        }
        nums.push(val);
        sum += val;
        // average = sum / nums.size();
        return (sum / nums.size());
        
    }
};

int main() {
    MovingAverage obj(3);
    cout << obj.next(1) << endl;
    cout << obj.next(10) << endl;
    cout << obj.next(3) << endl;
    cout << obj.next(5) << endl;


    return 0;
}