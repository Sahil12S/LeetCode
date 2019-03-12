// Given a non-empty array of integers, return the k most frequent elements.

package main

import (
	"container/heap"
)

// NumFreq store number and its frequency
type NumFreq struct {
	Num  int
	Freq int
}

// PriorityQueue array of NumFreq type
type PriorityQueue []*NumFreq

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Freq >= pq[j].Freq
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

// Push a value of type interface
func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*NumFreq)
	*pq = append(*pq, item)
}

// Pop a value from queue and return it
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(*pq)
	item := old[n-1]
	// item.index = -1
	*pq = old[0 : n-1]
	return item
}

func topKFrequent(nums []int, k int) []int {
	numMap := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		numMap[nums[i]]++
	}

	myNums := make(PriorityQueue, len(numMap))

	i := 0
	for num, freq := range numMap {
		myNums[i] = &NumFreq{num, freq}
		i++
	}

	heap.Init(&myNums)
	var ans []int
	for i = 0; i < k; i++ {
		num := heap.Pop(&myNums).(*NumFreq)
		ans = append(ans, num.Num)
	}

	return ans
}
