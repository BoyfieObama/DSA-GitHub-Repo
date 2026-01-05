#include <stdio.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct
{
    int table[SIZE];
} HashTable;

void initialize(HashTable *H);
int hash(int key);
void insert(HashTable *H, int key);
int search(HashTable H, int key);
void delete(HashTable *H, int key);
void display(HashTable H);

int main()
{
    HashTable H;

    initialize(&H);

    insert(&H, 10);
    insert(&H, 20);
    insert(&H, 30);
    insert(&H, 21);

    display(H);

    delete(&H, 20);
    display(H);

    return 0;
}

void initialize(HashTable *H)
{
    for (int i = 0; i < SIZE; i++)
    {
        H->table[i] = EMPTY;
    }
}

int hash(int key)
{
    return key % SIZE;
}

void insert(HashTable *H, int key)
{
    int index = hash(key);

    while (H->table[index] != EMPTY && H->table[index] != DELETED)
    {
        index = (index + 1) % SIZE;
    }

    H->table[index] = key;
}

int search(HashTable H, int key)
{
    int index = hash(key);
    int start = index;

    while (H.table[index] != EMPTY)
    {
        if (H.table[index] == key)
        {
            return index;
        }

        index = (index + 1) % SIZE;
        if (index == start)
        {
            break;
        }
    }

    return -1;
}

void delete(HashTable *H, int key)
{
    int index = search(*H, key);

    if (index != -1)
    {
        H->table[index] = DELETED;
    }
}

void display(HashTable H)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: %d\n", i, H.table[i]);
    }
}
