#include <stdio.h>

#define N 4

int fun(int a[][N]) {
    int i, y=0;
    for(i=0; i<N; i++)
        y+=a[i][0]+a[i][N-1];

    for(i=1; i<N-1; i++)
        y+=a[0][i]+a[N-1][i];

    return y;
}

int main() {
    int y;
    int x[N][N] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {3, 4, 1, 2}, {4, 3, 2, 1}};

    y=fun(x);

    printf("%d", y);

    return 0;
}

