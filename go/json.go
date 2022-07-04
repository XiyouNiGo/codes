package main

import (
	"encoding/json"
	"fmt"
)

type response struct {
	PageNumber int      `json:"page"` // json:"page"负责把page映射到结构体中的PageNumber字段上。
	Fruits     []string `json:"fruits"`
}

func testFunc() (res *response) {
	mapA := map[string]int{"apple": 5, "lettuce": 7}
	mapB, _ := json.Marshal(mapA)
	fmt.Println(string(mapB))
	str := `{"page": 1, "fruits": ["apple", "peach"]}`
	// res := response{}
	// var res *response
	res = &response{}
	if err := json.Unmarshal([]byte(str), res); err != nil {
		fmt.Println(err)
	}
	fmt.Println(res.PageNumber)
	return res
}

func main() {
	// testFunc()
	mapA := map[string]int{"apple": 5, "lettuce": 7}
	mapB, _ := json.Marshal(mapA)
	fmt.Println(string(mapB))
	str := `{"page": 1, "fruits": ["apple", "peach"]}`
	res := &response{}
	// var res *response
	if err := json.Unmarshal([]byte(str), res); err != nil {
		fmt.Println(err)
	}
	fmt.Println(res.PageNumber)
}
