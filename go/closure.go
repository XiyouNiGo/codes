package main

import "fmt"

func main() {
	n := 0
    // Golang的函数只能返回匿名函数
    // 闭包使匿名函数可以直接引用外部变量
	f := func() int {
		n += 1
		return n
	}
	fmt.Println(f())
	fmt.Println(f())
}
