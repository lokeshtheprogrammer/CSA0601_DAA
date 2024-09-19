#include <stdio.h>

int tsp(int graph[][V], int s) {
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[1][s] = 0;
    for (int mask = 0; mask < (1 << V); mask++) {
        for (int node = 0; node < V; node++) {
            if (((mask >> node) & 1) == 0) {
                continue;
            }
            for (int k = 0; k < V; k++) {
                if (k == node || ((mask >> k) & 1) == 0) {
                    continue;
                }
                int new_mask = mask ^ (1 << node);
                dp[mask][node] = min(dp[mask][node], dp[new_mask][k] + graph[k][node]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (i != s) {
            ans = min(ans, dp[(1 << V) - 1][i] + graph[i][s]);
        }
    }
    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 30},
        {15, 35, 0, 25},
        {20, 30, 25, 0}
    };
    int s = 0;
    printf("Minimum cost: %d\n", tsp(graph, s));
    return 0;
}
