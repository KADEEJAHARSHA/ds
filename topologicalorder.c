#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Global variables
int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to store graph
int visited[MAX_VERTICES]; // Visited array
int topo[MAX_VERTICES]; // Topological order
int topoIndex = 0;

// Function to perform DFS
void dfs(int vertex, int n) {
    visited[vertex] = 1; // Mark the current vertex as visited

    // Visit all the adjacent vertices of the current vertex
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n); // Recursive call
        }
    }

    // Add vertex to topo array after processing all its adjacent vertices
    topo[topoIndex++] = vertex;
}

// Function to perform topological sort
void topologicalSort(int n) {
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Call DFS on all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    // Print topological order (reverse of the processed order)
    printf("Topological Order: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int n, m; // n is number of vertices, m is number of edges
    int u, v; // u and v are the vertices that form an edge u -> v

    // Read number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read the edges and populate the adjacency matrix
    printf("Enter edges (u v) where u -> v: \n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Edge from u to v
    }

    // Perform topological sort
    topologicalSort(n);

    return 0;
}

