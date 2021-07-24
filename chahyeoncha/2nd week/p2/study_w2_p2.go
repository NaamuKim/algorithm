package main //proof to bf

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m, result int
	fmt.Scanf("%d %d", &n, &m)
	var cases [9][19]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			r := bufio.NewReader(os.Stdin)
			fmt.Fscan(r, &cases[i][j])
		}
	}
	for x := 0; x <= n; x++ {
		for y := 0; y <= n; y++ {
			flag := 0
			for w := 0; w < m; w++ {
				result_x := 0
				result_y := 0
				for z := 0; z < n; z++ {
					if cases[w][z] == x {
						result_x = z
					}
					if cases[w][z] == y {
						result_y = z
					}
				}
				if result_x < result_y {
					flag++
				}
			}
			if flag == m {
				// fmt.Println(cases[x][y])
				result++
			}
		}
	}
	fmt.Println(result - 1)
}
