package main

import (
	"flag"
	"fmt"
	"io"
	"os"
	"os/exec"
)

const (
	READELF_PATH string = "binutils-2.20.1/binutils/"
	MAKE_PATH string = "./"
	COMPARE_PATH string = "./"
)

func print_introduce() {
	fmt.Println("This tool is used to check abi compatibility, which developed by Xiyou LUG2.")
	flag.Usage()
}

func run_cmd(output io.Writer, name string, arg ...string) {
	cmd := exec.Command(name, arg...)
	cmd.Stdout = output
	cmd.Stderr = output
}

func main() {
	enable_test := flag.Bool("test", false,
		"Use libsample.v1 and libsample.v2 as input files")
	enable_introduce := flag.Bool("i", false,
		"Introduce the tool")
	enable_run := flag.Bool("r", false, "Run this tool without make")
	output_filename := flag.String("o", "/dev/stdout",
		"Specified output file, default: stdout")
	flag.Parse()

	// No extra arguments are required for option i and test
	n_arg := flag.NArg()
	if (*enable_test == false) && (n_arg != 2) {
		panic("Incorrect number of parameters")
	} else if (*enable_test || *enable_introduce) && (n_arg != 0) {
		panic("Incorrect number of parameters")
	}

	// option i
	if *enable_introduce {
		print_introduce()
		return
	}

	// option test
	var input_filename1 string
	var input_filename2 string
	fmt.Println(input_filename1, input_filename2)
	if *enable_test {
		input_filename1 = "libsample.v1/test"
		input_filename2 = "libsample.v1/test"
	} else {
		input_filename1 = flag.Arg(0)
		input_filename2 = flag.Arg(1)
	}

	// no option r
	if !*enable_run {

	}

	output, err := os.Create(*output_filename)
	if err != nil {
		fmt.Println(err)
		return
	}

	// configure
	run_cmd(output, MAKE_PATH + "make")

	// Generate json files
	run_cmd(output, READELF_PATH + "readelf", "-h", input_filename1)
	run_cmd(output, READELF_PATH + "readelf", "-h", input_filename2)
	run_cmd(output, READELF_PATH + "readelf", "-S", input_filename1)
	run_cmd(output, READELF_PATH + "readelf", "-S", input_filename2)
	run_cmd(output, READELF_PATH + "readelf", "-l", input_filename1)
	run_cmd(output, READELF_PATH + "readelf", "-l", input_filename2)
	run_cmd(output, READELF_PATH + "readelf", "-r", input_filename1)
	run_cmd(output, READELF_PATH + "readelf", "-r", input_filename2)
	run_cmd(output, READELF_PATH + "readelf", "-x", input_filename1)
	run_cmd(output, READELF_PATH + "readelf", "-x", input_filename2)

	// compare and print
	run_cmd(output, COMPARE_PATH + "compare_elf_cJSON",
		"elf_header1.json", "elf_header2.json",
		"elf_S1.json", "elf_S2.json",
		"elf_l1.json", "elf_l2.json",
		"elf_Relo1.json", "elf_Relo2.json",
		"elf_x1.json", "elf_x2.json")
}

