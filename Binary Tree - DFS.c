#include <stdio.h>
#include <stdbool.h>

#define MAX 5

void DFS(int graph[MAX][MAX], int start, bool visited[]);

int main()
{
    int graph[MAX][MAX] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bool visited[MAX] = { false };
    int start = 0;

    printf("DFS Traversal: ");
    DFS(graph, start, visited);

    return 0;
}

void DFS(int graph[MAX][MAX], int start, bool visited[])
{
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < MAX; i++)
    {
        if (graph[start][i] == 1 && visited[i] == false)
        {
            DFS(graph, i, visited);
        }
    }
}
