#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge src -> dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Uncomment the following lines for an undirected graph
    // newNode = createNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) function
void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS) function
void BFS(Graph* graph, int startVertex) {
    int queue[MAX], front = -1, rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Topological Sorting helper function
void topologicalSortUtil(Graph* graph, int vertex, int* stack, int* top) {
    graph->visited[vertex] = 1;

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            topologicalSortUtil(graph, adjVertex, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = vertex;
}

// Topological Sorting function
void topologicalSort(Graph* graph) {
    int stack[MAX], top = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            topologicalSortUtil(graph, i, stack, &top);
        }
    }

    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int vertices = 6;

    Graph* graph = createGraph(vertices);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    // DFS
    printf("DFS: ");
    DFS(graph, 5);
    printf("\n");

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }

    // BFS
    printf("BFS: ");
    BFS(graph, 5);
    printf("\n");

    // Reset visited array for Topological Sort
    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }

    // Topological Sorting
    topologicalSort(graph);

    return 0;
}
