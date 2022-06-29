package main

import (
	"fmt"
	"strings"
)

func main() {
	cidr := "2001:db8:3c4d:1:2:3:4/48"
	ipv4 := "10.144.250.65"
	fmt.Println(strings.Split(cidr, ":")[:5])
	fmt.Println(append(strings.Split(cidr, ":")[:5], strings.Split(ipv4, ".")[1:]...))
	fmt.Println(strings.Join(append(strings.Split(cidr, ":")[:5], strings.Split(ipv4, ".")[1:]...), ":"))
}