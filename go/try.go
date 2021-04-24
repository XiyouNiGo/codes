package main

import (
	"io"
	"os"
	"os/exec"
    log "github.com/sirupsen/logrus"
)

const (
    log_file string = "log_file"
)

func path_exists(path string) (bool, error) {
    _, err := os.Stat(path)
    if err == nil {
        return true, nil
    }
    if os.IsNotExist(err) {
        return false, nil
    }
    return false, nil
}

func create_file(path string) {
    flag, err := path_exists(path)
    if err != nil {
        log.Errorf("path_exists error:(%v)\n", err)
    }
    if !flag {
        if _, err := os.Create(log_file); err != nil {
            log.Errorf("Create error:(%v)\n", err)
        }
    }
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

func main() {
    create_file(log_file)

    if file, err := os.Open(log_file); err != nil {
        log.Errorf("Open error:(%v)")
    } else {
        run_cmd(file, "ls")
    }
}

