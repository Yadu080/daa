#include <stdio.h>
#define INFINITY 999

void dijkstra(int cost[10][10], int n, int source, int v[10], int d[10]) {
    int i, j, u, min;

    for (i = 1; i <= n; i++) {
        v[i] = 0;  
        d[i] = cost[source][i]; 
    }
    v[source] = 1; 
    d[source] = 0;

    for (int count = 1; count < n; count++) {
        min = INFINITY;
        u = -1;

       
        for (i = 1; i <= n; i++) {
            if (!v[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break; // no reachable vertex left
        v[u] = 1;

        // Update distances of adjacent vertices
        for (j = 1; j <= n; j++) {
            if (!v[j] && cost[u][j] != INFINITY && d[u] + cost[u][j] < d[j]) {
                d[j] = d[u] + cost[u][j];
            }
        }
    }
}

int main() {
    int n, cost[10][10], sourceNode, v[10], d[10];
    int i, j;

    printf("Enter no of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency matrix (use %d for no edge):\n", INFINITY);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex (%d to %d): ", 1, n);
    scanf("%d", &sourceNode);

    dijkstra(cost, n, sourceNode, v, d);

    printf("Shortest distances from vertex %d:\n", sourceNode);
    for (i = 1; i <= n; i++) {
        if (d[i] == INFINITY)
            printf("%d --> %d : No path\n", sourceNode, i);
        else
            printf("%d --> %d : %d\n", sourceNode, i, d[i]);
    }

    return 0;
}
