package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	stopCh := SetupSignalHandler()
	var wg sync.WaitGroup
	count := 3
	wg.Add(count)
	for i := 0; i < count; i++ {
		go func() {
			defer wg.Done()
			fmt.Println("goroutine %v: start")
			for {
				select {
				case <-stopCh:
					fmt.Println("goroutine %v: end")
					return
				default:
					fmt.Println("goroutine %v: I am working")
					time.Sleep(time.Second)
				}
			}
		}()
	}
	wg.Wait()
}
