#include <benchmark/benchmark.h>

#include <vector>
#include <iostream>

static void BM_VectorPushBack(benchmark::State &state) {
  int insert_times = state.range(0);
  std::cout << "Args: " << state.range(0) << " " << state.range(1) << std::endl;
  for (auto _ : state) {
    std::vector<int> container;
    for (int i = 0; i < insert_times; i++) {
      container.push_back(i);
    }
  }
}
BENCHMARK(BM_VectorPushBack)->ArgsProduct({{10, 100, 1000}, {1, 2}});

BENCHMARK_MAIN();