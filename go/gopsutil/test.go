package main

import (
	"encoding/json"
	"fmt"

	ps "github.com/shirou/gopsutil/process"
	"github.com/shirou/gopsutil/v4/mem"
)

func main() {
	v, _ := mem.VirtualMemory()

	// almost every return value is a struct
	fmt.Printf("Total: %v, Free:%v, UsedPercent:%f%%\n", v.Total, v.Free, v.UsedPercent)

	// convert to JSON. String() is also implemented
	fmt.Println(v)

	procs, err := ps.Processes()
	if err != nil {
		panic(err)
	}
	b, err := json.Marshal(procs)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(b))
}
