package main

import "fmt"

func main() {
    // 加入延迟调用栈
    defer fmt.Println("1")
    defer fmt.Println("2")
    defer fmt.Println("3")
    // 函数退出时执行
    // 可被用于资源管理
    fmt.Println("main will exit")
}

