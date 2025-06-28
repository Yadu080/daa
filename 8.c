#include <stdio.h>
#define INF 999

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void floyd(int n, int d[10][10]) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int n, a[10][10];
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (use %d for infinity where no edge exists):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(n, a);

    printf("\nThe all pair shortest distance matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
