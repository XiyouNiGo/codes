package main

import (
	"fmt"
	"strings"
)
 
func main() {
	demo := "Hello&Golang&Split."
	string_slice := strings.Split(demo, "&")
	for _, s := range string_slice {
		fmt.Println(s)
	}
 
	fmt.Println("result:",string_slice)
	fmt.Println("len:",len(string_slice))
	fmt.Println("cap:", cap(string_slice))
}