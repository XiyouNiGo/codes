package main

import "fmt"
// non-declaration statement outside function body
var v = 1

func main(){
    // 局部变量将被优先考虑
    // 初始化声明必须用在函数体内
    v := 2
    fmt.Println(v)
}

