package main

import (
	"encoding/json"
	"fmt"
	"log"
	"os"

	"github.com/vishvananda/netlink"
)

func showRoutes(routes []netlink.Route) {
	bytes, err := json.Marshal(routes)
	if err != nil {
		panic("marshal failed")
	}
	fmt.Println(string(bytes))
}

func main() {
	args := os.Args
	if len(args) != 2 {
		log.Fatalf("Usage: %v <nic-name>\n", args[0])
	}
	name := args[1]
	link, err := netlink.LinkByName(name)
	if err != nil {
		log.Fatalf("failed to get link by %s", name)
	}

	routes, err := netlink.RouteList(link, netlink.FAMILY_V4)
	if err != nil {
		log.Fatalf("failed to get routes v4 for %s", name)
	}
	showRoutes(routes)

	routes6, err := netlink.RouteList(link, netlink.FAMILY_V6)
	if err != nil {
		log.Fatalf("failed to get routes v6 for %s", name)
	}
	showRoutes(routes6)
}
