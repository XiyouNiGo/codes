package main

import (
	"fmt"

	"k8s.io/apimachinery/pkg/api/resource"
)

func printQuantityAsGB(q resource.Quantity) {
	fmt.Printf("Values: %d\n", q.Value())
	fmt.Printf("%dGB\n", q.ScaledValue(resource.Giga))
}

func main() {
	printQuantityAsGB(resource.MustParse("4Gi"))
	printQuantityAsGB(resource.MustParse("85899345920"))
	printQuantityAsGB(resource.MustParse("1536Mi"))
	printQuantityAsGB(resource.MustParse("1500m"))
	printQuantityAsGB(resource.MustParse("80Gi"))
	printQuantityAsGB(resource.MustParse("80G"))
}
