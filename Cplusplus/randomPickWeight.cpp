/*
 * Given an array w of positive integers, where w[i] describes the weight of index i,
 * write a function pickIndex which randomly picks an index in proportion to its weight.
 */

#include <vector>
#include <random>
#include <algorithm>

class Solution {
private:
    std::vector<int> vec;
    
public:
    Solution( std::vector<int> w) {
        // Add cumulative sum of weights in an array
        for( int i : w )
        {
            vec.emplace_back( vec.empty() ? i : i + vec.back() );
        }
    }
    
    int pickIndex() {
        int cumSum = vec.back();    // Store the cumulative sum

        // Get a value
        int randIdx = std::rand() % cumSum;

        // Find index which is greater than our value
        auto it = std::upper_bound( vec.begin(), vec.end(), randIdx );
        return it - vec.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

/*
SOMEBODY's EXPLANATION

 * say you have a vector w = [4,1,2]
 * so you would expect a result something like this ... 4,1,2,4,4,2,4,4.....
 * Please note 4 occurs more times followed by 2 than 1.

 * now lets create a new_vector = [4,4,4,4,1,2,2]
 * if you pick an index randomly from index 0 to 6, you would find more 4s than 2s than 1s.

 * Since above step would require a very big array when dealing with big numbers,
 * lets try another approach that zhoubowei has tried above.

 * lets create a sum_vector (vector s; in above code) = [4,5,7] where s[i] = sum of original vector till ith index.

 * Now imagine a number line between 0 to 7. PLEASE note the difference between 
 * two adjacent elements in vector s represent the share on a number line that the original element in vector w should have.
 * if you request a random number between 0 to 7, you may get numbers in 3 buckets .

 * between [0 to 4] (0,4 including)
 * between (4 to 5 ]
 * between (5,7]
 * Think of a Number Line mentally..................0,1,2,3,4, 5, 6,7 .................

 * Now out of 3 buckets, its more likely that a random number would be found in first bucket as it has more numbers i.e from [0 to 4]

 * so, basically find a random number between zero and total sum i.e last element in sum_vector.
 * say the random weight is r. Please note its more likely that the random number 
 * will be in 1st bucket (because 1st bucket would have more elements).

 * int r = rand() % m; // please note m = last element of vector s in above code.

 * now do a binary search of m in vector s. Please note vector S is a sorted array.
 * Find the first number that is greater than m in vector s and return its index.
*/