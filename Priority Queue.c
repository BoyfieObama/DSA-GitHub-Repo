#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int count;
} PriorityQueue;

PriorityQueue* initialize();
bool isFull(PriorityQueue* pq);
bool isEmpty(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, int value);
int dequeue(PriorityQueue* pq);
int front(PriorityQueue* pq);
void display(PriorityQueue* pq);

int main()
{
    PriorityQueue *pq = initialize();
    int choice, value;

    do
    {
        printf("\n-Priority Queue System (smaller number gets higher priority)-");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Front");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(pq, value);
                break;

            case 2:
                value = dequeue(pq);
                if (value != -1)
                {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                value = front(pq);
                if (value != -1)
                {
                    printf("Front: %d\n", value);
                }
                break;

            case 4:
                display(pq);
                break;
        }

    } 
    while (choice != 5);

    return 0;
}

PriorityQueue* initialize()
{
    static PriorityQueue pq;

    pq.count = 0;
    return &pq;
}

bool isFull(PriorityQueue* pq)
{
    return pq->count == MAX;
}

bool isEmpty(PriorityQueue* pq)
{
    return pq->count == 0;
}

void enqueue(PriorityQueue* pq, int value)
{
    if (isFull(pq))
    {
        printf("Priority Queue is full\n");
        return;
    }

    int i = pq->count - 1;

    while (i >= 0 && pq->data[i] > value)
    {
        pq->data[i + 1] = pq->data[i];
        i--;
    }

    pq->data[i + 1] = value;
    pq->count++;
}

int dequeue(PriorityQueue* pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty\n");
        return -1;
    }

    int value = pq->data[0];

    for (int i = 1; i < pq->count; i++)
    {
        pq->data[i - 1] = pq->data[i];
    }

    pq->count--;
    return value;
}

int front(PriorityQueue* pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty\n");
        return -1;
    }

    return pq->data[0];
}

void display(PriorityQueue* pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty\n");
        return;
    }

    for (int i = 0; i < pq->count; i++)
    {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}
