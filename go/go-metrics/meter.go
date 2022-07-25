package main

import (
	"log"
	"os"
	"time"

	"github.com/rcrowley/go-metrics"
)

func main() {

	m := metrics.NewMeter()
	metrics.Register("testMeter", m)
	m.Mark(1)

	go metrics.Log(metrics.DefaultRegistry,
		1*time.Second,
		log.New(os.Stdout, "metrics: ", log.Lmicroseconds))

	var j int64
	j = 1
	for true {
		time.Sleep(time.Second * 1)
		j++
		m.Mark(j)
	}
}
