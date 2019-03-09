package main

func isPalindrome(x int) bool {
	if x < 0 || (x%10 == 0 && x != 0) {
		return false
	}

	revNum := 0
	for revNum < x {
		revNum = revNum*10 + x%10
		x /= 10
	}

	return (x == revNum || x == revNum/10)
}
