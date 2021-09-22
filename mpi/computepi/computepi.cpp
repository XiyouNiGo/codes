#include "mpi.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  double local = 0, pi;
  int rank, size;
  const int N = 100000;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  for (int i = rank; i < N; i += size) {
    local += 4.0 / (1.0 + ((i + 0.5) / N) * ((i + 0.5) / N));
  }

  MPI_Reduce(&local, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0) {
    cout << "Pi is " << pi * (1.0 / N) << endl;
  }
  MPI_Finalize();

  return 0;
}
