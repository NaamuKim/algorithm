package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	chair := make([]int, n)
	person := make([]int, n)
	attacked := make([]int, n)
	for i := 0; i < n; i++ {
		chair[i] = i + 1
		person[i] = i + 1
	}
	for j := 0; j < n; j++ {
		attacked[j] = chair[k-1]
		if attacked[j]+k == n {
			chair[k-1] = chair[attacked[j]+k-1]
		} else if attacked[j]+k < n {
			chair[k-1] = chair[attacked[j]+k-1]
		}
	}
	fmt.Printf("%d", attacked)
}
