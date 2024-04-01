#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

#define TWENTY 1048576      // 2^20
#define TWO_FOUR 16777216   // 2^24
#define TWO_SEVEN 134217728 // 2^27

//externs
extern void daxpy(double A, double* X, double* Y, double* Z_a, int size);

// for generating random numbers, only from 0.0 to 100.0 and only one decimal place
void initialize_X_Y(double* X, int size, unsigned int seed) {
    srand(seed); //seed

    for (int i = 0; i < size; i++) {
        double random_value = (double)rand() / RAND_MAX * 100.0;
        X[i] = random_value;
    }
}

// C Version of the DAXPY
void daxpy_C(double A, double* X, double* Y, double* Z_c, int size) {
    for (int i = 0; i < size; i++) {
        Z_c[i] = A * X[i] + Y[i];
    }
}

// Function for printing Z results
void printZ(double A, double* X, double* Y, double* Z_c, double* Z_a) {
    for (int i = 0; i < 10; i++) {
        printf("OUTPUT NO. %d\n\n", i);
        printf("\tC result: \t%.1f * %.1f + %.1f = %.1f\n", A, X[i], Y[i], Z_c[i]);
        printf("\tx86-64 result: \t%.1f * %.1f + %.1f = %.1f\n", A, X[i], Y[i], Z_a[i]);
        printf("------------------------------------\n");
    }
}

int main() {
    int size = TWENTY;
    double A = 2.0;

    double* X;
    double* Y;
    double* Z_c;
    double* Z_a;

    double avg_time_c = 0.0;
    double avg_time_a = 0.0;

    double each_time_c = 0.0;
    double total_time_c = 0.0;

    double each_time_a = 0.0;
    double total_time_a = 0.0;

    clock_t start_time_c, end_time_c, start_time_a, end_time_a;

    // Dynamically allocate memory for X, Y, and Z
    X = (double*)malloc(size * sizeof(double));
    Y = (double*)malloc(size * sizeof(double));
    Z_c = (double*)malloc(size * sizeof(double));
    Z_a = (double*)malloc(size * sizeof(double));

    // Initialize X and Y with random values
    initialize_X_Y(X, size, (unsigned int)time(NULL));
    initialize_X_Y(Y, size, (unsigned int)time(NULL) + 1);

    // For C
    for (int i = 0; i < 30; i++) {
        start_time_c = clock();
        daxpy_C(A, X, Y, Z_c, size);
        end_time_c = clock();

        each_time_c = ((double)(end_time_c - start_time_c)) / CLOCKS_PER_SEC;
        printf("C [%d]: %.4f\n", i, each_time_c);

        total_time_c += each_time_c;
    }

    printf("Total Time C: %.4f\n", total_time_c);

    avg_time_c = total_time_c / 30.0;
    printf("Average Time C: %.4f\n\n", avg_time_c);

    // For x86-64
    for (int i = 0; i < 30; i++) {
        start_time_a = clock();
        daxpy(A, X, Y, Z_a, size);
        end_time_a = clock();

        each_time_a = ((double)(end_time_a - start_time_a)) / CLOCKS_PER_SEC;
        printf("x86-64 [%d]: %.4f\n", i, each_time_a);

        total_time_a += each_time_a;
    }

    printf("Total Time x86-64: %.4f\n", total_time_a);

    avg_time_a = total_time_a / 30.0;
    printf("Average Time x86-64: %.4f\n\n", avg_time_a);
    printf("------------------------------------\n");

    // Print results of Z
    printZ(A, X, Y, Z_c, Z_a);
  
    // Free the dynamically allocated memory
    free(X);
    free(Y);
    free(Z_c);
    free(Z_a);

    return 0;
}