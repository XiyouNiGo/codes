package main

import "fmt"

// 值传递
func alterArray(arr [10]int) {
	arr[0] = 1
}

func main() {
	var arr1 [10]int = [10]int{2: 1, 2}
	// arr2 := [...]int{5, 6, 7}
	alterArray(arr1)
	fmt.Println(arr1)
	// reslice
	slice := arr1[:]
	slice[1] = 2
	fmt.Println(arr1)
	fmt.Println(slice)
}
