/*
Given an array nums and a target value k,
find the maximum length of a subarray that sums to k.
If there isn't one, return 0 instead.
*/
package main

func maxSubArrayLen(nums []int, k int) int {
	var sum int
	var myMap = make(map[int]int)
	length := 0

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		if sum == k {
			length = i + 1
		}

		if _, ok := myMap[sum]; !ok {
			myMap[sum] = i
		}

		if idx, ok := myMap[sum-k]; ok {
			length = max(length, (i - idx))
		}
	}
	return length
}

// Find max value
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
