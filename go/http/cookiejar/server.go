package main

import (
	"fmt"
	"net/http"
	"strconv"
	"time"
)

var i int

func receiveReq(w http.ResponseWriter, r *http.Request) {
	// i++
	fmt.Println(r.Cookies())
	tNow := time.Now()
	cookie := &http.Cookie{
		Name:    "Cookie",
		Value:   strconv.Itoa(i),
		Expires: tNow.AddDate(1, 0, i),
	}
	http.SetCookie(w, cookie)
	w.Write(([]byte("your cookie has been received")))
}

func main() {
	http.HandleFunc("/test", receiveReq)
	err := http.ListenAndServe("127.0.0.1:8080", nil)
	if err != nil {
		fmt.Println("ListenAndServe error: ", err)
	}
}
