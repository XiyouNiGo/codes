package main

import (
    "fmt"
    "time"
)

func main() {
    // time.Duration以纳秒为单位
    var sec time.Duration = time.Second
    now := time.Now()
    fmt.Println(now)
    now_add_sec := now.Add(sec)
    fmt.Println(now_add_sec)
}

