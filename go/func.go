package main

import "fmt"

// 函数是一等公民
func swap(lhs, rhs int) (int, int) {
    return rhs, lhs
}

func main(){
    i1 := 1
    i2 := 2
    i1, i2 = swap(i1, i2)
    fmt.Println(i1, i2)
}

