package main

import (
	"fmt"
	"os"
)

func main() {
	pfile, _ := os.OpenFile("test", os.O_CREATE | os.O_RDWR, 0644)
	fmt.Fprintln(pfile, "Hello OpenFile")
}

