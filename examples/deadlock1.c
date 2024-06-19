#include <mpi.h>
#include <stdlib.h>

int main(void) {
    MPI_Init(NULL, NULL);

    MPI_Recv(NULL, 0, MPI_INT, 0, 0, MPI_COMM_SELF, MPI_STATUS_IGNORE);

    MPI_Finalize();
    return 0;
}
