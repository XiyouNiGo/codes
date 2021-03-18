package main

import "fmt"

func main(){
    // 关闭的channel中不但可以读取出已发送的数据，还可以不断的读取零值
    c := make(chan int, 10)
    c <- 1
    c <- 2
    close(c)
    fmt.Println(<-c) //1
    fmt.Println(<-c) //2
    fmt.Println(<-c) //0
    fmt.Println(<-c) //0
}

