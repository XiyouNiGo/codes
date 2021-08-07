package main

import "fmt"

func main(){
    // 切片不需要说明长度
    slice1 := make([]int, 10, 20)
    for i := 0; i < len(slice1); i++ {
        slice1[i] = i
    }
	slice1 = append(slice1, 10);
	copy(slice1[5:], slice1[4:]);
	slice1[4] = 10;
    fmt.Println(slice1, len(slice1), cap(slice1))
    fmt.Println("slice1 :", slice1[:5])
    fmt.Println("slice1 :", slice1[5:])

    var slice2 []int
    // 为初始化前为nil
    fmt.Println(slice2 == nil)

    slice2 = append(slice2, 1, 2, 3)
    slice3 := make([]int, 5, 10)
    copy(slice3, slice2)
    fmt.Println(slice3)
}

