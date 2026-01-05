#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char setUnion(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main()
{
    unsigned char A;
    unsigned char B;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);

    insert(&B, 3);
    insert(&B, 4);

    printf("Set A: ");
    display(A);

    printf("Set B: ");
    display(B);

    printf("Union: ");
    display(setUnion(A, B));

    printf("Intersection: ");
    display(intersection(A, B));

    printf("Difference: ");
    display(difference(A, B));

    return 0;
}

void initialize(unsigned char *set)
{
    *set = 0;
}

void insert(unsigned char *set, int element)
{
    *set = *set | (1 << element);
}

void delete(unsigned char *set, int element)
{
    *set = *set & ~(1 << element);
}

bool find(unsigned char set, int element)
{
    return (set & (1 << element)) != 0;
}

unsigned char setUnion(unsigned char A, unsigned char B)
{
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B)
{
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B)
{
    return A & ~B;
}

void display(unsigned char set)
{
    for (int i = 0; i < 8; i++)
    {
        if (find(set, i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
