package main

import "fmt"
import "time"

func main() {
    go func() {
        time.Sleep(1 * time.Hour)
    }()
    c := make(chan int)
    go func() {
        for i := 0; i < 10; i = i + 1 {
            c <- i
        }
        //close(c)
    }()
    // for range处理channel
    for i := range c {
        fmt.Println(i)
    }
    fmt.Println("Finished")
}
