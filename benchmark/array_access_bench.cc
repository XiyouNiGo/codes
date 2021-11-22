#include <benchmark/benchmark.h>

#include <array>

constexpr int kArraySize = 5;

constexpr auto MyPow(const int i) { return i * i; }

// array::operator[]
static void BM_ArrayOperator(benchmark::State& state) {
  std::array<int, kArraySize> arr;
  constexpr int i = 1;
  for (auto _ : state) {
    arr[0] = MyPow(i);
    arr[1] = MyPow(i + 1);
    arr[2] = MyPow(i + 2);
    arr[3] = MyPow(i + 3);
    arr[4] = MyPow(i + 4);
  }
}
BENCHMARK(BM_ArrayOperator);

// array::at
static void BM_ArrayAt(benchmark::State& state) {
  std::array<int, kArraySize> arr;
  constexpr int i = 1;
  for (auto _ : state) {
    arr.at(0) = MyPow(i);
    arr.at(1) = MyPow(i + 1);
    arr.at(2) = MyPow(i + 2);
    arr.at(3) = MyPow(i + 3);
    arr.at(4) = MyPow(i + 4);
  }
}
BENCHMARK(BM_ArrayAt);

// std::get
static void BM_ArrayGet(benchmark::State& state) {
  std::array<int, kArraySize> arr;
  constexpr int i = 1;
  for (auto _ : state) {
    std::get<0>(arr) = MyPow(i);
    std::get<1>(arr) = MyPow(i + 1);
    std::get<2>(arr) = MyPow(i + 2);
    std::get<3>(arr) = MyPow(i + 3);
    std::get<4>(arr) = MyPow(i + 4);
  }
}
BENCHMARK(BM_ArrayGet);

BENCHMARK_MAIN();