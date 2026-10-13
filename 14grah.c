/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************

Ex No:14
Aim: Implementation  of  graphs  and  graph  traversals.

**********Algorithm************

Step1:Start
Step2:Enter the number of vertices and edges.
Step3:Create the graph using an adjacency matrix.
Step4:Enter all edges.
Step5:Enter the starting vertex.
Step6:BFS: Use a queue and visit the vertices level by level.
Step7:DFS: Use recursion and visit vertices deeply one by one.
Step8:Print the BFS and DFS traversal.
Step9:Stop.

******Source code******
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // For undirected graph
}

void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1) return 0;
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1) return 0;

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter start vertex for traversal: ");
    if (scanf("%d", &start) != 1) return 0;

    BFS(&g, start);
    DFS(&g, start);

    return 0;
}
/* 
Output

Enter number of vertices: 5
Enter number of edges: 5
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 3
Enter edge (source destination): 1 4
Enter edge (source destination): 2 4
Enter start vertex for traversal: 0

BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2
*/
