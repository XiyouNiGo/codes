package main

import (
	"os"

	log "github.com/sirupsen/logrus"
)

func init() {
	// default: log.TextFormatter{}
	log.SetFormatter(&log.JSONFormatter{})
	// io.Writer
	log.SetOutput(os.Stdout)
	log.SetLevel(log.InfoLevel)
}

func main() {
	log.WithFields(log.Fields{
		"animal": "walrus",
	}).Info("A walrus appears")
}
