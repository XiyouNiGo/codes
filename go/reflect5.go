package main

import (
    "fmt"
    "reflect"
)

func say(text string) {
    fmt.Println(text)
}

func Call(m map[string]interface{}, name string, params ... interface{}) (result []reflect.Value) {
    f := reflect.ValueOf(m[name])
    in := make([]reflect.Value, len(params))
    fmt.Println("len is", params)
    for k, param := range params {
        in[k] = reflect.ValueOf(param)
    }
    result = f.Call(in)
    return
}

func main() {
    var funcMap = make(map[string]interface{})
    funcMap["say"] = say
    Call(funcMap, "say", "hello")
}
