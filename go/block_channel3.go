package main

import (
    "fmt"
)

func main() {
    c := make(chan string, 1)
    c <- "this is my data"
    fmt.Println(<-c)
}

