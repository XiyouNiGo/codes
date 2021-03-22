package main

import (
    "fmt"
)

func main() {
    c := make(chan string)
    go func() {
        c <- "this is my data"
    }()
    fmt.Println(<-c)
}

