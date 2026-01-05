#include <stdio.h>

#define MAX 4

typedef struct
{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct
{
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main()
{
    VHeap V;
    List L;

    initialize(&V);
    L = -1;

    insertFirst(&L, &V, 3);
    insertLast(&L, &V, 5);
    insertSorted(&L, &V, 4);
    insertFirst(&L, &V, 2);

    display(L, V);

    delete(&L, &V, 4);
    display(L, V);

    return 0;
}

void initialize(VHeap *V)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        V->H[i].next = i + 1;
    }

    V->H[MAX - 1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap* V)
{
    int index = V->avail;

    if (index != -1)
    {
        V->avail = V->H[index].next;
    }

    return index;
}

void deallocSpace(VHeap* V, int index)
{
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem)
{
    int index = allocSpace(V);
    if (index == -1)
    {
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = *L;
    *L = index;
}

void insertLast(int* L, VHeap* V, int elem)
{
    int index = allocSpace(V);
    if (index == -1)
    {
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = -1;

    if (*L == -1)
    {
        *L = index;
    }
    else
    {
        int curr = *L;
        while (V->H[curr].next != -1)
        {
            curr = V->H[curr].next;
        }
        V->H[curr].next = index;
    }
}

void insertPos(int* L, VHeap* V, int elem)
{
    if (*L == -1)
    {
        insertFirst(L, V, elem);
        return;
    }

    int index = allocSpace(V);
    if (index == -1)
    {
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = V->H[*L].next;
    V->H[*L].next = index;
}

void insertSorted(int* L, VHeap* V, int elem)
{
    int *trav = L;

    while (*trav != -1 && V->H[*trav].elem < elem)
    {
        trav = &V->H[*trav].next;
    }

    int index = allocSpace(V);
    if (index == -1)
    {
        return;
    }

    V->H[index].elem = elem;
    V->H[index].next = *trav;
    *trav = index;
}

void delete(int* L, VHeap* V, int elem)
{
    int *trav = L;

    while (*trav != -1 && V->H[*trav].elem != elem)
    {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1)
    {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem)
{
    int *trav = L;

    while (*trav != -1)
    {
        if (V->H[*trav].elem == elem)
        {
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        }
        else
        {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V)
{
    int curr = L;

    while (curr != -1)
    {
        printf("%d ", V.H[curr].elem);
        curr = V.H[curr].next;
    }
    printf("\n");
}
