#include <benchmark/benchmark.h>

#include <deque>
#include <vector>

template <typename T>
static void BM_ContainerPushBack(benchmark::State &state) {
  int insert_times = state.range(0);
  for (auto _ : state) {
    T container;
    for (int i = 0; i < insert_times; i++) {
      container.push_back(i);
    }
  }
}
BENCHMARK_TEMPLATE(BM_ContainerPushBack, std::vector<int>)->Arg(10)->Arg(100)->Arg(1000);
BENCHMARK_TEMPLATE(BM_ContainerPushBack, std::deque<int>)->Arg(10)->Arg(100)->Arg(1000);

BENCHMARK_MAIN();