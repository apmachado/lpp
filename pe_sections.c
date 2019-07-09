#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
    double a[256], b[256];
    int n = 256, i;
    double temp_sum = 0,temp_prod = 1;
    for (i=0; i<n; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }

    #pragma omp parallel shared(a,b,n) private(i)
    {
        #pragma omp sections
        {
            #pragma omp section
            for (i=0; i<n; i++){
                temp_sum += a[i]*b[i];
            }

            #pragma omp section
            for (i=1; i<n; i++){
                temp_prod *= a[i]*b[i];
            }
        }
    }

    printf("Sum: %f\n", temp_sum);
    printf("Product: %f\n", temp_prod);



    return 0;
}