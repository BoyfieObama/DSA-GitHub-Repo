#include <stdio.h>
#include <stdbool.h>

#define MAX 5

void BFS(int graph[MAX][MAX], int start);

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

    int start = 0;

    printf("BFS Traversal: ");
    BFS(graph, start);

    return 0;
}

void BFS(int graph[MAX][MAX], int start)
{
    bool visited[MAX] = { false };
    int queue[MAX];
    int front = 0;
    int rear = 0;

    visited[start] = true;
    queue[rear] = start;
    rear++;

    while (front < rear)
    {
        int current = queue[front];
        front++;

        printf("%d ", current);

        for (int i = 0; i < MAX; i++)
        {
            if (graph[current][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                queue[rear] = i;
                rear++;
            }
        }
    }
}
