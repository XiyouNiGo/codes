package main

import "fmt"

type Base struct {
    base_name string
}

func (b *Base) print_base() {
    fmt.Println(b.base_name)
}


type Derive struct {
    Base    // 匿名结构体
    derive_name string
}

func (d *Derive) print_derive() {
    // 可直接访问匿名结构体的成员和方法
    d.print_base()
    fmt.Println(d.derive_name)
}

func main() {
    b := Base{"base"}
    b.print_base()

    d := Derive{b, "derive"}
    d.print_derive()
}

