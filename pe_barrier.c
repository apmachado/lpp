#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
    double sum;
    double a[256], b[256];
    int n = 256, i, temp;
    for (i=0; i<n; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }
    sum = 0;
    #pragma omp parallel shared(a,b,n,sum) private(i,temp)
    {
        temp = 0;
        #pragma omp for
        for (i=1; i<n; i++){
            temp = temp + a[i]*b[i];
            
        }

        #pragma omp barrier
        sum = sum + temp;
        
    }

    printf("Sum: %f\n", sum);

    return 0;
}