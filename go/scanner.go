package main

import (
	"bufio"
	"fmt"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(strings.NewReader("hello world !"))
	// scanner.Split(bufio.ScanWords)
	scanner.Split(bufio.ScanRunes) // unicode
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}
}
