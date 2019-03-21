/*
Given an array nums of n integers, are there elements
a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
*/

package main

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	var ans [][]int

	for i := 0; i < len(nums); i++ {
		// myMap := make(map[int]int)
		left := i + 1
		right := len(nums) - 1
		target := -nums[i]

		for left < right {
			sum := nums[left] + nums[right]
			if sum < target {
				left++
			} else if sum > target {
				right--
			} else {

				a := []int{nums[i], nums[left], nums[right]}
				ans = append(ans, a)

				for left < right && nums[left] == a[1] {
					left++
				}
				for left < right && nums[right] == a[2] {
					right--
				}
			}
		}
		for i+1 < len(nums) && nums[i+1] == nums[i] {
			i++
		}
	}
	return ans

}
