package main

import (
    "fmt"
	"reflect"
)

func reflectType(x interface{}) {
	v := reflect.TypeOf(x)
    fmt.Printf("Name:%v Kind:%v\n", v.Name(), v.Kind())
}

func main() {
	var a float32 = 3.14
	reflectType(a)
	var b int64 = 100
	reflectType(b)
}
