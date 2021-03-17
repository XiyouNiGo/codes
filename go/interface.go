package main

import (
    "fmt"
    "reflect"
)

func main() {
    // interface变量可以存储任何类型
    var  I interface{}
    I = 1
    fmt.Println(reflect.TypeOf(I).Kind().String())
    I = 1.3
    fmt.Println(reflect.TypeOf(I).Kind().String())
    I = true
    fmt.Println(reflect.TypeOf(I).Kind().String())
}


