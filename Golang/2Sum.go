package main

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
