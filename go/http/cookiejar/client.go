package main

import (
	"fmt"
	"net/http"
	"net/http/cookiejar"
)

func main() {
	jar, _ := cookiejar.New(nil)
	client := http.Client{
		Jar: jar,
	}
	url := "http://127.0.0.1:8080/test"
	req, _ := http.NewRequest("GET", url, nil)
	for i := 0; i < 5; i++ {
		client.Do(req)
		fmt.Println("Cookie: ", req.Cookies())
	}
}
