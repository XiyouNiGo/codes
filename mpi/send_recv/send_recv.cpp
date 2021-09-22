#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int rank = 0, size = 0;
  int tag = 1;
  int name_len = 0;
  char processor_name[MPI_MAX_PROCESSOR_NAME] = {0};
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Get_processor_name(processor_name, &name_len);

  if (rank == 0) {
    int senddata = 9999;
    printf("Processor %s send %d\n", processor_name, senddata);
    MPI_Send(&senddata, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
  } else if (rank == 1) {
    int recvdata = 0;
    MPI_Recv(&recvdata, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
    printf("Processor %s receive %d\n", processor_name, recvdata);
  }
  MPI_Finalize();
  return 0;
}
