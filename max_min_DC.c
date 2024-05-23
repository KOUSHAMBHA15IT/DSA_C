#include<stdio.h>

void maxmin(int a[], int s, int e, int res[]) {
    if (s == e) {
        res[0] = res[1] = a[s];
        return;
    }

    int mid = s + (e - s) / 2;
    int leftRes[2], rightRes[2];
    maxmin(a, s, mid, leftRes);
    maxmin(a, mid + 1, e, rightRes);

    res[0] = (leftRes[0] < rightRes[0]) ? leftRes[0] : rightRes[0];
    res[1] = (leftRes[1] > rightRes[1]) ? leftRes[1] : rightRes[1];
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int res[2];

    maxmin(a, 0, sizeof(a) / sizeof(a[0]) - 1, res);

    printf("The minimum element: %d\n", res[0]);
    printf("The maximum element: %d\n", res[1]);

    return 0;
}
