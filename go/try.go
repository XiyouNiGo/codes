package main

import "fmt"

func main() {
    const (
        a int = iota
        b
        c
        d
    )
    fmt.Println(a)
}

