package main

import "fmt"
import "time"

func main(){
    // 本质上是通道
    ticker := time.NewTicker(time.Millisecond * 500)
    go func() {
        for t := range ticker.C {
            fmt.Println("Tick at", t)
        }
    }()
}
