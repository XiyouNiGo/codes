package main

import (
	"fmt"
	"time"
)

// select + time.After实现超时控制
func main() {
	done := make(chan struct{})

	go func() {
		fmt.Println("Do something...")
		time.Sleep(2 * time.Second)
		done <- struct{}{}
	}()

	select {
	case <- done:
		fmt.Println("Done!")
	case <- time.After(time.Second):
		fmt.Println("Timeout!")
	}
}