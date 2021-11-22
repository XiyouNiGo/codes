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
BENCHMARK(BM_VectorPushBack)->Arg(10)->Arg(100)->Arg(1000);

BENCHMARK_MAIN();