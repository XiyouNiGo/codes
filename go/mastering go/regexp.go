package main

import (
	"bytes"
	"fmt"
	"regexp"
)

func main() {
	match, _ := regexp.MatchString("p([a-z]+)ch", "peach")
	fmt.Println(match)

	r, _ := regexp.Compile("p([a-z]+)ch")
	fmt.Println(r.MatchString("peach"))
	// 查找第一次匹配的索引
	fmt.Println(r.FindString("peach punch"))
	fmt.Println(r.FindStringIndex("peach punch"))
	// Submatch返回完全匹配和局部匹配的字符串（其实就是捕获）
	fmt.Println(r.FindStringSubmatch("peach punch"))
	fmt.Println(r.FindStringSubmatchIndex("peach punch"))
	// 返回所有的匹配项
	fmt.Println(r.FindAllString("peach punch pinch", -1))
	fmt.Println(r.FindAllStringSubmatchIndex(
		"peach punch pinch", -1))
	// n: 限制正则匹配次数
	fmt.Println(r.FindAllString("peach punch pinch", 2))
	fmt.Println(r.Match([]byte("peach")))
	//创建正则表示式常量时，可以使用 Compile 的变体MustCompile 。因为 Compile 返回两个值，不能用语常量。
	r = regexp.MustCompile("p([a-z]+)ch")
	fmt.Println(r)
	// 替换字符串
	fmt.Println(r.ReplaceAllString("a peach", "<fruit>"))
	in := []byte("a peach")
	// 用Func（其实是引用类型）替换字符串
	out := r.ReplaceAllFunc(in, bytes.ToUpper)
	fmt.Println(string(out))
}
