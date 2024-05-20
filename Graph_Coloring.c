#include <stdio.h>
#define MAX 6 // Adjust MAX according to the size of the matrix

int main() {
    int a[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int color[MAX] = {0}, n = MAX, i, j, p = 1;

    printf("\nMatrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    color[0] = 1;
    while (p < n) {
        color[p] = 1;
        for (j = 0; j < p; j++) {
            if (a[p][j] == 1 && color[j] == color[p])
                color[p]++;
        }
        p++;
    }

    for (i = 0; i < n; i++)
        printf("\nVertex %c = color %d", i + 65, color[i]);

    return 0;
}
