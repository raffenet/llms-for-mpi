#include <mpi.h>
#include <stdlib.h>

int main(void) {
    int rank, size;
    int buf[4];

    MPI_Init(NULL, NULL);

    MPI_Bcast(buf, 4, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}
