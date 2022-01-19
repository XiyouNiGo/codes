package server

import (
	"net"
	"strings"
)

type User struct {
	Name string
	Addr string
	C    chan string
	conn net.Conn
	server *Server
}

func NewUser(conn net.Conn, server *Server) *User {
	addr := conn.RemoteAddr().String()

	user := &User{
		Name: addr,
		Addr: addr,
		C:    make(chan string),
		conn: conn,
		server: server,
	}

	go user.WriteRoutine()

	return user
}

func (server *User) Online() {
	server.server.mapLock.Lock()
	server.server.OnlineMap[server.Name] = server
	server.server.mapLock.Unlock()

	server.server.BroadCast(server, "Online now.")
}

func (server *User) Offline() {
	server.server.mapLock.Lock()
	delete(server.server.OnlineMap, server.Name)
	server.server.mapLock.Unlock()

	server.server.BroadCast(server, "Offline now.")
}

func (server *User) SendMsg(msg string) {
	server.conn.Write([]byte(msg))
}

func (server *User) HandleMessage(msg string) {
	if msg == "who" {
		server.server.mapLock.RLock()
		for _, user := range server.server.OnlineMap {
			onlineMsg := "[" + user.Addr + "]" + user.Name + ":" + "is online."
			server.SendMsg(onlineMsg)
		}
		server.server.mapLock.RUnlock()
	} else if len(msg) > 7 && msg[:7] == "rename|" {
		new_name := strings.Split(msg, "|")[1]
		_, ok := server.server.OnlineMap[new_name]
		if ok {
			server.SendMsg("The name is being used.")
		} else {
			server.server.mapLock.Lock()
			delete(server.server.OnlineMap, server.Name)
			server.server.OnlineMap[new_name] = server
			server.Name = new_name
			server.server.mapLock.Unlock()

			server.SendMsg("Update successfully.")
		}

	} else if len(msg) > 4 && msg[:3] == "to|" {
		peer_name := strings.Split(msg, "|")[1]
		if peer_name == "" {
			server.SendMsg("Wrong format of message.")
			return
		}

		server.server.mapLock.RLock()
		peer_user, ok := server.server.OnlineMap[peer_name]
		server.server.mapLock.RUnlock()
		if !ok {
			server.SendMsg("User name does not exist")
			return
		}

		content := strings.Split(msg, "|")[2]
		if content == "" {
			server.SendMsg("Empty message, please send again.")
			return
		}
		peer_user.SendMsg(server.Name + "say to you:" + content)
	} else {
		server.server.BroadCast(server, msg)
	}
}

func (server *User) WriteRoutine() {
	for {
		msg := <-server.C
		server.conn.Write([]byte(msg + "\n"))
	}
}
