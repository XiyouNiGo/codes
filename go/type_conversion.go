package main

import "fmt"

func main() {
    i1 := 5
    i2 := 2
    // go不支持隐式转换
    fmt.Println(float64(i1) / float64(i2))
}

