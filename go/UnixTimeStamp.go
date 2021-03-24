package main

import (
    "fmt"
    "time"
)

// 时间戳是1970.1.1至当前时间的总毫秒数
func print_timestamp() {
    now := time.Now()
    // int64
    unix_timestamp := now.Unix()
    nano_unix_timestamp := now.UnixNano()
    fmt.Println(unix_timestamp, nano_unix_timestamp)
}

func main() {
    print_timestamp()
}

