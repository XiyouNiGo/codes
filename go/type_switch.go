package main

import "fmt"

func main(){
    var i interface{}
    switch i.(type) {
    case int:
        fmt.Println("type of i is int")
    case nil:
        fmt.Println("type of i is <nil>")
    }
}

