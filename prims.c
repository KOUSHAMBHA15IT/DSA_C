#include<stdio.h>
#define INF 9999

int main() {
    int n = 5; // Number of vertices
    int g[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int s = 0, r, c, p = 0, min;
    int status[n];
    
    for (int i = 0; i < n; status[i++] = 0);
    status[0] = 1; // Starting node
    
    while (p < n - 1) {
        for (int i = 0; i < n; i++) {
            if (status[i] == 1) {
                min = INF;
                for (int j = 0; j < n; j++) {
                    if (status[j] == 0 && g[i][j] < min) {
                        min = g[i][j];
                        r = i;
                        c = j;
                    }
                }
            }
        }
        printf("\n %c --> %c = %d", r + 65, c + 65, min);
        s += min;
        status[c] = 1;
        p++;
    }
    printf("\n Value %d", s);
    return 0;
}
