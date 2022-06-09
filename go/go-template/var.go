package main

import (
	"text/template"
	"os"
)

func main() {
	tx := template.Must(template.New("hh").Parse(
		`{{range $x := . -}}
		{{$y := 333}}
		{{- if (gt $x 33)}}{{println $x $y ($z := 444)}}{{- end}}
		{{- end}}
		`))
		s := []int{11, 22, 33, 44, 55}
		_ = tx.Execute(os.Stdout, s)
}