package main

import (
	"fmt"
	"reflect"
)

func main() {
	type cat struct {
		Name string
		Type int `json:"type" id:"100"`
	}
	ins := cat{Name: "mimi", Type: 1}
	typeOfCat := reflect.TypeOf(ins)
	for i := 0; i < typeOfCat.NumField(); i++ {
		fieldType := typeOfCat.Field(i)
		fmt.Printf("name: %v  tag: '%v'\n", fieldType.Name, fieldType.Tag)
	}
	// 通过字段名查找字段
	if catType, ok := typeOfCat.FieldByName("Type"); ok {
		fmt.Println(catType.Tag.Get("json"), catType.Tag.Get("id"))
	}
}
