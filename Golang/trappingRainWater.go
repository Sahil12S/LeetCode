/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1, compute how much water it
is able to trap after raining.
*/

package main

func trap(height []int) int {
	/*
		if len(height) == 0 {
			return 0
		}

		ans := 0
		maxLeft := make([]int, len(height))
		maxRight := make([]int, len(height))

		maxLeft[0] = height[0]
		for i := 1; i < len(height); i++ {
			maxLeft[i] = max(maxLeft[i-1], height[i])
		}

		maxRight[len(height)-1] = height[len(height)-1]
		for i := len(height) - 2; i >= 0; i-- {
			maxRight[i] = max(maxRight[i+1], height[i])
		}

		for i := 1; i < len(height)-1; i++ {
			ans += min(maxLeft[i], maxRight[i]) - height[i]
		}
		return ans
	*/
	left, right := 0, len(height)-1
	ans := 0
	leftMax, rightMax := 0, 0

	for left < right {
		if height[left] < height[right] {
			if height[left] >= leftMax {
				leftMax = height[left]
			} else {
				ans += leftMax - height[left]
			}
			left++
		} else {
			if height[right] >= rightMax {
				rightMax = height[right]
			} else {
				ans += rightMax - height[right]
			}
			right--
		}
	}
	return ans

}
