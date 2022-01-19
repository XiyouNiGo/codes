package client

import (
	"fmt"
	"io"
	"net"
	"os"
)

type Client struct {
	Name string
	conn net.Conn
	flag int
}

func NewClient(server_ip string, server_port int) *Client {
	client := &Client{
		flag: 0,
	}

	conn, err := net.Dial("tcp", fmt.Sprintf("%s:%d", server_ip, server_port))
	if err != nil {
		fmt.Printf("net.Dial error: %v.\n", err)
		return nil
	}
	client.conn = conn

	return client
}

func (client *Client) ReadRoutine() {
	// Copy copies from src to dst until either EOF is reached on src or an error occurs
	if _, err := io.Copy(os.Stdout, client.conn); err != nil {
		fmt.Printf("io,Copy error: %v.\n", err)
	}
}

func (client *Client) menu() bool {
	var flag int

	fmt.Println("1. PublicChat")
	fmt.Println("2. PrivateChat")
	fmt.Println("3. UpdateName")
	fmt.Println("0. Exit")

	fmt.Scanln(&flag)

	if flag >= 0 && flag <= 3 {
		client.flag = flag
		return true
	} else {
		fmt.Println("Invalid input.")
		return false
	}

}

func (client *Client) SelectUsers() {
	// TODO: use json to convey data
	sendMsg := "who\n"
	_, err := client.conn.Write([]byte(sendMsg))
	if err != nil {
		fmt.Println("conn Write err:", err)
		return
	}
}

func (client *Client) PrivateChat() {
	var remoteName string
	var chatMsg string

	client.SelectUsers()
	fmt.Println("Please enter the chat object [username], exit exit:")
	fmt.Scanln(&remoteName)

	for remoteName != "exit" {
		fmt.Println("Please enter the message content, exit to exit:")
		fmt.Scanln(&chatMsg)

		for chatMsg != "exit" {
			if len(chatMsg) != 0 {
				sendMsg := "to|" + remoteName + "|" + chatMsg + "\n\n"
				_, err := client.conn.Write([]byte(sendMsg))
				if err != nil {
					fmt.Println("conn Write err:", err)
					break
				}
			}

			chatMsg = ""
			fmt.Println("Please enter the message content, exit to exit:")
			fmt.Scanln(&chatMsg)
		}

		client.SelectUsers()
		fmt.Println("Please enter the chat object [username], exit exit:")
		fmt.Scanln(&remoteName)
	}
}

func (client *Client) PublicChat() {
	var chatMsg string

	fmt.Println("Please enter the message content, exit to exit")
	fmt.Scanln(&chatMsg)

	for chatMsg != "exit" {
		if len(chatMsg) != 0 {
			sendMsg := chatMsg + "\n"
			_, err := client.conn.Write([]byte(sendMsg))
			if err != nil {
				fmt.Println("conn Write err:", err)
				break
			}
		}

		chatMsg = ""
		fmt.Println("Please enter the message content, exit to exit")
		fmt.Scanln(&chatMsg)
	}

}

func (client *Client) UpdateName() bool {

	fmt.Println("Please enter the new username")
	fmt.Scanln(&client.Name)

	sendMsg := "rename|" + client.Name + "\n"
	_, err := client.conn.Write([]byte(sendMsg))
	if err != nil {
		fmt.Println("conn.Write err:", err)
		return false
	}

	return true
}

func (client *Client) Run() {
	for client.flag != 0 {
		for client.menu() != true {
		}

		switch client.flag {
		case 1:
			client.PublicChat()
		case 2:
			client.PrivateChat()
		case 3:
			client.UpdateName()
		}
	}
}
