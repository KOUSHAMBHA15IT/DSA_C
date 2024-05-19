#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N], d[N], e[2 * N - 1], f[2 * N - 1];

bool solve(int c) {
    if (c == N) return true;
    for (int i = 0; i < N; i++) {
        if (!d[i] && !e[c + i] && !f[c - i + N - 1]) {
            board[c] = i, d[i] = e[c + i] = f[c - i + N - 1] = 1;
            if (solve(c + 1)) return true;
            d[i] = e[c + i] = f[c - i + N - 1] = 0;
        }
    }
    return false;
}

void print() {
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf(board[i] == j ? "Q " : ". ");
}

int main() {
    if (solve(0)) print();
    else printf("Solution does not exist.\n");
    return 0;
}
