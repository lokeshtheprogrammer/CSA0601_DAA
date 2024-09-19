#include <stdio.h>

int knapsack(int w, int n, int val[], int wt[]) {
    int i, j;
    int K[n + 1][w + 1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            } else {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    return K[n][w];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w);
    int val[n], wt[n];
    printf("Enter the values and weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    int max_val = knapsack(w, n, val, wt);
    printf("Maximum value: %d\n", max_val);
    return 0;
}
