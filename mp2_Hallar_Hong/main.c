//FOR 2^20, 2^24 and 2^30
#define TEN 1024
#define TWENTY 1048576
#define TWO_FOUR 16777216
#define THIRTY 1073741824

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

//externs
extern void daxpy(double A, double* X, double* Y, double* Z, int size);


// for generating random numbers, only from 0.0 to 100.0 and only one decimal place
void initialize_X_Y(double *vector, int size, unsigned int seed) {
    srand(seed); //seed
    for (int i = 0; i < size; i++) {
        double random_value = (double)rand() / RAND_MAX * 100.0;
        vector[i] = random_value;
    }
}

/*
void DAXPY(double A, double* X, double* Y, double* Z, int size) {
    for (int i = 0; i < size; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}
*/
/*
void printZ(double A, double* X, double* Y, double* Z, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %f * %f * %f = %f/n", size, A, X[i], Y[i], Z[i]);
    }
}
*/



int main() {
    int size = TEN;
	double A = 2.0;
	double X[TEN], Y[TEN];
	double Z[TEN];

	initialize_X_Y(X, size, (unsigned int)time(NULL));
    initialize_X_Y(Y, size, (unsigned int)time(NULL)+1);
    daxpy(A, X, Y, Z, TEN);
    
    for (int i = 0; i < size; i++) {
        printf("%d: %.1f * %.1f + %.1f = %.1f\n", i,A,X[i],Y[i],Z[i]);
    }

	return 0;
}