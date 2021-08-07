package main

import "fmt"

func main() {
	var n, k int
	fmt.Scanln(&n, &k)
	temp, _ := intScanln(n)
	var temp_sum int
	result := make([]int, n+k+1, n+k+1)

	for i := 0; i < n-k+1; i++ {
		for j := i; j <= i+k; j++ {
			temp_sum += temp[j]
		}
		result[i] = temp_sum // number of cases of result is n+k+1
	}

	var largerNumber, temp_i int
	for _, element := range result {
		if element > temp_i {
			temp_i = element
			largerNumber = temp_i
		}
	}

	fmt.Println(largerNumber)
}

func intScanln(n int) ([]int, error) {
	x := make([]int, n)
	y := make([]interface{}, len(x))
	for i := range x {
		y[i] = &x[i]
	}
	n, err := fmt.Scanln(y...)
	x = x[:n]
	return x, err
}
