package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func main() {
	defer wg.Wait()
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			fmt.Println("Hello WaitGroup")
		}()
	}
}

