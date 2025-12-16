


#include <stdio.h>
#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n;

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (adj[v][i] == 1 && !visited[i])
            DFS(i);
}

int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex 1: ");
    DFS(1);
    return 0;
}
