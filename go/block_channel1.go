package main

import (
    "fmt"
)

func main() {
    c := make(chan string)
    defer fmt.Println("over")
    c <- "this is my data"
    // fatal error: all goroutines are asleep - deadlock!
}

