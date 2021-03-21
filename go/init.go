package main

import "fmt"

// global var -> init -> main
func init() {
    fmt.Println("main init")
}

func main() {
    fmt.Println("main")
}

