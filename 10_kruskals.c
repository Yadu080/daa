#include <stdio.h>
#define INFINITY 999
#define MAX 100

struct EDGE {
    int x, y, wt;
} e[MAX];

int parent[MAX];
int cost[MAX][MAX];
int t[MAX][2];
int nedges = 0;

void sort_edges(int n_edges) {
    int i, j;
    struct EDGE temp;
    for (i = 0; i < n_edges - 1; i++) {
        for (j = 0; j < n_edges - 1 - i; j++) {
            if (e[j].wt > e[j + 1].wt) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int get_parent(int v) {
    while (parent[v] != 0)
        v = parent[v];
    return v;
}

void join(int i, int j) {
    parent[j] = i;
}

void kruskal(int n) {
    int i, k = 0, sum = 0;
    int edge_count = 0;

    for (i = 0; i < nedges && edge_count < n - 1; i++) {
        int u = e[i].x;
        int v = e[i].y;

        int set_u = get_parent(u);
        int set_v = get_parent(v);

        if (set_u != set_v) {
            join(set_u, set_v);
            t[edge_count][0] = u;
            t[edge_count][1] = v;
            sum += e[i].wt;
            edge_count++;
        }
    }

    printf("\nCost of the minimum spanning tree is: %d\n", sum);
    printf("The edges in the spanning tree are:\n");
    for (i = 0; i < edge_count; i++) {
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }
}

int main() {
    int n, i, j;
    scanf("%d", &n);

    nedges = 0;
    for (i = 1; i <= n; i++) {
        parent[i] = 0;
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] != INFINITY) {
                e[nedges].x = i;
                e[nedges].y = j;
                e[nedges].wt = cost[i][j];
                nedges++;
            }
        }
    }

    sort_edges(nedges);
    kruskal(n);

    return 0;
}
