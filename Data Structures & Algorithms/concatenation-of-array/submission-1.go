func getConcatenation(nums []int) []int {
	n := len(nums) 
	ans := make([]int, n*2)

	j := 0
	for i := 0 ; i < n; i++ {
		ans[j] = nums[i]	
		if i == n-1 && j == i {
			i = -1
		}
		j++
	}

	return ans
}
