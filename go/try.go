package main

import (
	"io"
	"os"
	"os/exec"
)

const (
	READELF_PATH string = "binutils-2.20.1/binutils/"
	COMPARE_PATH string = "./"
	WARN_CFLAGS string = "-W -Wall -Wstrict-prototypes -Wmissing-prototypes"
)

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

func main() {
    run_cmd(os.Stdout, "awk",
		"'NR==241{$0=\"-W -Wall -Wstrict-prototypes -Wmissing-prototypes\"} {print>\"Makefile\"}'",
		"Makefile")
}

