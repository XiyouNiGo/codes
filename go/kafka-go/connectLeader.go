package main

import (
	"net"
	"strconv"

	kafka "github.com/segmentio/kafka-go"
)

func main() {
	// to connect to the kafka leader via an existing non-leader connection rather than using DialLeader
	conn, err := kafka.Dial("tcp", "localhost:9092")
	if err != nil {
		panic(err.Error())
	}
	defer conn.Close()
	controller, err := conn.Controller()
	if err != nil {
		panic(err.Error())
	}
	var connLeader *kafka.Conn
	connLeader, err = kafka.Dial("tcp", net.JoinHostPort(controller.Host, strconv.Itoa(controller.Port)))
	if err != nil {
		panic(err.Error())
	}
	defer connLeader.Close()
}
