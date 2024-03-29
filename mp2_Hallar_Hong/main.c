#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

#define TEN 1024            // 2^10
#define TWENTY 1048576      // 2^20
#define TWO_FOUR 16777216   // 2^24
#define THIRTY 1073741824   // 2^30

//externs
extern void daxpy(double A, double* X, double* Y, double* Z, int size);

// for generating random numbers, only from 0.0 to 100.0 and only one decimal place
void initialize_X_Y(double* vector, int size, unsigned int seed) {
    srand(seed); //seed

    for (int i = 0; i < size; i++) {
        double random_value = (double)rand() / RAND_MAX * 100.0;
        vector[i] = random_value;
    }
}

// C Version of the DAXPY
void daxpy_C(double A, double* X, double* Y, double* Z, int size) {
    for (int i = 0; i < size; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

double daxpy_asm_time(double A, double* X, double* Y, double* Z, int size) {
    clock_t start_asm, end_asm;
    double total_time_asm = 0.0;

    for (int i = 0; i < 30; i++) {
        start_asm = clock();

        // Perform the DAXPY ASM operation
        daxpy(A, X, Y, Z, size);

        end_asm = clock();

        total_time_asm += ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;
    }

    return total_time_asm / 30.0;
}

double daxpy_c_time(double A, double* X, double* Y, double* Z, int size) {
    clock_t start_c, end_c;
    double total_time_c = 0.0;

    for (int i = 0; i < 30; i++) {
        start_c = clock();

        // Performt he DAXPY C operation
        daxpy_C(A, X, Y, Z, size);

        end_c = clock();

        total_time_c += ((double)(end_c - start_c)) / CLOCKS_PER_SEC;
    }

    return total_time_c / 30.0;
}

void printZ(double A, double* X, double* Y, double* Z, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %.1f * %.1f + %.1f = %.1f\n", i, A, X[i], Y[i], Z[i]);
    }
}

int main() {
    int size = TEN;
    double A = 2.0;
    double* X;
    double* Y;
    double* Z;

    // Dynamically allocate memory for X, Y, and Z
    X = (double*)malloc(size * sizeof(double));
    Y = (double*)malloc(size * sizeof(double));
    Z = (double*)malloc(size * sizeof(double));

    // Initialize X and Y with random values
    initialize_X_Y(X, size, (unsigned int)time(NULL));
    initialize_X_Y(Y, size, (unsigned int)time(NULL) + 1);

    printf("ASM Average Time: %.1f", daxpy_asm_time(A, X, Y, Z, size));

    printf("C Average Time: %.1f", daxpy_c_time(A, X, Y, Z, size));

    // Print the results
    printZ(A, X, Y, Z, size);

    // Free the dynamically allocated memory
    free(X);
    free(Y);
    free(Z);

    return 0;
}