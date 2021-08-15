package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var N int
	temp := bufio.NewReader(os.Stdin)
	fmt.Fscan(temp, &N)

	array := make([][]int, N)
	for a := range array {
		array[a] = make([]int, N)
	}
	for j := 0; j < N; j++ {
		for i := 0; i < N; i++ {
			fmt.Scanf("%d", &array[i][j])
		}
	} // empty slice(=array) is filled to "0"

	move_list := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &move_list[i])
	}
	basket := make([]int, N)
	move(move_list, array, basket, N)
	answer := 0
	clear(basket, N, answer)
	fmt.Println(answer)
}

func move(move []int, from [][]int, target []int, N int) {
	for i := 0; i < N; i++ {
		if move[i] == 0 {
			i = i + 1
			continue
		}
		for j := 0; j < N; j++ {
			if from[move[i]][j] == 0 {
				j = j + 1
				continue
			}
			target[move[i]] = from[move[i]][j]
			from[move[i]][j] = 0
		}
	}

}

func clear(basket []int, N int, answer int) {
	for i := 1; i < N; i++ {
		if basket[i-1] == basket[i] {
			for j := i; j < N; j++ {
				basket[j-1] = basket[j+1]
				answer++
			}

		}
	}
}
