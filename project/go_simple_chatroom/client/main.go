package main

import (
	"flag"
	"fmt"
	"go_simple_chatroom_client/client"
)

func main() {
	var server_ip string
	var server_port int
	flag.StringVar(&server_ip, "ip", "127.0.0.1", "ip of server")
	flag.IntVar(&server_port, "port", 8080, "port of server")
	flag.Parse()

	client := client.NewClient(server_ip, server_port)
	if client == nil {
		fmt.Println("Failed to connect to the server.")
		return
	}
	
	go client.ReadRoutine()
	fmt.Println("Connect to the server successfully.")

	client.Run()
}
