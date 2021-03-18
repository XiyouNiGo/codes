package main

import "fmt"
import "Sqrt"

func main() {
    res, err := Sqrt(-1)
    if err != nil {
        fmt.Println(err)
    }
}

