func removeElement(nums []int, val int) int {
	var expectedNums []int
	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			nums[i] = -1
		} else {
			expectedNums = append(expectedNums, nums[i])
		}
	}

	for i:=0; i < len(expectedNums); i++ {
		nums[i] = expectedNums[i]
	}

	return len(expectedNums)
}
