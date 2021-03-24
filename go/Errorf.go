package main

import "fmt"

func main() {
	o_err := fmt.Errorf("original error")
	// %w for wrapping error
	l_err := fmt.Errorf("lastest error : wrap (%w)", o_err)
	fmt.Println(o_err)
	fmt.Println(l_err)
}

