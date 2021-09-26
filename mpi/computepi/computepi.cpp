#include <cmath>
#include <iostream>

#include "mpi.h"

int main(int argc, char* argv[]) {
  double local = 0, pi;
  int rank, size;
  const int N = 100000;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // 每隔size项计算一次（每个进程）
  for (int i = rank; i < N; i += size) {
    // 矩阵拟合法
    local += 4.0 / (1.0 + ((i + 0.5) / N) * ((i + 0.5) / N));
  }
  // int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
  //                MPI_Datatype datatype, MPI_Op op, int root,
  //                MPI_Comm comm)
  MPI_Reduce(&local, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    printf("Pi is %lf\n", pi * (1.0 / N));
  }
  MPI_Finalize();

  return 0;
}
