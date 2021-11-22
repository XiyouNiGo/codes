#include <benchmark/benchmark.h>

#include <vector>

static void BM_VectorPushBack(benchmark::State &state) {
  int insert_times = state.range(0);
  for (auto _ : state) {
    std::vector<int> container;
    for (int i = 0; i < insert_times; i++) {
      container.push_back(i);
    }
  }
}
// BENCHMARK(BM_VectorPushBack)->Range(10, 1000);
BENCHMARK(BM_VectorPushBack)->RangeMultiplier(10)->Range(10, 1000);

BENCHMARK_MAIN();