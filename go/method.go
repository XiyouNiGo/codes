package main

import "fmt"

type Student struct {
    name string
    sex string
    age int
}

func(s Student) assign_by_val() {
    s.name = "nigo"
    s.sex = "m"
    s.age = 20
}

func(s *Student) assign_by_ptr() {
    s.name = "nigo"
    s.sex = "m"
    s.age = 20
}

func main() {
    // 函数没有接受者，方法有接受者
    var s Student
    // 值传递和引用传递
    s.assign_by_val()
    fmt.Println(s)

    s.assign_by_ptr()
    fmt.Println(s)
}
