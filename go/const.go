package main

import (
	"fmt"
	"unsafe"
)

func main() {
	const ci = 1
	// 常量表达式中，函数必须是内置函数
	const sz = unsafe.Sizeof(ci)
	// 常量可用作枚举
	// iota : 特殊常量，可理解为行索引
	const (
		a = iota
		b = 1000
		c
		d = iota // 恢复计数
		e
	)
	fmt.Println(ci, sz)
	fmt.Println(a, b, c)
	const s1 = "My String"
	const s2 string = "My String"
	fmt.Println(s1, s2)
}
