package main

import (
	"fmt"
	"time"
	"sync"
)

var wg sync.WaitGroup

func go_func(exit_chan <-chan struct{}, id int) {
	defer wg.Done()
	for {
		fmt.Println(id)
		time.Sleep(time.Second)
		select {
		case <- exit_chan:
			return
		default:
		}
	}
}

func main() {
	n := 5
	wg.Add(5)
	exit_chan := make(chan struct{})
	for i := 0; i < n; i++ {
		go go_func(exit_chan, i)
	}
	time.Sleep(time.Second * 2)
	exit_chan <- struct{}{}
	wg.Wait()
}

