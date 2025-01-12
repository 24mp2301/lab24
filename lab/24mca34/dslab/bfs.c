#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
bool visited[MAX];
int queue[MAX], front = 0, rear = -1;

void BFS(int start, int n) {
    queue[++rear] = start; // Enqueue the start vertex
    visited[start] = true;

    while (front <= rear) {
        int current = queue[front++]; // Dequeue
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) { // If connected and not visited
                queue[++rear] = i; // Enqueue
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    printf("BFS traversal starting from vertex 0:\n");
    BFS(0, n);

    return 0;
}
