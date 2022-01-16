package main

import (
	"encoding/json"
	"fmt"
)

type response struct {
	PageNumber int      `json:"page"` // json:"page"负责把page映射到结构体中的PageNumber字段上。
	Fruits     []string `json:"fruits"`
}

func main() {
	mapA := map[string]int{"apple": 5, "lettuce": 7}
	mapB, _ := json.Marshal(mapA)
	fmt.Println(string(mapB))
	str := `{"page": 1, "fruits": ["apple", "peach"]}`
	res := response{}
	json.Unmarshal([]byte(str), &res)
	fmt.Println(res.PageNumber)
}
