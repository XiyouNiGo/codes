package main

import (
	"fmt"

	"k8s.io/apimachinery/pkg/api/resource"
)

func main() {
	memoryQuantity, _ := resource.ParseQuantity("2048Mi")
	fmt.Println(memoryQuantity.String())
	memoryQuantity.Format = resource.DecimalSI
	fmt.Println(memoryQuantity.String())
	memoryQuantity.Format = resource.BinarySI
	fmt.Println(memoryQuantity.String())
	memoryInGigabytes := memoryQuantity.Value() / (1024 * 1024 * 1024)
	fmt.Printf("Memory in gigabytes: %dG\n", memoryInGigabytes)
}
