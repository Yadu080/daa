#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

void dfs(int graph[MAX_NODES][MAX_NODES], bool visited[], int node, int num_nodes) {
    visited[node] = true;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, num_nodes);
        }
    }
}

bool is_connected(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    bool visited[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    dfs(graph, visited, 0, num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    if (is_connected(graph, num_nodes)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
