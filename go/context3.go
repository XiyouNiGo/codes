package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup

func Worker(ctx context.Context) {
LOOP:
	for {
		fmt.Println("Do something...")
		time.Sleep(time.Millisecond * 10)
		select {
		case <-ctx.Done():
			break LOOP
		default:
			fmt.Println("Do something...")
		}
	}
	fmt.Println("Done!")
	wg.Done()
}

func main() {
	ctx, cancel := context.WithTimeout(context.Background(), time.Millisecond*50)
	defer cancel()

	wg.Add(1)
	go Worker(ctx)
	time.Sleep(time.Second * 5)
	wg.Wait()
}
