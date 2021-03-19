package main

import "fmt"

func main() {
    fmt.Println("c")
    defer func() {
        fmt.Println("d")
        if err := recover(); err != nil {
            fmt.Println(err)
        }
        fmt.Println("e")
    }()
    f()
    fmt.Println("f")
}

func f() {
    fmt.Println("a")
    panic("error")
    fmt.Println("b")
}
