#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES];
int vertices;

// --- BFS Implementation (using a simple queue array) ---
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_VERTICES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start_node) {
    int i, current_node;

    for(i = 0; i < vertices; i++) visited[i] = 0;
    front = -1; rear = -1; // Reset queue

    enqueue(start_node);
    visited[start_node] = 1;
    printf("BFS Traversal: ");

    while(front != -1 && front <= rear) {
        current_node = dequeue();
        printf("%d ", current_node);

        for(i = 0; i < vertices; i++) {
            if(graph[current_node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// --- DFS Implementation (recursive) ---
void dfs(int current_node) {
    int i;
    printf("%d ", current_node);
    visited[current_node] = 1;

    for(i = 0; i < vertices; i++) {
        if(graph[current_node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void run_dfs(int start_node) {
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    dfs(start_node);
    printf("\n");
}

void build_graph() {
    int i, j, edges;
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid vertex count. Using default %d.\n", MAX_VERTICES);
        vertices = MAX_VERTICES;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination, e.g., 0 1):\n");
    for (int k = 0; k < edges; k++) {
        int u, v;
        printf("Edge %d: ", k + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1;
            graph[v][u] = 1; // Undirected
        } else {
            printf("Invalid vertices for edge, skipping.\n");
            k--;
        }
    }
}

int main() {
    build_graph();
    int start;

    printf("Enter the starting vertex for traversals (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    if (start >= 0 && start < vertices) {
        bfs(start);
        run_dfs(start);
    } else {
        printf("Invalid start vertex.\n");
    }
    return 0;
}
