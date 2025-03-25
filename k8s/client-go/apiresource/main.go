package main

import (
	"fmt"
	"log"

	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
)

func main() {
	config, err := clientcmd.BuildConfigFromFlags("", clientcmd.RecommendedHomeFile)
	if err != nil {
		log.Fatalf("Failed to get kubeconfig: %v", err)
	}

	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		log.Fatalf("Failed to create clientset: %v", err)
	}

	grpList, err := clientset.Discovery().ServerGroups()
	if err != nil {
		log.Fatalf("Failed to get namespaced resource: %v", err)
	}

	for _, group := range grpList.Groups {
		// bytes, _ := json.Marshal(group)
		// fmt.Println(string(bytes))
		fmt.Println(group.PreferredVersion.GroupVersion, group.PreferredVersion.Version)
	}
}
