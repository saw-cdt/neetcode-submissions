func hasDuplicate(nums []int) bool {
    occurrences := map[int]int{}     
    for _, number:= range nums {
        if _, ok := occurrences[number]; ok {
            return true
        } else {
            occurrences[number] = 1
        }
    }
    return false
}