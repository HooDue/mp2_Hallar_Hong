#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

//externs
extern void asmhello();
extern void DAXPY(int size, double A, double* X, double* Y, double* Z);


// for generating random numbers
void initialize_X_Y(double *vector, int size) {
    srand(time(NULL)); //seed
    for (int i = 0; i < size; i++) {
        double random_value = (double)rand() / RAND_MAX * 100.0;

        if (random_value < 0.0) {
            random_value = 0.0;
        }
        else if (random_value > 99.9) {
            random_value = 99.9;
        }
        else {
            random_value = ((int)(random_value * 10.0)) / 10.0;
        }

        vector[i] = random_value;
        printf("%.1f\n", vector[i]);
    }
}

void DAXPY(int size, double A, double *X, double *Y, double *Z) {
	for (int i = 0; i < size; i++) {
		Z[i] = A * X[i] + Y[i];
	}
}


int main() {
    int size = 1024;
	double A = 2.0;
	double X[size], Y[size];
	double Z[size];

	initialize_X_Y(X, size);
    initialize_X_Y(Y, size);


	return 0;
}