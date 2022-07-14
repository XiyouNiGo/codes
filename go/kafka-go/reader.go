package main

import (
	"context"
	"fmt"
	"log"

	kafka "github.com/segmentio/kafka-go"
)

func main() {
	// make a new reader that consumes from topic-A, partition 0, at offset 42
	r := kafka.NewReader(kafka.ReaderConfig{
		Brokers:   []string{"localhost:9092"},
		Topic:     "my-topic",
		Partition: 0,
		MinBytes:  10e3, // 10KB
		MaxBytes:  10e6, // 10MB
	})
	r.SetOffset(42)

	for {
		m, err := r.ReadMessage(context.Background())
		if err != nil {
			break
		}
		fmt.Printf("message at offset %d: %s = %s\n", m.Offset, string(m.Key), string(m.Value))
	}

	// 进程被SIGINT和SIGINT关闭时不会调用Close
	// 需要用signal.Notify来关闭程序
	if err := r.Close(); err != nil {
		log.Fatal("failed to close reader:", err)
	}
}
