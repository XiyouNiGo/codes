package main

import (
	"context"
	"log"

	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	v1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/apimachinery/pkg/apis/meta/v1/unstructured"
	"k8s.io/apimachinery/pkg/runtime/schema"
	"k8s.io/client-go/dynamic"
	"k8s.io/client-go/dynamic/dynamicinformer"

	"k8s.io/client-go/tools/cache"
	"k8s.io/client-go/tools/clientcmd"
)

const (
	snapshotGroup    = "snapshot.storage.k8s.io"
	snapshotVersion  = "v1"
	snapshotResource = "volumesnapshots"
	osimageCacheAnno = "app.gaea.io/osimage_cache"
)

func main() {
	config, err := clientcmd.BuildConfigFromFlags("", clientcmd.RecommendedHomeFile)
	if err != nil {
		log.Fatalf("Failed to get kubeconfig: %v", err)
	}
	dynClient, err := dynamic.NewForConfig(config)
	if err != nil {
		log.Fatalf("Failed to create clientset: %v", err)
	}
	ctx := context.Background()
	var snapshotScheme = schema.GroupVersionResource{
		Group:    snapshotGroup,
		Version:  snapshotVersion,
		Resource: snapshotResource}
	snapshots, err := dynClient.Resource(snapshotScheme).List(ctx, v1.ListOptions{})
	if err != nil {
		log.Fatalf("Failed to get namespaced resource: %v", err)
	}
	for _, snapshot := range snapshots.Items {
		ns := snapshot.GetNamespace()
		name := snapshot.GetName()
		log.Printf("Snapshot: %s/%s\n", ns, name)
	}

	dynInfomer := dynamicinformer.NewFilteredDynamicSharedInformerFactory(dynClient, 0, "", func(options *metav1.ListOptions) {
	})
	snapshotInformer := dynInfomer.ForResource(snapshotScheme).Informer()
	snapshotInformer.AddEventHandler(cache.ResourceEventHandlerFuncs{
		AddFunc: func(obj interface{}) {
			snapshot := obj.(*unstructured.Unstructured)
			log.Printf("snapshot add callback: %+v/%+v", snapshot.GetNamespace(), snapshot.GetName())
		},
		UpdateFunc: func(_, obj interface{}) {
			snapshot := obj.(*unstructured.Unstructured)
			log.Printf("snapshot update callback: %+v/%+v", snapshot.GetNamespace(), snapshot.GetName())
		},
		DeleteFunc: func(obj interface{}) {
			snapshot := obj.(*unstructured.Unstructured)
			log.Printf("snapshot delete callback: %+v/%+v", snapshot.GetNamespace(), snapshot.GetName())
		},
	})
	snapshotInformer.Run(ctx.Done())
}
