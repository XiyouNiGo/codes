package main

import (
	"fmt"
	"reflect"
)

type Enum int

const (
	Zero Enum = 0
)

func main() {
	// Kind相当于一个大类，是Type实际的类型
	type cat struct {
	}
	typeOfCat := reflect.TypeOf(cat{})
	fmt.Println(typeOfCat.Name(), typeOfCat.Kind())
	typeOfA := reflect.TypeOf(Zero)
	fmt.Println(typeOfA.Name(), typeOfA.Kind())
}
