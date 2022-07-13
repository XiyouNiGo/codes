package main

import (
	"bytes"
	"fmt"
	"io"
	"log"
	"net/http"
	"net/http/httptest"
	"net/http/httputil"
	"net/url"
)

func showRequest(r *http.Request) {
	fmt.Println("")
	fmt.Println("url:", r.URL)
	fmt.Println("path:", r.URL.Path)
	fmt.Println("scheme:", r.URL.Scheme)
	fmt.Println("header:", r.Header)
	// b, err := io.ReadAll(r.Body)
	// if err != nil {
	// 	log.Fatal(err)
	// }
	// fmt.Println("body:", string(b))
	fmt.Println("")
}

func newClusterReverseProxy(target *url.URL) *httputil.ReverseProxy {
	targetQuery := target.RawQuery
	director := func(req *http.Request) {
		req.URL.Scheme = target.Scheme
		req.URL.Host = target.Host
		req.URL.Path = target.Path
		req.URL.RawPath = target.RawPath
		if targetQuery == "" || req.URL.RawQuery == "" {
			req.URL.RawQuery = targetQuery + req.URL.RawQuery
		} else {
			req.URL.RawQuery = targetQuery + "&" + req.URL.RawQuery
		}
		if _, ok := req.Header["User-Agent"]; !ok {
			// explicitly disable User-Agent so it's not set to default value
			req.Header.Set("User-Agent", "")
		}
	}
	return &httputil.ReverseProxy{Director: director}
}

func main() {
	backendServer := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		showRequest(r)
		toWrite := "successfully reverse proxy"
		w.Write([]byte(toWrite))
	}))
	defer backendServer.Close()

	rpURL, err := url.Parse(backendServer.URL)
	fmt.Println(backendServer.URL)
	if err != nil {
		log.Fatal(err)
	}
	frontendProxy := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		newClusterReverseProxy(rpURL).ServeHTTP(w, r)
	}))
	defer frontendProxy.Close()

	req, err := http.NewRequest("GET", frontendProxy.URL, bytes.NewReader([]byte("wanna be proxyed correctly")))
	if err != nil {
		log.Fatal("new req failed", err)
	}
	req.Header.Add("Cookies", "test")
	req.Header.Add("Authorization", "test")

	client := &http.Client{}
	showRequest(req)
	resp, err := client.Do(req)
	if err != nil {
		log.Fatal("send failed", err)
	}

	defer resp.Body.Close()
	b, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%s", b)
}
