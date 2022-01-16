package main

import (
	"errors"
	"fmt"
)

func main() {
 fmt.Println("Enter function main.")
 defer func(){
  fmt.Println("Enter defer function.")
  if p := recover(); p != nil {
   fmt.Printf("panic: %s\n", p)
  }
  fmt.Println("Exit defer function.")
 }()
 // 引发panic
 panic(errors.New("something wrong"))
 fmt.Println("Exit function main.")
}