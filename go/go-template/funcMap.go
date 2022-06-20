package main

import (
	"os"
	"text/template"
)

func SayHello() string {
	return "hello world"
}

func SayYouName(name string) string {
	return "my name is : " + name
}

func main() {
	funcMap := template.FuncMap{
		"SayHello":   SayHello,
		"SayYouName": SayYouName,
	}
	name := "boss"
	// 在template中使用函数
	tmpl, err := template.New("test").Funcs(funcMap).Parse("{{SayHello}}\n{{SayYouName .}}\n")
	if err != nil {
		panic(err)
	}
	err = tmpl.Execute(os.Stdout, name)
	if err != nil {
		panic(err)
	}
}
