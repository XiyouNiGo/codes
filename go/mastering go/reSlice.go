package main

import (
	"fmt"
)

func main() {
	s := make([]int, 5)
	reSlice := s[1:3]
	fmt.Println(s)
	fmt.Println(reSlice)
	reSlice[0] = -1
	reSlice[1] = -2
	// reslice指向同一片地址
	fmt.Println(s)
	fmt.Println(reSlice)
}
