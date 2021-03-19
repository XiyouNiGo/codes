package main

import "fmt"

func main() {
	var i interface{} = "hello"

	s := i.(string)
	fmt.Println(s)

	s, ok := i.(string)
	fmt.Println(s, ok)

	f, ok := i.(float64)    // no panic
	fmt.Println(f, ok)

	f = i.(float64) // panic
	fmt.Println(f)
}

