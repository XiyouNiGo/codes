package main

import (
	"fmt"

	"k8s.io/apimachinery/pkg/labels"
)

func main() {
	selector, err := labels.Parse("tags.gaea.io/tag1=val1")
	if err != nil {
		fmt.Println(err)
	}
	label := map[string]string{
		"tags.gaea.io/tag1": "val1",
		"tags.gaea.io/tag2": "val2",
	}
	if !selector.Matches(labels.Set(label)) {
		fmt.Println("No match")
	} else {
		fmt.Println("Match")
	}
}
