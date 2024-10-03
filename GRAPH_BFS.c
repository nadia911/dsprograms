#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices in the graph

int graph[MAX][MAX];  // Adjacency matrix representation of the graph
int visited[MAX];     // Array to mark visited vertices
int vertices;         // Number of vertices in the graph

// Function to perform BFS
void BFS(int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    
    // Initialize the queue and visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    // Enqueue the start vertex and mark it as visited
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];  // Dequeue a vertex
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    // Perform BFS from the first vertex (0 or any other vertex)
    printf("BFS Traversal: ");
    BFS(0);

    return 0;
}
