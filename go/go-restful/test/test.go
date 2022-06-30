package main

import (
	"log"
	"net/http"

	restful "github.com/emicklei/go-restful/v3"
)

func sayGet(request *restful.Request, response *restful.Response) {
	response.WriteEntity("Get")
}

func sayDel(request *restful.Request, response *restful.Response) {
	response.WriteEntity("Del")
}

func main() {
	ws := new(restful.WebService)
	ws.Path("/test")
	// regex
	ws.Route(ws.GET("/{*}").To(sayGet))
	ws.Route(ws.DELETE("/{*}").To(sayDel))
	restful.DefaultContainer.Add(ws)
	server := &http.Server{Addr: ":8080", Handler: restful.DefaultContainer}
	log.Fatal(server.ListenAndServe())
}
