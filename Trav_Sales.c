#include <stdio.h>
#include <limits.h>

#define N 4 // Number of cities

int graph[N][N] = { {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0} };

int tsp(int mask, int pos, int dp[N][1 << N]) {
    if (mask == (1 << N) - 1) return graph[pos][0];
    if (dp[pos][mask] != -1) return dp[pos][mask];

    int minDistance = INT_MAX;
    for (int next = 0; next < N; next++) {
        if (!(mask & (1 << next))) {
            int newDistance = graph[pos][next] + tsp(mask | (1 << next), next, dp);
            minDistance = (newDistance < minDistance) ? newDistance : minDistance;
        }
    }

    return dp[pos][mask] = minDistance;
}

int main() {
    int dp[N][1 << N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << N); j++) dp[i][j] = -1;

    int minDistance = tsp(1, 0, dp); // Start from city 0

    printf("Minimum distance for TSP: %d\n", minDistance);

    return 0;
}
