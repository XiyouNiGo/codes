package main

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// bufio:封装了File，实现更多的功能
func main() {
	file, err := os.Open("text")
	if err != nil {
		fmt.Println("os.Open error:", err)
		return
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	for {
		line, err := reader.ReadString('\n')
		if err == io.EOF {
			if len(line) != 0 {
				fmt.Println(line)
			}
			fmt.Println("complete reading")
			break
		}
		if err != nil {
			fmt.Println("bufio.ReadString error:", err)
			return
		}
		fmt.Print(line)
	}
}

