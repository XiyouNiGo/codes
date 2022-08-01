package main

import (
	"fmt"
	"sync"
)

func main() {
	stopCh := SetupSignalHandler()
	var wg sync.WaitGroup
	count := 3
	wg.Add(count)
	for i := 0; i < count; i++ {
		go func() {
			defer wg.Done()
			fmt.Println("goroutine %v: start", i)
			if _, ok := <-stopCh; !ok {
				fmt.Println("not ok")
			} else {
				fmt.Println("ok")
			}
			fmt.Println("goroutine %v: end", i)
		}()
	}
	wg.Wait()
}
