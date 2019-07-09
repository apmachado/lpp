#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]){

    int p;
    int my_rank;
    double prod_escalar;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    double sum;
    double a[256], b[256];
    int n = 256, i;

    int local_n, local_a, local_b; 
    local_n = n/p;

    int resto = n - (local_n * p);
    if(resto > 0 && my_rank < resto){
        local_n +=1;
        printf("Processo %d: local_n = %d \n", my_rank, local_n);
    } else {
        printf("Processo %d: local_n = %d \n", my_rank, local_n);
    }

    local_a = my_rank*local_n;
    if(resto > 0 && my_rank >= resto) local_a += resto;
    local_b = local_a + local_n;

    for (i=local_a; i<local_b; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }

    sum = 0;
    for (i=local_a; i<local_b; i++){
        sum = sum + a[i]*b[i];
    }

    if(my_rank == 0){
        prod_escalar = sum;
        MPI_Reduce(&sum, &prod_escalar, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    } else {
        MPI_Reduce(&sum, &prod_escalar, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    if(my_rank == 0) printf("Resultado: %f\n", prod_escalar);

    

    return 0;
}