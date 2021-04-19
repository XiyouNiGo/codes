package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"path"
	"strconv"
	"syscall"
)

// 系统默认创建挂载的memory sudsystem hierarchy
const cgroup_memory_hierarchy_mount = "/sys/fs/cgroup/memory"

func main() {
	if os.Args[0] == "/proc/self/exe" {
		// 容器进程
		fmt.Println("container process: pid = %d\n", syscall.Getpid())
		cmd := exec.Command("sh", "-c", "stress --vm-bytes 200m --vm-keep -m 1")
		cmd.SysProcAttr = &syscall.SysProcAttr{}
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Run(); err != nil {
			fmt.Println(err)
			os.Exit(-1)
		}
	}

	cmd := exec.Command("/proc/self/exe")
	cmd.SysProcAttr = &syscall.SysProcAttr{
		Cloneflags: syscall.CLONE_NEWUTS | syscall.CLONE_NEWPID | syscall.CLONE_NEWNS,
	}
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	if err := cmd.Start(); err != nil {
		fmt.Println(err)
		os.Exit(-1)
	} else {
		fmt.Println("fork pid: %v", cmd.Process.Pid)
		// 创建cgroups
		// 目录:0755 文件:0644
		os.Mkdir(path.Join(cgroup_memory_hierarchy_mount, "test_memory_limit"), 0755)
		// 将容器进程加入cgroup
		ioutil.WriteFile(path.Join(cgroup_memory_hierarchy_mount, "test_memory_limit", "tasks"),
			[]byte(strconv.Itoa(cmd.Process.Pid)), 0644)
		// 限制容器进程
		ioutil.WriteFile(path.Join(cgroup_memory_hierarchy_mount, "test_memory_limit", "memory.limit_in_bytes"),
			[]byte("100m"), 0644)
		cmd.Wait()
	}
}
