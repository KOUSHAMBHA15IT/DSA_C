#include <stdio.h>
#define N 6
#define INF 9999
void print(int dist[]) {
    for (int i = 0; i < N; i++) printf("%d\n", dist[i]);
}

void calc(int g[][N]) {
    int d[N] = {INF, INF, INF, INF, INF, INF};
    d[0] = 0;

    for (int c = 0; c < N - 1; c++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (g[i][j] != INF && d[i] + g[i][j] < d[j])
                    d[j] = d[i] + g[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (g[i][j] != INF && d[i] + g[i][j] < d[j]) {
                printf("Graph contains negative weight cycle.\n");
                return;
            }

    print(d);
}

int main() {
    int g[N][N] = {{0, 5, INF, INF, INF, INF},
                   {INF, 0, -2, INF, INF, -3},
                   {INF, INF, 0, INF, 3, INF},
                   {INF, INF, 6, 0, -2, INF},
                   {INF, INF, INF, INF, 0, INF},
                   {INF, INF, INF, 1, INF, 0}};

    calc(g);
}
