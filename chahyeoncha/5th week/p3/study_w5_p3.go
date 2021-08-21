package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	chair := make([]int, n+1)
	attacked := make([]int, n+1)
	for i := 1; i <= n; i++ {
		chair[i] = i
	}
	temp := make([]int, len(chair))
	copy(temp, chair)
	for j := 1; j <= n; j++ {
		if n-j >= k {
			attacked[j] = temp[k]
			remove_element(temp, k)
			temp = append(temp[k:], temp[:k]...)
		} else {
			for x := 0; x < k; x++ {
				attacked[j] = chair[x]
			}
		}
	}
	fmt.Println("<%d"attacked[1:])
}
func remove_element(src []int, k int) []int {
	return append(src[:k], src[k+1:]...)
}
