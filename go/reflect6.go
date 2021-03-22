package main

import (
	"fmt"
	"reflect"
)

type S struct {
	s1 string
	s2 string
}

// TypeOf : 类型信息
// ValueOf : 值信息
func set_val(src interface{}, dst interface{}) bool {
	src_val := reflect.ValueOf(src)
	dst_val := reflect.ValueOf(dst)
	// 无法被设置通常代表其非指针
	if !src_val.CanSet() && !(src_val.Kind() == reflect.Ptr) {
		fmt.Printf("can't set %v\n", reflect.TypeOf(src).Kind())
		return false
	}

	// 到此处应是一个有效的Ptr
	src_elem := src_val.Elem()
	// 获取结构体成员
	// 对非Ptr调用Elem会造成panic
	var dst_elem reflect.Value
	if dst_val.Kind() == reflect.Ptr {
		dst_elem = reflect.ValueOf(dst).Elem()
	} else {
		dst_elem = reflect.ValueOf(dst)
	}

	switch src_elem.Kind() {
	case reflect.String:
		src_elem.SetString(reflect.ValueOf(dst).String())
		fmt.Printf("string : %v in func set_val\n", src_elem.String())
	case reflect.Int:
		src_elem.SetInt(reflect.ValueOf(dst).Int())
		fmt.Printf("int : %v in func set_val\n", src_elem.Int())
	case reflect.Struct:
		for i := 0; i < src_elem.NumField(); i++ {
			src_field := src_elem.Field(i)
			dst_field := dst_elem.Field(i)
			//fmt.Println("Kind of src_field is", src_field.Kind())	// Kind of src_field is string
			// 递归
			set_val(src_field, dst_field)	// can't set struct
		}
		fmt.Printf("struct : %v in func set_val\n", src_elem)
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
		s_struct S = S{"s1", "s2"}
	)

	fmt.Println(i, s, s_struct)
	// 无效的修改
	set_val(i, 666)
	set_val(s, "alter s")
	fmt.Println(i, s, s_struct)
	// 有效的修改
	set_val(&s, "alter s")
	set_val(&i, 666)
	set_val(&s_struct, S{"alter s1", "alter s2"})
	fmt.Println(i, s, s_struct)
}
