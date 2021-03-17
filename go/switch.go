package main

import "fmt"

func main() {
    var flag int = 2

    switch flag {
    // 多个符合条件的值
    case 1, 2:
        fmt.Println("1, 2");
        // 默认break，可使用fallthrough
    case 0:
        fmt.Println("0")
    }

    // switch可以不放值
    switch {
    case flag == 1, flag == 2:
        fmt.Println("1, 2")
        // 强制执行下一条，不判断是否为true
        fallthrough
    case flag == 0:
        fmt.Println("fallthrough")
    }
}

