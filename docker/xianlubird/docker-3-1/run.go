package main

import (
	"os"

	"docker-3-1/container"

	log "github.com/Sirupsen/logrus"
)

func Run(tty bool, command string) {
	parent := container.NewParentProcess(tty, command)
	if err := parent.Start(); err != nil {
		log.Error(err)
	}
	// 每个容器都有对应的前台进程
	parent.Wait()
	os.Exit(-1)
}
