#include <benchmark/benchmark.h>

#include <deque>
#include <iostream>
#include <vector>

const int kInsertTimes = 64;

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
BENCHMARK(BM_VectorPushBack)->Args({kInsertTimes, kInsertTimes});

static void BM_DequePushBack(benchmark::State &state) {
  int insert_times = state.range(0);
  std::cout << "Args: " << state.range(0) << " " << state.range(1) << std::endl;
  for (auto _ : state) {
    std::deque<int> container;
    for (int i = 0; i < insert_times; i++) {
      container.push_back(i);
    }
  }
}
BENCHMARK(BM_DequePushBack)->Args({kInsertTimes, kInsertTimes});

BENCHMARK_MAIN();