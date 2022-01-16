package main

import (
	"fmt"
	"os"
)

func main() {
	f, err := os.Open("/home/nigo/go");
	if (err != nil) {
		fmt.Println(err);
	}
	result, _ := f.Readdirnames(0);
	fmt.Println(result);
}