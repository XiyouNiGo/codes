package main

import (
	"flag"
	"fmt"
	"go_simple_chatroom_server/server"
)

func main() {
	var server_ip string
	var server_port int
	flag.StringVar(&server_ip, "ip", "127.0.0.1", "ip of server")
	flag.IntVar(&server_port, "port", 8080, "port of server")
	flag.Parse()

	server := server.NewServer(server_ip, server_port)
	if err := server.Start(); err == nil {
		fmt.Printf("Server starts at at %v:%v.\n", server_ip, server_port)
	}
}
