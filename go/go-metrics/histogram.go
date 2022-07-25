package main

import (
	"log"
	"os"
	"time"

	"github.com/rcrowley/go-metrics"
)

func main() {
	s := metrics.NewExpDecaySample(1024, 0.015) // or metrics.NewUniformSample(1028)

	h := metrics.NewHistogram(s)

	metrics.Register("testHistogram", h)
	h.Update(1)

	go metrics.Log(metrics.DefaultRegistry,
		1*time.Second,
		log.New(os.Stdout, "metrics: ", log.Lmicroseconds))

	var j int64
	j = 1
	for true {
		time.Sleep(time.Second * 1)
		j++
		h.Update(j)
	}
}
