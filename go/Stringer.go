package main

import "fmt"

type Student struct {
    name string
    sex string
    age int
}

func (s Student) String() string {
    return fmt.Sprintf("name:%v, sex:%v, age:%v", s.name, s.sex, s.age)
}

func main() {
    s := Student{"nigo", "m", 20}
    fmt.Println(s)
}

