#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

typedef struct Edge {
    int vertex, weight;
    struct Edge* next;
} Edge;

Edge* adjList[MAX]; // Adjacency list
int visited[MAX] = {0}, n; // Global visited array
int mincost = 0;

// Function to add an edge to the adjacency list
void addEdge(int u, int v, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = v;
    newEdge->weight = weight;
    newEdge->next = adjList[u];
    adjList[u] = newEdge;
}

// Function to find the minimum spanning tree using Prim's algorithm
void prim() {
    int ne = 1, u, v, min;
    visited[1] = 1; // Start from the first vertex

    printf("\n");

    while (ne < n) {
        min = INF;
        u = -1;
        v = -1;

        // Find the edge with the minimum weight that connects a visited vertex to an unvisited vertex
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                Edge* temp = adjList[i];
                while (temp) {
                    if (!visited[temp->vertex] && temp->weight < min) {
                        min = temp->weight;
                        u = i;
                        v = temp->vertex;
                    }
                    temp = temp->next;
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, u, v, min);
            mincost += min;
            visited[v] = 1; // Mark the vertex as visited
        }
    }

    printf("\n\nMinimum cost: %d\n", mincost);
}

int main() {
    int edges, u, v, weight;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adjList[i] = NULL;
    }

    printf("\nEnter the edges (u, v, weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
        addEdge(v, u, weight); // Since the graph is undirected
    }

    prim(); // Call Prim's algorithm
    return 0;
}  
