#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main()
{
    Stack *s = initialize();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    printf("Popped: %d\n", pop(s));
    printf("Peek: %d\n", peek(s));

    display(s);

    free(s);
    return 0;
}

Stack* initialize()
{
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }

    s->top = NULL;

    return s;
}

bool isFull(Stack* s)
{
    return false;
}

bool isEmpty(Stack* s)
{
    return s->top == NULL;
}

void push(Stack* s, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    Node *temp = s->top;
    int value = temp->data;

    s->top = temp->next;
    free(temp);

    return value;
}

int peek(Stack* s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->top->data;
}

void display(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
