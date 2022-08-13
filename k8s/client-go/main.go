package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"

	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"

	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	"k8s.io/klog/v2"
)

func main() {
	var kubeConfig string
	if home := homedir.HomeDir(); home != "" {
		flag.StringVar(&kubeConfig, "kubeconfig", filepath.Join(home, ".kube", "config"), "Path of kubeconfig file")
	} else {
		flag.StringVar(&kubeConfig, "kubeconfig", "", "Path of kubeconfig file")
	}
	flag.Parse()
	// Build k8s config
	config, err := clientcmd.BuildConfigFromFlags("", kubeConfig)
	if err != nil {
		klog.Fatal(err)
	}
	// Get clienSet of k8s
	clientSet, err := kubernetes.NewForConfig(config)
	if err != nil {
		klog.Fatal(err)
	}
	// List and show ns
	namespaces, err := clientSet.CoreV1().Namespaces().List(context.Background(), metav1.ListOptions{})
	if err != nil {
		klog.Fatal(err)
	}
	for _, ns := range namespaces.Items {
		fmt.Println(ns.Name)
	}
}
