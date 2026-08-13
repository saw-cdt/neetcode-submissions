import "reflect"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}	

	sOccurrences := map[byte]int{}
	tOccurrences := map[byte]int{}

	for i := range s {
		sOccurrences[s[i]]++
		tOccurrences[t[i]]++
	}

	return reflect.DeepEqual(sOccurrences, tOccurrences)
}
