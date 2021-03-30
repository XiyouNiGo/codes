package main

import (
	"flag"
	"fmt"
)

func print_usage() {
	fmt.Println("This tool is used to check abi compatibility, which developed by Xiyou LUG2.")
	flag.Usage()
}

func main() {
	enable_test := flag.Bool("test", false,
		"Use libsample.v1 and libsample.v2 as input files")
	output_filename := flag.String("o", "/dev/stdout",
		"Specified output file, default: stdout")

	flag.Parse()
	if enable_test == nil {
		panic("ccccccc")
	}
	print_usage()
	fmt.Println(enable_test, output_filename)
}

