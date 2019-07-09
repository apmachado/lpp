#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
    double sum, sum2;
    double a[256], b[256];
    int n = 256, i, temp, temp2;
    for (i=0; i<n; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }
    sum = 0;
    sum2 = 0;
    #pragma omp parallel shared(a,b,n,sum) private(i,temp,temp2)
    {
        temp = 0;
        temp2 = 0;

        #pragma omp sections
        {
            #pragma omp section
            for (i=1; i<n; i++){
                temp = temp + a[i]*b[i];
                
            }

            #pragma omp section
            for (i=1; i<n; i++){
                temp2 = temp * a[i]*b[i];
            }
        }

        #pragma omp critical
        sum = sum + temp;

        #pragma omp critical
        sum2 = sum2 + temp2;
        
    }

    printf("Sum: %f\n", sum);

    printf("Sum2: %f\n", sum2);

    return 0;
}