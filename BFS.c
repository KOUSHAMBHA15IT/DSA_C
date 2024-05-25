#include <stdio.h>

#define N 4

int g[N][N] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};

void bfs(int s, int n) {
    int q[N] = {s}, f = 0, r = 0;
    char v[N] = {0};

    printf("BFS from %d: ", s);

    while (f <= r) {
        int c = q[f++];

        if (!v[c]) {
            printf("%d ", c);
            v[c] = 1;

            for (int i = 0; i < n; i++) {
                if (g[c][i] && !v[i]) {
                    q[++r] = i;
                }
            }
        }
    }
}

int main() {
    bfs(0, N);
    printf("\n");
    return 0;
}
