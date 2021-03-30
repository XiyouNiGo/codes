package elf_script_go

import (
	"flag"
	"fmt"
	"io"
	"os"
	"os/exec"
	"sync"
)

const (
	MAIN_PATH string = "./"
	OPCODES_PATH = MAIN_PATH + "opcodes/"
	BFD_PATH = MAIN_PATH + "bfd/"
	BINUTILS_PATH string = MAIN_PATH + "binutils/"
	COMPARE_PATH string = MAIN_PATH + "./"

	WARN_CFLAGS string = "WARN_CFLAGS = -W -Wall -Wstrict-prototypes -Wmissing-prototypes"
)

func print_introduce() {
	fmt.Println("This tool is used to check abi compatibility, which developed by Xiyou-LUG2.")
	flag.Usage()
}

func run_cmd(output io.Writer, name string, arg ...string) {
	cmd := exec.Command(name, arg...)
	cmd.Stdout = output
	cmd.Stderr = output
	if err := cmd.Start(); err != nil {
		panic(err)
	}
	if err := cmd.Wait(); err != nil {
		panic(err)
	}
}

var wg sync.WaitGroup

func main() {
	enable_test := flag.Bool("test", false,
		"Use libsample.v1 and libsample.v2 as input files")
	enable_introduce := flag.Bool("i", false,
		"Introduce the tool")
	only_run := flag.Bool("r", false, "Run this tool without configuration")
	output_filename := flag.String("o", "/dev/stdout",
		"Specified output file, default: stdout")
	flag.Parse()

	// no extra arguments are required for option i and test
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

	// option r is disable
	if !*only_run {
		// configure
		run_cmd(os.Stdout, MAIN_PATH + "configure")
		// clumsy approach to avoid compilation error
		// -Werror is attributed
		run_cmd(os.Stdout, MAIN_PATH + "make")
		run_cmd(os.Stdout, "awk",
			"NR==241{$0=\"" + WARN_CFLAGS + "\"} {print>\"" + BINUTILS_PATH + "Makefile\"}",
			"Makefile")
		run_cmd(os.Stdout, MAIN_PATH + "make")
		run_cmd(os.Stdout, "awk",
			"NR==241{$0=\"" + WARN_CFLAGS + "\"} {print>\"" + BINUTILS_PATH + "Makefile\"}",
			"Makefile")
	}

	output, err := os.Create(*output_filename)
	if err != nil {
		fmt.Println(err)
		return
	}

	// generate json files
	wg.Add(2)
	go func() {
		defer wg.Done()
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-h", input_filename1)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-S", input_filename1)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-l", input_filename1)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-r", input_filename1)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-x", input_filename1)
	}()
	go func() {
		defer wg.Done()
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-h", input_filename2)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-S", input_filename2)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-l", input_filename2)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-r", input_filename2)
		run_cmd(os.Stdout, BINUTILS_PATH + "readelf", "-x", input_filename2)
	}()
	// multithreading improves response time
	wg.Wait()

	// compare and print
	run_cmd(output, COMPARE_PATH + "elf_main")
}

