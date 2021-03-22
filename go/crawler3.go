package main

import (
    "fmt"
    "github.com/jackdanger/collectlinks"
    "net/http"
)

func main() {
    url := "http://www.baidu.com/"
    queue := make(chan string)

    queue <- url
    fmt.Println("hhhh")
    for i := range queue {
        go download(i, queue)
    }
}

func download(url string, queue chan string) {
    client := &http.Client{}
    req, _ := http.NewRequest("GET", url, nil)
    req.Header.Set("User-Agent", "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)")

    resp, err := client.Do(req)
    if err != nil {
        fmt.Println("http get error", err)
        return
    }
    defer resp.Body.Close()

    links := collectlinks.All(resp.Body)
    for _, link := range links {
        fmt.Println("parse url", link)
        queue <- link
    }
}

