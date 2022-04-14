package main

import (
	"container/heap"
	"fmt"
	"math/rand"
	"time"
)

type minHeap []int

func (h minHeap) Len() int {
	return len(h)
}

func (h minHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h minHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *minHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *minHeap) Pop() interface{} {
	n := len(*h)
	res := (*h)[n-1]
	*h = (*h)[:n-1]
	return res
}

func main() {
	h := &minHeap{}
	heap.Init(h)
	rand.Seed(time.Now().Unix())
	for i := 0; i < 10; i++ {
		heap.Push(h, rand.Intn(20))
	}
	for i := 0; i < 10; i++ {
		fmt.Print(heap.Pop(h), " ")
	}
}
