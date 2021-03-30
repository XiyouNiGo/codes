package main

import (
    "fmt"
    "flag"
)

// flag用于开发命令行工具
func main() {
    s := flag.String("s", "string", "flag s")
    i := flag.Int("i", 666, "flag i")
    b := flag.Bool("b", false, "flag bool")
    flag.Parse()
    fmt.Println(*s, *i, *b)
}

