package main

import (
	"fmt"
	"net"
	"strconv"

	kafka "github.com/segmentio/kafka-go"
)

func main() {
	// to create topics when auto.create.topics.enable='false'
	topic := "my-topic"

	// 可能不是leader
	conn, err := kafka.Dial("tcp", "localhost:9092")
	if err != nil {
		panic(err.Error())
	}
	defer conn.Close()

	controller, err := conn.Controller()
	if err != nil {
		panic(err.Error())
	}
	var controllerConn *kafka.Conn
	address := net.JoinHostPort(controller.Host, strconv.Itoa(controller.Port))
	fmt.Println("address: ", address)
	controllerConn, err = kafka.Dial("tcp", address)
	if err != nil {
		panic(err.Error())
	}
	defer controllerConn.Close()

	topicConfigs := []kafka.TopicConfig{
		{
			Topic:             topic,
			NumPartitions:     1,
			ReplicationFactor: 1,
		},
	}

	err = controllerConn.CreateTopics(topicConfigs...)
	if err != nil {
		panic(err.Error())
	}
}
