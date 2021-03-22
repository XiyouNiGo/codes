package main

import (
	"fmt"
	"reflect"
)

// TypeOf : 类型信息
// ValueOf : 值信息
func set_val(src interface{}, dst interface{}) bool {
	src_val := reflect.ValueOf(src)
	// 无法被设置通常代表其非指针
	if !src_val.CanSet() && !(src_val.Kind() == reflect.Ptr) {
		fmt.Printf("can't set %v\n", reflect.TypeOf(src).Kind())
		return false
	}

	// 到此处应是一个有效的Ptr
	src_elem := src_val.Elem()
	switch src_elem.Kind() {
	case reflect.String:
		src_elem.SetString(reflect.ValueOf(dst).String())
		fmt.Printf("string : %v in func set_val\n", src_elem.String())
	case reflect.Int:
		src_elem.SetInt(reflect.ValueOf(dst).Int())
		fmt.Printf("int : %v in func set_val\n", src_elem.Int())
	default:
		fmt.Printf("unknow type : in func set_val\n")
	}
	return true
}

// 修改反射对象
func main() {
	var (
		s string = "s"
		i int = 0
	)
	fmt.Println(i, s)
	// 无效的修改
	set_val(i, 666)
	set_val(s, "alter s")
	fmt.Println(i, s)
	// 有效的修改
	set_val(&s, "alter s")
	set_val(&i, 666)
	fmt.Println(i, s)
}
