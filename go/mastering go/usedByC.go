package main

import (
	"C"
	"fmt"
)

//PrintMessage
func PrintMessage() {
	fmt.Println("A Go function!")
}

func main() {
	// 生成共享库
	// go build -o usedByC.o -buildmode=c-shared usedByC.go
}
