#include <stdio.h>

#define V 4
#define INF 9999

void dijkstra(int g[V][V], int s) {
    int d[V], vstd[V] = {0}, mD, u;
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    for (int c = 0; c < V - 1; c++) {
        mD = INF;
        for (int v = 0; v < V; v++)
            if (!vstd[v] && d[v] <= mD)
                mD = d[v], u = v;
        vstd[u] = 1;
        for (int v = 0; v < V; v++)
            if (!vstd[v] && g[u][v] && d[u] != INF && d[u] + g[u][v] < d[v])
                d[v] = d[u] + g[u][v];
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, d[i]);
}

int main() {
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    dijkstra(graph, 0);
    return 0;
}
