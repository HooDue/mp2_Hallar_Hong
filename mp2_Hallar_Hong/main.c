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

void printZ(double A, double* X_c, double* Y_c, double* Z_c, int size, double* Z_a) {
    for (int i = 1; i < 11; i++) {
        printf("OUTPUT NO. %d\n\n", i);
        printf("\tC result: %.1f * %.1f + %.1f = %.1f\n", A, X_c[i], Y_c[i], Z_c[i]);
        printf("\tx86-64 result: %.1f\n", Z_a[i]);
        printf("------------------------------------\n");
    }
}

int main() {
    int size = TWENTY;
    double A = 2.0;
    double* X_c;
    double* Y_c;
    double* Z_c;
    double* X_a;
    double* Y_a;
    double* Z_a;

    // For C
    LARGE_INTEGER start, end, frequency;
    double total_time_c = 0.0;

    // For x86-64
    LARGE_INTEGER start_asm, end_asm, frequency_asm;
    double total_time_asm = 0.0;

    // Dynamically allocate memory for X, Y, and Z
    X_c = (double*)malloc(size * sizeof(double));
    Y_c = (double*)malloc(size * sizeof(double));
    Z_c = (double*)malloc(size * sizeof(double));

    X_a = (double*)malloc(size * sizeof(double));
    Y_a = (double*)malloc(size * sizeof(double));
    Z_a = (double*)malloc(size * sizeof(double));

    // Initialize X and Y with random values
    initialize_X_Y(X_c, size, (unsigned int)time(NULL));
    initialize_X_Y(X_a, size, (unsigned int)time(NULL));

    initialize_X_Y(Y_c, size, (unsigned int)time(NULL) + 1);
    initialize_X_Y(Y_a, size, (unsigned int)time(NULL) + 1);

    // For C
    QueryPerformanceFrequency(&frequency);

    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&start);

        // Performt he DAXPY C operation
        daxpy_C(A, X_c, Y_c, Z_c, size);

        QueryPerformanceCounter(&end);

        double elapsed_time_c = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // For checking
        // printf("%.9f\n", elapsed_time_c);

        total_time_c += elapsed_time_c;
    }

    printf("AVERAGE TIME:\n");
    printf("\tC: %.10f seconds\n", total_time_c / 30.0);
    printf("\n");

    // For x86-64
    QueryPerformanceFrequency(&frequency_asm);

    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&start_asm);

        // Performt he DAXPY ASM operation
        daxpy(A, X_a, Y_a, Z_a, size);

        QueryPerformanceCounter(&end_asm);

        double elapsed_time_asm = (double)(end_asm.QuadPart - start_asm.QuadPart) / frequency_asm.QuadPart;

        // For checking
        // printf("%.9f\n", elapsed_time_asm);

        total_time_c += elapsed_time_asm;
    }

    printf("\tx86-64: %.10f seconds\n", total_time_asm / 30.0);
    printf("------------------------------------\n");

    // Print results
    printZ(A, X_c, Y_c, Z_c, 10, Z_a);

    // Free the dynamically allocated memory
    free(X_c);
    free(Y_c);
    free(Z_c);
    free(X_a);
    free(Y_a);
    free(Z_a);

    return 0;
}