package main

import (
	"fmt"
	"regexp"
)

func main() {
	match, _ := regexp.MatchString("^[a-z][a-z0-9-.]{0,5}[a-z0-9]$", "p123456e")
	fmt.Println(match)
}