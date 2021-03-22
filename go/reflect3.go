package main

import (
    "fmt"
    "reflect"
)

func reflect_val(i interface{}) {
    v := reflect.ValueOf(i)
    switch v.Kind() {
    case reflect.String:
        fmt.Printf("string : %v\n", v.String())
    case reflect.Int:
        fmt.Printf("int : %v\n", v.Int())
    default:
        fmt.Printf("unknow type\n")
    }
}

func main() {
    reflect_val("Hello reflect")
    reflect_val(1)
}

