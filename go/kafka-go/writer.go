package main

import (
	"context"
	"log"

	kafka "github.com/segmentio/kafka-go"
)

func main() {
	// make a writer that produces to topic-A, using the least-bytes distribution
	w := &kafka.Writer{
		Addr:     kafka.TCP("localhost:9092"),
		Topic:    "topic-A",
		Balancer: &kafka.LeastBytes{},
	}

	err := w.WriteMessages(context.Background(),
		kafka.Message{
			Key:   []byte("Key-A"),
			Value: []byte("Hello World!"),
		},
		kafka.Message{
			Key:   []byte("Key-B"),
			Value: []byte("One!"),
		},
		kafka.Message{
			Key:   []byte("Key-C"),
			Value: []byte("Two!"),
		},
	)
	if err != nil {
		log.Fatal("failed to write messages:", err)
	}

	if err := w.Close(); err != nil {
		log.Fatal("failed to close writer:", err)
	}
}
