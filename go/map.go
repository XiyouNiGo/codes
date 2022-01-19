package main

import "fmt"

func main() {
	i_map := make(map[int]int)
	i_map[1] = 2
	i_map[1] = 3
	i_map[666] = 667
	i_map[520] = 521

	for i := range i_map {
		fmt.Println(i, i_map[i])
	}

	i, status := i_map[1]
	fmt.Println(i, status)

	delete(i_map, 1)

	for i := range i_map {
		fmt.Println(i, i_map[i])
	}
}
