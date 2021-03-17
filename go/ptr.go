package main

import "fmt"

func main(){
    var i int = 10
    var ptr *int = &i
    fmt.Println("type of i is %T", i)
    fmt.Println("i is %d", i)
    fmt.Println("*ptr = 20")
    *ptr = 20
    fmt.Println("i is %d", i)
}

