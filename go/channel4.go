package main

import "time"
import "fmt"

func main() {
    c1 := make(chan string, 1)
    go func() {
        time.Sleep(time.Second * 2)
        c1 <- "result 1"
    }()
    select {
    case res := <-c1:
        fmt.Println(res)
    // channel超时处理

    // time.After方法
    // 它返回一个类型为<-chan Time的单向的channel
    // 在指定的时间发送一个当前时间给返回的channel
    case <-time.After(time.Second * 1):
        fmt.Println("timeout 1")
    }
}
