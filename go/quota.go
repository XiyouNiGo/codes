package main

import (
	"fmt"
	"reflect"
	"unsafe"
)

func main() {
	//String in double quotes
	x := "tit\nfor\ttat"
	fmt.Println("Priting String in Double Quotes:")
	fmt.Printf("x is: %s\n", x)

	//String in back quotes
	// 字符串字面量，原封不动输出
	y := `tit\nfor\ttat`
	fmt.Println("\nPriting String in Back Quotes:")
	fmt.Printf("y is: %s\n", y)

	//Declaring a byte with single quotes
	// rune（int32）和byte（uint8），默认rune
	var b byte = 'a'
	fmt.Println("\nPriting Byte:")
	//Print Size, Type and Character
	fmt.Printf("Size: %d\nType: %s\nCharacter: %c\n", unsafe.Sizeof(b), reflect.TypeOf(b), b)

	//Declaring a rune with single quotes
	r := '£'
	fmt.Println("\nPriting Rune:")
	//Print Size, Type, CodePoint and Character
	fmt.Printf("Size: %d\nType: %s\nUnicode CodePoint: %U\nCharacter: %c\n", unsafe.Sizeof(r), reflect.TypeOf(r), r, r)
	//Below will raise a compiler error - invalid character literal (more than one character)
	//r = 'ab'
}
