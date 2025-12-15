#include <stdio.h>
int main() {
    int n, start;
    int graph[10][10];
    int visited[10] = {0};
    int stack[10];
    int top = -1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    // Push starting vertex
    stack[++top] = start;
    printf("DFS Traversal: ");
    while(top != -1) {
        int v = stack[top--];

        if(visited[v] == 0) {
            printf("%d ", v);
            visited[v] = 1;
        }
        // Push adjacent vertices in reverse order
        for(int i = n - 1; i >= 0; i--) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
    }
    return 0;
}
