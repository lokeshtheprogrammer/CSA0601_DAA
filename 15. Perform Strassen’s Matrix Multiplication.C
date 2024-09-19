#include <stdio.h>

void strassen_matrix_multiplication(int a[][2], int b[][2], int c[][2]) {
    int p1 = a[0][0] * (b[0][1] - b[1][1]);
    int p2 = (a[0][0] + a[0][1]) * b[1][1];
    int p3 = (a[1][0] + a[1][1]) * b[0][0];
    int p4 = a[1][1] * (b[1][0] - b[0][0]);
    int p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    int p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);

    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p5 + p1 - p3 - p7;
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];
    strassen_matrix_multiplication(a, b, c);
    printf("Matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("Matrix C (A * B):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
