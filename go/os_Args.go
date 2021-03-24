package main

import (
    "fmt"
    "os"
)

func main() {
    // string[]
    if len(os.Args) > 0 {
        for i, arg := range os.Args {
            fmt.Printf("arg%v : %v\n", i, arg)
        }
    }
}

