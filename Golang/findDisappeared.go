package main

func findDisapperedNumbers(nums []int) []int {
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
			ans = append(ans, i+1)
		}
	}
	return ans
}
