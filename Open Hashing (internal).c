#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *table[SIZE];
} HashTable;

void initialize(HashTable *H);
int hash(int key);
void insert(HashTable *H, int key);
void delete(HashTable *H, int key);
void display(HashTable H);

int main()
{
    HashTable H;

    initialize(&H);

    insert(&H, 10);
    insert(&H, 15);
    insert(&H, 20);
    insert(&H, 7);

    display(H);

    delete(&H, 15);
    display(H);

    return 0;
}

void initialize(HashTable *H)
{
    for (int i = 0; i < SIZE; i++)
    {
        H->table[i] = NULL;
    }
}

int hash(int key)
{
    return key % SIZE;
}

void insert(HashTable *H, int key)
{
    int index = hash(key);

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }

    newNode->data = key;
    newNode->next = H->table[index];
    H->table[index] = newNode;
}

void delete(HashTable *H, int key)
{
    int index = hash(key);
    Node *curr = H->table[index];
    Node *prev = NULL;

    while (curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL)
    {
        if (prev == NULL)
        {
            H->table[index] = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void display(HashTable H)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        Node *curr = H.table[i];
        while (curr != NULL)
        {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}
