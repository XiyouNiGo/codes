package main

import "fmt"

func main(){
    var i int
    switch i.(type) {
    case int:
        fmt.Println("type of i is int")
    }
    fmt.Println("Hello, World!")
}

