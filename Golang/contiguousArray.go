/*
Given a binary array, find the maximum length of a
contiguous subarray with equal number of 0 and 1.
*/

package main

func findMaxLength(nums []int) int {
	count := 0
	maxL := 0

	myMap := make(map[int]int)
	myMap[0] = -1

	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			count++
		} else {
			count--
		}

		if idx, ok := myMap[count]; !ok {
			myMap[count] = i
		} else {
			maxL = max(maxL, i-idx)
		}
	}
	return maxL
}
