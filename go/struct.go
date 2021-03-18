package main

import "fmt"

type Student struct {
    name string
    sex string
    age int
}

func main(){
    s1 := Student{"nigo", "m", 20}
    s2 := Student{name:"lj", sex:"f", age:20}
    fmt.Println(s1, s2)
    fmt.Println(s1.name, s1.sex, s1.age)
    ps2 := &s2
    // 指针也用.
    fmt.Println(ps2.name, ps2.sex, ps2.age)
}

