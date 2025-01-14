#include <stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int  main() {
 FILE *file;

//    printf("\nEner the number of nodes: ");
// scanf("%d", &n);
	 file = fopen("graph.txt", "r");
   	 if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

// Read the number of vertices
    fscanf(file, "%d", &n);
//  printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(file,"%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Represent no edge with a large value
            }
        }
    }

    visited[1] = 1; // Start from the first node
    printf("\n");

    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && visited[i] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as used
    }

    printf("\n\nMinimum cost: %d\n", mincost);
 fclose(file);
return 0;
}
