#include <stdio.h>
#include <stdlib.h>

void prims(int cost[10][10], int n) {
    int a, b, i, j;
    int visited[10], mincost = 0;
    int u, v, min;
    int ne = 1;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nThe edges of the minimum spanning tree\n");
    visited[1] = 1;  // Start from node 1

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (!visited[b]) {
            printf("%d Edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; 
    }
    printf("Minimum total cost = %d\n", mincost);
}

int main() {
    int n, i, j;
    int cost[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; 
        }
    }

    prims(cost, n);
    return 0;
}
