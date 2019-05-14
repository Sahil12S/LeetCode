/*
    Median is the middle value in an ordered integer list.
    If the size of the list is even, there is no middle value.
    So the median is the mean of the two middle value.

    For example,
    [2,3,4], the median is 3

    [2,3], the median is (2 + 3) / 2 = 2.5

    Design a data structure that supports the following two operations:

    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.
*/


// BASIC MULTISET

#include <set>
#include <queue>

class MedianFinder {
private:
    std::multiset<int> stream;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        stream.emplace( num );
    }
    
    double findMedian() {
        int size = stream.size();
        if( size % 2 == 1 )
        {
            auto it = stream.begin();
            advance( it, size / 2 );
            return static_cast<double>( *it );
        }
        else
        {
            auto it = stream.begin();
            advance( it, ( size - 1 ) / 2 );
            return static_cast<double>( *it + *(++it) ) / static_cast<double>( 2 );
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// IMPROVED MULTISET

class MedianFinder {
private:
    std::multiset<int> stream;
    std::multiset<int>::iterator mid;
public:
    /** initialize your data structure here. */
    MedianFinder() : mid( stream.end() ) {
        
    }
    
    void addNum(int num) {
        int n = stream.size();
        
        stream.emplace( num );
        
        // If its first element
        if( n == 0 )
        {
            mid = stream.begin();
        }
        // Inserted number is smaller, so we decrease median
        else if( num < *mid )
        {
            // Check for odd and even, if even, go back one position
            mid = ( n & 1 ? mid : prev( mid ) );
        }
        else
        {
            // Check for odd and even, if odd, go ahead one position
            mid = ( n & 1 ? next( mid ) : mid );
        }
    }
    
    double findMedian() {
        const int n = stream.size();
        return ( *mid + *next( mid, n % 2 - 1 ) ) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// USING 2 PRIORITY QUEUES
class MedianFinder {
private:
    std::priority_queue<int> lo_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi_pq;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo_pq.push( num );
        
        hi_pq.push( lo_pq.top() );
        lo_pq.pop();
        
        
        // Remove largest element from lo_pq and insert it into hi_pq
        if( lo_pq.size() < hi_pq.size() )
        {
            lo_pq.push( hi_pq.top() );
            hi_pq.pop();
        }
    }
    
    double findMedian() {
        return lo_pq.size() > hi_pq.size() ? static_cast<double>( lo_pq.top() ) : ( lo_pq.top() + hi_pq.top() ) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */