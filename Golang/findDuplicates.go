/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
*/

package main

/*
	Implementation 2
*/
func findDuplicates(nums []int) []int {
	var ans []int

	for i := 0; i < len(nums); i++ {
		idx := abs(nums[i]) - 1
		if nums[idx] > 0 {
			nums[idx] *= -1
		} else {
			ans = append(ans, idx+1)
		}
	}
	return ans
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

/*
	Implementation 1

func findDuplicates(nums []int) []int {
	var i int
	for i < len(nums) {
		if nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		} else {
			i++
		}
	}
	var ans []int
	for i = 0; i < len(nums); i++ {
		if nums[i]-1 != i {
			ans = append(ans, nums[i])
		}
	}
	return ans
}
*/
