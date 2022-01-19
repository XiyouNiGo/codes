package main

import (
	"context"
	"fmt"
	"time"
)

// select + context.WithTimeout实现超时控制
func main() {
	done := make(chan struct{})

	go func() {
		fmt.Println("Do something...")
		time.Sleep(2 * time.Second)
		done <- struct{}{}
	}()

	timeout, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	select {
	case <- done:
		fmt.Println("Done!")
	case <- timeout.Done():
		fmt.Println("Timeout!")
	}
}