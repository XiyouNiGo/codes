#include <benchmark/benchmark.h>

static void BM_ComplexityN(benchmark::State& state) {
  int n = 0;
  for (auto _ : state) {
    for (int i = 0; i < state.range(0); ++i) {
      benchmark::DoNotOptimize(n += 2);
    }
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ComplexityN)
    ->RangeMultiplier(10)
    ->Range(10, 1000000)
    ->Complexity();

static void BM_ComplexityLogN(benchmark::State& state) {
  int n = 0;
  for (auto _ : state) {
    for (int i = 1; i < state.range(0); i *= 2) {
      benchmark::DoNotOptimize(n += 2);
    }
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ComplexityLogN)
    ->RangeMultiplier(10)
    ->Range(10, 1000000)
    ->Complexity();

static void BM_ComplexitySquare(benchmark::State& state) {
  int n = 0;
  auto len = state.range(0);
  for (auto _ : state) {
    for (int64_t i = 1; i < len * len; ++i) {
      benchmark::DoNotOptimize(n += 2);
    }
  }
  state.SetComplexityN(len);
}
BENCHMARK(BM_ComplexitySquare)
    ->RangeMultiplier(10)
    ->Range(10, 100000)
    ->Complexity();

BENCHMARK_MAIN();