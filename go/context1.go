package main

import (
	"fmt"
	"time"
	"sync"
	"context"
)

var wg sync.WaitGroup

func go_func(ctx context.Context, id int) {
	defer wg.Done()
	for {
		fmt.Println(id)
		time.Sleep(time.Second)
		select {
		case <- ctx.Done():
			return
		default:
		}
	}
}

func main() {
	ctx, cancle := context.WithCancel(context.Background())
	n := 5
	wg.Add(5)
	for i := 0; i < n; i++ {
		go go_func(ctx, i)
	}
	time.Sleep(time.Second * 2)
	cancle()
	wg.Wait()
}


