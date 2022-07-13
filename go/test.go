package main

import (
	"encoding/json"
	"fmt"
	"strings"

	"github.com/go-sql-driver/mysql"
)

const (
	ErrDuplicateEntryCode = 1062
)

func MysqlErrCode(err error) int {
	mysqlErr, ok := err.(*mysql.MySQLError)
	if !ok {
		return 0
	}
	return int(mysqlErr.Number)
}

func main() {
	// sqlError := mysql.MySQLError{
	// 	Number:  1062,
	// 	Message: "Duplicate entry for key 'model_restag.uniq_project_resource'",
	// }
	// var mysqlErr *mysql.MySQLError
	// if errors.As(errors.New(sqlError.Error()), &mysqlErr) && mysqlErr.Number == 1062 {
	// 	fmt.Println("here")
	// }
	// fmt.Println(mysql.ErrBusyBuffer)
	// fmt.Println(errors.New(sqlError.Error()))
	// fmt.Println(strings.Contains("Error 1062: Duplicate entry '114-0-vm-66d943b4-22d0-4d5e-ac07-429114cff43e-a' for key 'model_restag.uniq_project_resource'", "1062"))
	s := "/gapis/test"
	// index := strings.Index(s, "gapis/")
	index := strings.Index(s, "gapis/")
	fmt.Println(index)
	fmt.Println(s[index+len("gapis/"):])
	// fmt.Println(s[index:])
	s1, _ := json.Marshal("devbox-vm-template")
	fmt.Println(string(s1))
}
