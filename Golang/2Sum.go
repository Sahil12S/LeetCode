package main

import "fmt"

func twoSum(nums []int, target int) []int {
	myMap := make(map[int]int)
	var ans []int

	for i := 0; i < len(nums); i++ {
		rem := target - nums[i]
		elem, ok := myMap[rem]

		if ok {
			ans = append(ans, elem)
			ans = append(ans, i)
			break
		}

		myMap[nums[i]] = i
	}
	return ans
}

func main() {
	// nums := []int{2, 7, 11, 15}
	nums := []int{0, 4, 3, 0}
	target := 0

	ans := twoSum(nums, target)

	fmt.Println(ans)
}
