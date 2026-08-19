func replaceElements(arr []int) []int {
	max := arr[len(arr)-1]
	for i := len(arr)-1; i > 0; i-- {
		aux := max
		if arr[i-1] > max {
			max = arr[i-1]
		}
		arr[i-1] = aux		
	}		
	arr[len(arr)-1] = -1
	return arr
}
