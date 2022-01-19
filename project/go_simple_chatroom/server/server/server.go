package server

import (
	"fmt"
	"io"
	"net"
	"sync"
	"time"
)

type Server struct {
	Ip   string
	Port int
	OnlineMap map[string]*User
	mapLock   sync.RWMutex
	BroadcastChannel chan string
}

func NewServer(ip string, port int) *Server {
	server := &Server{
		Ip:        ip,
		Port:      port,
		OnlineMap: make(map[string]*User),
		BroadcastChannel:   make(chan string),
	}
	return server
}

func (server *Server) BroadcastRoutine() {
	for {
		msg := <-server.BroadcastChannel
		server.mapLock.RLock()
		for _, cli := range server.OnlineMap {
			cli.C <- msg
		}
		server.mapLock.RUnlock()
	}
}

func (server *Server) BroadCast(user *User, msg string) {
	server.BroadcastChannel <- fmt.Sprintf("[%v]%v: %v", user.Addr, user.Name, msg)
}

func (server *Server) HandleConn(conn net.Conn) {
	user := NewUser(conn, server)
	defer close(user.C)
	defer conn.Close()

	user.Online()
	alive := make(chan struct{})

	// ReadRoutine
	go func() {
		buf := make([]byte, 4096)
		for {
			// TODO: handle half and sticky package
			n, err := conn.Read(buf)
			if n == 0 {
				user.Offline()
				return
			}
			if err != nil && err != io.EOF {
				fmt.Printf("conn.Read error: %v.\n", err)
				return
			}
			msg := string(buf[:n-1])
			if (len(msg) != 0) {
				user.HandleMessage(msg)
				alive <- struct{}{}
			}
		}
	}()

	// timeout control
	for {
		select {
		case <-alive:
			// do nothing to make next line retiming
		case <-time.After(time.Minute * 5):
			user.SendMsg("Too long time without operation, the connection is disconnected.")
		}
	}
}

func (server *Server) Start() error {
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", server.Ip, server.Port))
	if err != nil {
		fmt.Printf("net.Listen error: %v.\n", err)
		return err
	}
	defer listener.Close()

	go server.BroadcastRoutine()

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Printf("listener accept error: %v.\n", err)
			continue
		}
		go server.HandleConn(conn)
	}
}
