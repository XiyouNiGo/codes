package main

import (
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    fmt.Println("Hello, world")
    resp, err := http.Get("http://www.baidu.com/")
    if err != nil {
        fmt.Println("http get error", err)
        return
    }
    // 使用完必须关闭回复的主体
    defer resp.Body.close()
    body, err := ioutil.ReadAll(resp.Body)
    if err != nil {
        fmt.Println("read error", err)
        return
    }
    fmt.Println(string(body))
}

