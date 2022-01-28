package main

import (
	"os"

	"github.com/sirupsen/logrus"
)

func main() {
	// 创建logger实例
	file, _ := os.OpenFile("nigo_logrus.log", os.O_CREATE|os.O_TRUNC, 0666)
	logger := logrus.New()
	logger.Out = file
	logger.WithFields(logrus.Fields{
		"animal": "walrus",
	}).Info("A walrus appears")
}
