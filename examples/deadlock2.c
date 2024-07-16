#include <mpi.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    int rank, size;
    int buf[4];

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    assert(size > 2);

    if (rank == 0) {
        MPI_Send(buf, 4, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else {
        MPI_Recv(buf, 4, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Finalize();
    return 0;
}
