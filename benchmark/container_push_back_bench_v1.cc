#include <benchmark/benchmark.h>

#include <deque>
#include <vector>

const int kInsertTimes = 64;

static void BM_VectorPushBack(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> container;
    for (int i = 0; i < kInsertTimes; i++) {
      container.push_back(i);
    }
  }
}
BENCHMARK(BM_VectorPushBack);

static void BM_DequePushBack(benchmark::State &state) {
  for (auto _ : state) {
    std::deque<int> container;
    for (int i = 0; i < kInsertTimes; i++) {
      container.push_back(i);
    }
  }
}
BENCHMARK(BM_DequePushBack);

BENCHMARK_MAIN();