#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;
int vertices;

void push(int item) {
    stack[++top] = item;
}

void topological_sort_util(int current_node) {
    visited[current_node] = 1;

    for(int i = 0; i < vertices; i++) {
        // Check for edge to unvisited neighbor
        if(graph[current_node][i] == 1 && visited[i] == 0) {
            topological_sort_util(i);
        }
    }
    // Push current vertex to stack only after all its dependencies are processed
    push(current_node);
}

void topological_sort() {
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    top = -1;

    // Call the recursive helper function for all unvisited vertices
    for(int i = 0; i < vertices; i++) {
        if(visited[i] == 0) {
            topological_sort_util(i);
        }
    }

    printf("Topological Sort: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

void build_graph() {
    int edges;
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid vertex count. Using default %d.\n", MAX_VERTICES);
        vertices = MAX_VERTICES;
    }

    printf("Enter number of DIRECTED edges (Ensure no cycles!): ");
    scanf("%d", &edges);

    printf("Enter edges (source destination, e.g., 0 1):\n");
    for (int k = 0; k < edges; k++) {
        int u, v;
        printf("Edge %d: ", k + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1; // Directed edge from u to v
        } else {
            printf("Invalid vertices for edge, skipping.\n");
            k--;
        }
    }
}

int main() {
    build_graph();
    topological_sort();
    return 0;
}
