#include <mpi.h>
#include <stdlib.h>

int main(void)
{
  int rank, size;
  int buf[4];
  
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* need at least 2 processes */
  if (size < 2) {
      return 0;
  }

  if (rank == 0) {
    MPI_Send(buf, 4, MPI_INT, 1, 0, MPI_COMM_WORLD);
  } else if (rank == 1) {
    MPI_Recv(buf, 4, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  
  return 0;
}
