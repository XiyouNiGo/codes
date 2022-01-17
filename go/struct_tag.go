package main

import (
	"fmt"
	"reflect"
)

type Person struct {
	Name string `remark:"姓名"`
	Sex  string `remark:"性别"`
}

func PrintTag(arg interface{}) {
	elem := reflect.TypeOf(arg).Elem()
	n := elem.NumField()
	for i := 0; i < n; i++ {
		remark := elem.Field(i).Tag.Get("remark")
		fmt.Println("remark: ", remark)
	}
}

func main() {
	p := Person{"Nigo", "Man"}
	PrintTag(&p) // 必须传指针（为啥）
}
