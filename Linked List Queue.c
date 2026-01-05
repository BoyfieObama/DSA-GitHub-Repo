#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct
{
    Node* front;
    Node* rear;
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
    printf("Rear: %d\n", q->rear->data);

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

    q->front = NULL;
    q->rear = NULL;

    return q;
}

bool isFull(Queue* q)
{
    return false;
}

bool isEmpty(Queue* q)
{
    return q->front == NULL;
}

void enqueue(Queue* q, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    q->front = temp->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int front(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    return q->front->data;
}

void display(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
