#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int items[MAX];
    int count;
} List;

typedef struct
{
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main()
{
    Queue *q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", q->list.items[q->rear]);

    display(q);

    free(q);
    return 0;
}

Queue* initialize()
{
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        return NULL;
    }

    q->front = 0;
    q->rear = -1;
    q->list.count = 0;

    return q;
}

bool isFull(Queue* q)
{
    return q->list.count == MAX;
}

bool isEmpty(Queue* q)
{
    return q->list.count == 0;
}

void enqueue(Queue* q, int value)
{
    if (isFull(q))
    {
        return;
    }

    q->rear++;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    int value = q->list.items[q->front];
    q->front++;
    q->list.count--;

    return value;
}

int front(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    return q->list.items[q->front];
}

void display(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->list.items[i]);
    }
    printf("\n");
}
