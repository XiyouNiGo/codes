package main

import (
	"fmt"

	"github.com/google/uuid"
)

func main() {
	for i := 0; i < 10; i++ {
		// hardly panic
		id := uuid.New()
		fmt.Printf("%s %s\n", id, id.Version().String())
	}
	fmt.Println("len: ", len("947b63c5-3975-4a9a-b307-5210b77e80cf"))
	for i := 0; i < 10; i++ {
		id2, err := uuid.NewRandom()
		if err != nil {
			fmt.Printf("%v\n", err)
		}
		fmt.Printf("%s %s\n", id2, id2.Version().String())
	}
}
