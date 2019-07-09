echo '---------------------------------'
echo 'Produto Escalar com Atomic'
OMP_NUM_THREADS=4 gcc -o a pe_atomic.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com Critical'
OMP_NUM_THREADS=4 gcc -o a pe_critical.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar Hibrido'
OMP_NUM_THREADS=2 mpicc -o a pe_hibrido.c -fopenmp
OMP_NUM_THREADS=2 mpirun -np 2 a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com MPI'
mpicc -o a pe_mpi.c -fopenmp
mpirun -np 4 a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com Reduce'
OMP_NUM_THREADS=4 gcc -o a pe_reduction.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com Schedule Dynamic'
OMP_NUM_THREADS=4 gcc -o a pe_schedule_dynamic.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com Schedule Static'
OMP_NUM_THREADS=4 gcc -o a pe_schedule_static.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'


echo '---------------------------------'
echo 'Produto Escalar com Sections'
OMP_NUM_THREADS=4 gcc -o a pe_sections.c -fopenmp
OMP_NUM_THREADS=4 ./a
rm a
echo '---------------------------------\n\n'
