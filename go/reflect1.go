package main

import (
    "fmt"
	"reflect"
)

// 反射是指在程序运行期对程序本身进行访问和修改的能力
func reflectType(x interface{}) {
	v := reflect.TypeOf(x)  // TypeOf返回的是接口，内含String方法
	fmt.Printf("type:%v\n", v)
}

func main() {
	var a float32 = 3.14
	reflectType(a) // type:float32
	var b int64 = 100
	reflectType(b) // type:int64
}
