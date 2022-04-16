package main

import (
	"fmt"
	"os"
	"reflect"
)

type a struct {
	X int
	Y float64
	Z string
}

type b struct {
	F int
	G int
	H string
	I float64
}

func main() {
	// 反射是指在程序运行期对程序本身进行访问和修改的能力
	// 程序在编译时变量被转换为内存地址，变量名不会被编译器写入到可执行部分，在运行程序时程序无法获取自身的信息
	// 支持反射的语言可以在程序编译期将变量的反射信息，如字段名称、类型信息、结构体信息等整合到可执行文件中
	x := 100
	// 通过 reflect.Elem() 方法获取这个指针指向的元素类型
	// 非指针或interface调用Elem会Panic
	xRefl := reflect.ValueOf(&x).Elem()
	// xRefl := reflect.ValueOf(x)
	xType := xRefl.Type()
	fmt.Printf("The type of x is %s.\n", xType)
	A := a{100, 200.12, "Struct a"}
	B := b{1, 2, "Struct b", -1.2}
	var r reflect.Value

	arguments := os.Args
	if len(arguments) == 1 {
		r = reflect.ValueOf(&A).Elem()
	} else {
		r = reflect.ValueOf(&B).Elem()
	}
	iType := r.Type()
	fmt.Printf("i Type: %s\n", iType)
	fmt.Printf("The %d fields of %s are:\n", r.NumField(), iType)

	for i := 0; i < r.NumField(); i++ {
		fmt.Printf("Field name: %s ", iType.Field(i).Name)
		fmt.Printf("with type: %s ", r.Field(i).Type())
		fmt.Printf("and value %v\n", r.Field(i).Interface())
	}
}
