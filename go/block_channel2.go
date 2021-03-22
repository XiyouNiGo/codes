package main

import (
    "fmt"
)

func main() {
    c := make(chan string, 1)
    defer fmt.Println("over")
    c <- "this is my data"
    c <- "this is my data"
}

