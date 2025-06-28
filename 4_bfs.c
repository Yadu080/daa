#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

void bfs(int a[MAX_NODES][MAX_NODES], int n, int source) {
    int q[MAX_NODES], front = 0, rear = -1;
    int v[MAX_NODES] = {0};
    int node, i;

    v[source] = 1;
    q[++rear] = source;

    printf("Nodes reachable from node %d: ", source);

    while (front <= rear) {
        node = q[front++];
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (a[node][i] == 1 && v[i] == 0) {
                v[i] = 1;
                q[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, source, i, j;
    int a[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &source);

    bfs(a, n, source);

    return 0;
}
