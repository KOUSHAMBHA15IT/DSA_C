#include <stdio.h>

int main() {
    int a[6][6] = {{0, 1, 1, 0, 0, 0},
                   {1, 0, 0, 1, 1, 0},
                   {1, 0, 0, 1, 0, 1},
                   {0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 0, 1},
                   {0, 0, 1, 0, 1, 0}};
    int color[6] = {0}, n = 6, i, j, p = 1;

    printf("\nMatrix form:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    color[0] = 1;
    while (p < n) {
        color[p] = 1;
        for (j = 0; j < p; j++)
            if (a[p][j] == 1 && color[j] == color[p]) color[p]++;
        p++;
    }

    for (i = 0; i < n; i++)
        printf("\nVertex %c = color %d", i + 65, color[i]);

    return 0;
}
