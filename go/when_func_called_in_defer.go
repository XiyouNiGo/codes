package main

import "fmt"

func deferFunc() func() {
	fmt.Println("deferFunc called.")
	return func() {
		fmt.Println("lastFunc called.")
	}
}

func main() {
	fmt.Println("First.")
	// deferFunc在此处会被调用来获取那个函数指针
	// 而不是说，这一整句放到最后执行
	defer deferFunc()()
	fmt.Println("Second.")
}
