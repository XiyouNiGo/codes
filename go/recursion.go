package main

import "fmt"

func Factorial(n uint64) uint64 {
    if (n > 0) {
        return n * Factorial(n-1)
    }
    return 1
}

func main() {  
    var i int = 5
    fmt.Printf("Factorial(%d) : %d\n", i, Factorial(uint64(i)))
}
