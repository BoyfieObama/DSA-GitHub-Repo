#include <stdio.h>
#define MAX 10

typedef struct 
{
    int elem[MAX];
    int count;
} List;

List initializeList();
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main()
{
    List L;
    L = initializeList();
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 2);

    printf("Initial list:\n");
    display(L);

    L = deletePos(L, 1);
    printf("\nAfter deleting index 1:\n");
    display(L);

    int pos = locate(L, 30);
    printf("\nLocation of 30: %d\n", pos);

    L = insertSorted(L, 15);
    printf("\nAfter inserting 15 in sorted order:\n");
    display(L);
}

List initializeList()
{
    List L;
    L.count = 0;
    for (int i = 0; i < MAX; i++)
    {
        L.elem[i] = -1;
    }
    return L;
}

List insertPos(List L, int data, int position)
{
    if (L.count >= MAX)
    {
        printf("List is full\n");
        return L;
    }
    if (position < 0 || position > L.count)
    {
        printf("Invalid position %d\n", position);
        return L;
    }

    for (int i = L.count; i > position; i--)
    {
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position)
{
    if (position < 0 || position >= L.count)
    {
        printf("Invalid delete position %d\n", position);
        return L;
    }

    for (int i = position; i < L.count - 1; i++)
    {
        L.elem[i] = L.elem[i + 1];
    }
    L.elem[L.count - 1] = -1;
    L.count--;
    return L;
}

int locate(List L, int data)
{
    for (int i = 0; i < L.count; i++)
    {
        if (L.elem[i] == data)
        {
            return i;
        }
    }
    return -1; //error sigma
}

List insertSorted(List L, int data)
{
    if (L.count >= MAX)
    {
        printf("List is full\n");
        return L;
    }

    int pos = 0;
    while (pos < L.count && L.elem[pos] < data)
    {
        pos++;
    }
    L = insertPos(L, data, pos);
    return L;
}

void display(List L)
{
    printf("List (count = %d): ", L.count);
    for (int i = 0; i < L.count; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
