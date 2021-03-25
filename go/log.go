package main

import (
	"fmt"
	"log"
	"os"
)

// 不支持级别
func init() {
    log_file, err := os.OpenFile("try.log", os.O_CREATE, 0644)
    if err != nil {
        fmt.Println("os.OpenFile error :", err)
        return
    }
    log.SetOutput(log_file)
    log.SetFlags(log.Llongfile | log.Lmicroseconds)
    log.SetPrefix("I'm prefix")
}

func main() {
    log.Println("Hello log")
}

