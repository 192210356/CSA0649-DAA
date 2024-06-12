#include <stdio.h>
#include <time.h>

#define R1 1000 // number of rows in Matrix-1
#define C1 1000 // number of columns in Matrix-1
#define R2 1000 // number of rows in Matrix-2
#define C2 1000 // number of columns in Matrix-2

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    int result[R1][C2];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int m1[R1][C1];
    int m2[R2][C2];
    clock_t start, end;

    // Initialize matrices with random values
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            m1[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            m2[i][j] = rand() % 10;
        }
    }

    start = clock();
    multiplyMatrix(m1, m2);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
