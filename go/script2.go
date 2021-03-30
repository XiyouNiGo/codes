package main

import (
    "fmt"
    "os/exec"
)

func main() {
    cmd := exec.Command("go", "run", "try.go")
    out, err := cmd.CombinedOutput()
    fmt.Println("Here")
    if err != nil {
        fmt.Println(err)
    }
    fmt.Println(string(out))
}
