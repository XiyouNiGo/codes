package main

import "fmt"

// 全局变量允许声明但不使用
var (               // usually used in global var
    i3 int = 4
    i4 int = 5
)

func main(){
    var i1, i2 int = 1, 2
    var s string;       // default value
    var bo bool
    var p *int          // nil
    var au_bo = true    // auto type
    non_var_i := 3      // non-var int 初始化声明，只能被用在函数体内
    _ = "abandoned val" // _是一个只写变量, 有时候不需要使用一个值
    fmt.Println(i1, i2, s, bo, p, au_bo, non_var_i)
}

