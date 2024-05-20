#include <stdio.h>
#include <limits.h>

#define S 10

int mco(int d[], int n) {
    int dp[S][S] = {{0}};

    for (int l = 2; l < n; l++)
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int c = dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (c < dp[i][j])
                    dp[i][j] = c;
            }
        }

    return dp[1][n - 1];
}

int main() {
    int d[] = {10, 20, 30, 40, 30}; // Matrix dimensions
    int n = sizeof(d) / sizeof(d[0]); // Number of matrices

    printf("Minimum number of multiplications needed: %d\n", mco(d, n));

    return 0;
}
