#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices in the graph

int graph[MAX][MAX];  // Adjacency matrix representation of the graph
int visited[MAX];     // Array to mark visited vertices
int vertices;         // Number of vertices in the graph

void DFS(int vertex) {
    visited[vertex] = 1;  // Mark the vertex as visited
    printf("%d ", vertex);

    // Visit all the adjacent vertices
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Read the edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // Mark the edge from u to v
        graph[v][u] = 1;  // For undirected graph, mark the edge from v to u
    }

    // Perform DFS from the first vertex (0 or any other vertex)
    printf("DFS Traversal: ");
    DFS(0);

    return 0;
}
