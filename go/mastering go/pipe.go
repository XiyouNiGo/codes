package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os/exec"
)

func main() {
	UnixPipe()
}

//将命令ps aux 的输出管道连接到grep pipe的输入管道
//并把输出管道里的数据全部写到输入管道里
func UnixPipe() {
	fmt.Println("Run command `ps aux | grep apipe`: ")
	cmd1 := exec.Command("ps", "aux")
	cmd2 := exec.Command("grep", "apipe")
	stdout1, err := cmd1.StdoutPipe() //cmd1上建立一个输出管道，为*io.Reader类型
	if err != nil {
		fmt.Printf("Error: Can not obtain the stdout pipe for command: %s", err)
		return
	}
	if err := cmd1.Start(); err != nil {
		fmt.Printf("Error: The command can not running: %s\n", err)
		return
	}
	outputBuf1 := bufio.NewReader(stdout1) //避免数据过多带来的困扰，使用带缓冲的读取器来获取输出管道中的数据
	stdin2, err := cmd2.StdinPipe()        //cmd2上建立一个输入管道
	if err != nil {
		fmt.Printf("Error: Can not obtain the stdin pipe for command: %s\n", err)
		return
	}
	outputBuf1.WriteTo(stdin2)  //将缓冲读取器里的输出管道数据写入输入管道里
	var outputBuf2 bytes.Buffer //获取cmd2的输出数据的字节缓冲器
	cmd2.Stdout = &outputBuf2   //将缓冲器赋值给cmd2的输出字段，这样cmd2的所有输出内容就会被写入到缓冲器中
	if err := cmd2.Start(); err != nil {
		fmt.Printf("Error: The command can not be startup: %s\n", err)
		return
	}
	err = stdin2.Close() //关闭cmd2的输入管道
	if err != nil {
		fmt.Printf("Error: Can not close the stdio pipe: %s\n", err)
		return
	}
	if err := cmd2.Wait(); err != nil { //为了获取cmd2的所有输出内容，调用Wait()方法一直阻塞到其所属所有命令执行完
		fmt.Printf("Error: Can not wait for the command: %s\n", err)
		return
	}
	fmt.Printf("%s\n", outputBuf2.Bytes()) //输出执行结果
}
