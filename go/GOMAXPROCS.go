package main

import (
	"fmt"
	"runtime"
	"time"
)

func a() {
	for i := 1; i < 20; i++ {
		fmt.Println("A:", i)
	}
}

func b() {
	for i := 1; i < 20; i++ {
		fmt.Println("B:", i)
	}
}

func main() {
    // 对应m:n中的n
	runtime.GOMAXPROCS(2)
	go a()
	go b()
	time.Sleep(time.Second)
}


