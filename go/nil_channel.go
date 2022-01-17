package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Send(c chan int) {
	for {
		c <- rand.Intn(10)
	}
}

func Accumulate(c chan int) {
	sum := 0

	t := time.NewTimer(1 * time.Second)

	for {
		select {
		case input := <-c:
			sum = sum + input
		case <-t.C:
			c = nil // nil channel，相当于禁用上一条分支
			fmt.Println(sum)
		}
	}
}

func main() {
	c := make(chan int)
	go Accumulate(c)
	go Send(c)
	time.Sleep(3 * time.Second)
}
