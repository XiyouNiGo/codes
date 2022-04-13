package main

import (
	"fmt"
	"os"
	"path/filepath"
	"time"
)

func main() {
	var myTime string
	if len(os.Args) != 2 {
		fmt.Printf("Usage: %s string\n",
			filepath.Base(os.Args[0]))
		os.Exit(0)
	}
	myTime = os.Args[1]
	// 15: hour
	// 04: minute
	// 05: second
	d, err := time.Parse("15:04", myTime)
	if err == nil {
		fmt.Println("Full", d)
		fmt.Println("Time", d.Hour(), d.Minute())
	} else {
		fmt.Println(err)
	}
}
