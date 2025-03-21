package main

import (
	"log"
	"net/http"
	"time"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
	"github.com/prometheus/client_golang/prometheus/promhttp"
	"k8s.io/component-base/metrics"
	"k8s.io/component-base/metrics/legacyregistry"
)

var (
	counter = promauto.NewCounter(prometheus.CounterOpts{
		Subsystem: "linkaiauto",

		Name: "devbulls_counter",
		Help: "Counting the total number of requests handled",
	})

	// must be registered
	gauge = metrics.NewGaugeVec(&metrics.GaugeOpts{
		Subsystem: "linkai",
		Name:      "storage_client_started_total",

		Help: "Total number of requests started on the client.",
	}, []string{"node", "namespace"})
)

func recordMetrics() {
	go func() {
		// time.Sleep(10 * time.Second)
		// prometheus.MustRegister(gauge)
		// fmt.Println("registed")
		for {
			counter.Inc()
			gauge.WithLabelValues("node-1", "namespace-b").Set(0)
			time.Sleep(time.Second * 5)
		}
	}()
}

func init() {
}

func main() {
	recordMetrics()
	legacyregistry.MustRegister(gauge)
	legacyregistry.MustRegister(&counter)

	go func() {
		srv := http.NewServeMux()
		srv.Handle("/metrics", promhttp.Handler())

		if err := http.ListenAndServe(":8091", srv); err != nil {
			log.Fatalf("unable to start server: %v", err)
		}
	}()

	srv := http.NewServeMux()
	srv.Handle("/metrics", legacyregistry.Handler())

	if err := http.ListenAndServe(":8090", srv); err != nil {
		log.Fatalf("unable to start server: %v", err)
	}
}
