// MPI include
#include <mpi.h>

// System includes
#include <iostream>

int main(int argc, char *argv[])
{
    // Initialize MPI state
    MPI_Init(&argc, &argv);

    // Get our MPI node number and node count
    int commSize, commRank;
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &commRank);


    int *countRoot = NULL;
    if (commRank == 0)
    {
        int countRoot = 0;
    }

    int *countNode = 0;

    if (commRank == 0)
    {
        MPI_Send(&countRoot, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if (commRank == 1)
    {
        MPI_Recv(&countNode, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        countNode++;
        MPI_Send(&countNode, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

    }

    if (commRank == 0)
    {
        MPI_Recv(&countRoot, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    
    // Cleanup
    MPI_Finalize();

    if (commRank == 0)
    {
        std::cout << countRoot << std::endl;
    }

    return 0;
}