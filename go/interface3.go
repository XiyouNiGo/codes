package main

import "fmt"

type I interface {
	M()
}

type T struct {
	S string
}
// 即便接口内的具体值为 nil，方法仍然会被 nil 接收者调用 
func (t *T) M() {
	if t == nil {
		fmt.Println("<nil>")
		return
	}
	fmt.Println(t.S)
}

func main() {
	var i I

	var t *T
	i = t
	describe(i)
	i.M()

	i = &T{"hello"}
	describe(i)
	i.M()
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}

