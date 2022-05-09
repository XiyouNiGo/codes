package main

import (
	"encoding/json"
	"fmt"
)

type coordinate struct {
	Lat *float64 `json:"latitude,omitempty"`
	Lng *float64 `json:"longitude,omitempty"`
}

// 赋值等于默认空值，不输出
// 解决：改成*
func main() {
	cData := `{
		"latitude": 0.0,
		"longitude": 0.0
	}`
	c := new(coordinate)
	json.Unmarshal([]byte(cData), &c)
	coordinateBytes, _ := json.MarshalIndent(c, "", "    ")
	fmt.Printf("%s\n", string(coordinateBytes))
}
