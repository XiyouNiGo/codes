package main

import (
	"fmt"

	kyaml "k8s.io/apimachinery/pkg/util/yaml"
)

func main() {
	s := `ovn.kubernetes.io/logical_switch: {{.LogicalSwitch}}
	ovn.kubernetes.io/ip_address: {{.IpAddress}}
	ovn.kubernetes.io/mac_address: {{.MacAddress}}`
	_, err := kyaml.ToJSON([]byte(s))
	if err != nil {
		fmt.Println(err)
	}
}
