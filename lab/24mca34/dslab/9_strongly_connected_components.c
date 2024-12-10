#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_VERTICES 36  // Support for up to 36 vertices (A-Z, 0-9)

int graph[MAX_VERTICES][MAX_VERTICES] = {0};       // Adjacency matrix for graph
int transpose[MAX_VERTICES][MAX_VERTICES] = {0};  // Adjacency matrix for transposed graph
int visited[MAX_VERTICES] = {0};                   // Visited nodes array
int finish_stack[MAX_VERTICES];                     // Stack for finish times
int top = -1;                                       // Top of the stack

// Converts a vertex (1-9 or A-Z) to an index
int vertex_to_index(char vertex) {
    if (isdigit(vertex))
        return vertex - '1';  // Convert '1'-'9' to 0-8 (1-based)
    else if (isalpha(vertex))
        return toupper(vertex) - 'A' + 9;  // Convert 'A'-'Z' to 9-35
    else
        return -1;
}

// Push an element onto the finish_stack
void push(int node) {
    finish_stack[++top] = node;
}

// Pop an element from the finish_stack
int pop() {
    return finish_stack[top--];
}

// DFS on the original graph
void dfs_original(int node, int vertices) {
    visited[node] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] && !visited[i])
            dfs_original(i, vertices);
    }

    push(node);
}

// Transpose the graph
void transpose_graph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            transpose[j][i] = graph[i][j];
        }
    }
}

// DFS on the transposed graph
void dfs_transposed(int node, int vertices, int* component, int* component_size) {
    visited[node] = 1;
    component[(*component_size)++] = node;

    for (int i = 0; i < vertices; i++) {
        if (transpose[node][i] && !visited[i])
            dfs_transposed(i, vertices, component, component_size);
    }
}

// Find and print SCCs
void find_sccs(int vertices) {
    // Step 1: DFS on the original graph
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i])
            dfs_original(i, vertices);
    }

    // Step 2: Transpose the graph
    transpose_graph(vertices);

    // Step 3: DFS on the transposed graph in the order of finish times
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("The strongly connected components (SCCs) are:\n");

    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            int component[MAX_VERTICES];
            int component_size = 0;

            dfs_transposed(node, vertices, component, &component_size);

            // Print the SCC
            printf("{");
            for (int j = 0; j < component_size; j++) {
                printf("%c", component[j] < 9 ? component[j] + '1' : component[j] - 9 + 'A');  
                if (j < component_size - 1)
                    printf(", ");
            }
            printf("}\n");
        }
    }
}

int main() {
    int vertices, edges;
    char u, v;

    printf("Enter number of vertices (up to %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Error: The graph can only have between 1 and %d vertices.\n", MAX_VERTICES);
        return -1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &u, &v);
        int u_idx = vertex_to_index(u);
        int v_idx = vertex_to_index(v);
        if (u_idx == -1 || v_idx == -1) {
            printf("Invalid input! Vertices must be in the range of 1-9 or A-Z.\n");
            return -1;
        }
        graph[u_idx][v_idx] = 1;
    }

    find_sccs(vertices);
    
    return 0;
}
