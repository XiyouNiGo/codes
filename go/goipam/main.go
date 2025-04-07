package main

import (
	"context"
	"fmt"
	"time"

	goipam "github.com/metal-stack/go-ipam"
)

func main() {
	// The background context
	bgCtx := context.Background()

	// Create a ipamer with in memory storage
	ipam := goipam.NewWithStorage(goipam.NewLocalFile(bgCtx, "/tmp/go-ipam.db"))

	// Optionally, we can pass around a context for a given namespace
	namespace := "tenant-a"
	err := ipam.CreateNamespace(bgCtx, namespace)
	if err != nil {
		panic(err)
	}
	ctx := goipam.NewContextWithNamespace(bgCtx, namespace)
	ctx, cancel := context.WithTimeout(ctx, 5*time.Second)
	defer cancel()

	// Create a prefix to manage some IPs
	prefix, err := ipam.NewPrefix(ctx, "192.168.0.0/24")
	if err != nil {
		panic(err)
	}

	for i := 0; i < 10; i++ {
		// Acquire and release an IP with this prefix
		ip, err := ipam.AcquireIP(ctx, prefix.Cidr)
		if err != nil {
			panic(err)
		}
		fmt.Printf("got IP: %s\n", ip.IP)
	}

	// prefix, err = ipam.ReleaseIP(ctx, ip)
	// if err != nil {
	// 	panic(err)
	// }
	// fmt.Printf("IP: %s released.\n", ip.IP)

	// Now a IPv6 Super Prefix with Child Prefixes
	prefix, err = ipam.NewPrefix(ctx, "2001:aabb::/48")
	if err != nil {
		panic(err)
	}

	cp1, err := ipam.AcquireChildPrefix(ctx, prefix.Cidr, 64)
	if err != nil {
		panic(err)
	}
	fmt.Printf("got Prefix: %s\n", cp1)

	cp2, err := ipam.AcquireChildPrefix(ctx, prefix.Cidr, 72)
	if err != nil {
		panic(err)
	}
	fmt.Printf("got Prefix: %s\n", cp2)
	ip21, err := ipam.AcquireIP(ctx, cp2.Cidr)
	if err != nil {
		panic(err)
	}
	fmt.Printf("got IP: %s\n", ip21.IP)
}
