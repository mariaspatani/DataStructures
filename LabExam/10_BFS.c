#include<stdio.h>
#include<string.h>

int main(){
    int n;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    
    int queue[100], rear = 0, front = 0;
    int matrix[100][100], visited[20];
    char vertices[100][20], startingvertex[20];
    
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Enter the vertices:\n");
    for(int i=0; i<n; i++){
        scanf("%s", vertices[i]);
    }

    printf("Enter the starting vertex: ");
    scanf("%s", startingvertex);
    
    int startingIndex = -1;

    // FIXED LOOP
    for(int i = 0; i < n; i++){
        if(strcmp(vertices[i], startingvertex) == 0){
            startingIndex = i;
            break;
        }
    }

    if(startingIndex == -1){
        printf("Invalid Vertex!\n");
        return 0;
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    
    queue[rear++] = startingIndex;
    visited[startingIndex] = 1;

    printf("BFS: ");
    while(front < rear){
        int current = queue[front++];
        printf("%s ", vertices[current]);

        for(int i = 0; i < n; i++){
            if(matrix[current][i] == 1 && visited[i] == 0){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    
    printf("\n");
    return 0;
}
