#include <benchmark/benchmark.h>

#include <vector>

static void BM_VectorPushBack(benchmark::State& state) {
  int insert_times = state.range(0);
  for (auto _ : state) {
    std::vector<int> container;
    for (int i = 0; i < insert_times; i++) {
      container.push_back(i);
    }
  }
}
static void CustomArgs(benchmark::internal::Benchmark* b) {
  for (int i = 100; i <= 1000; i += 100) {
    b->Arg(i);
  }
}
BENCHMARK(BM_VectorPushBack)->Apply(CustomArgs);

BENCHMARK_MAIN();