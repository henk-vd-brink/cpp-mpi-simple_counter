// MPI include
#include <mpi.h>

// System includes
#include <iostream>

int main(int argc, char *argv[])
{
    // Initialize MPI state
    MPI_Init(&argc, &argv);

    // Get our MPI node number and node count
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int PING_PONG_LIMIT = 10;

    int count = 0;
    int partner_rank = (world_rank + 1) % 2;

    while (count < PING_PONG_LIMIT) {
        if (world_rank == count % 2) {

            count++;

            MPI_Send(&count, 1, MPI_INT, partner_rank, 0,
                    MPI_COMM_WORLD);

            printf("%d sent and incremented count"
                "%d to %d\n", world_rank, count,
                partner_rank);

        } else {
            MPI_Recv(&count, 1, MPI_INT, partner_rank, 0,
                    MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            printf("%d received count %d from %d\n",
                world_rank, count, partner_rank);
        }
    }


    // Cleanup
    MPI_Finalize();

    return 0;
}