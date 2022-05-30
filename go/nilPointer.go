package main

import (
	"fmt"
)

func main() {
	testMap := map[string]*[]string{}
	arr := testMap["test"]
	*arr = append(*arr, "arr")
	fmt.Println(arr)
}
