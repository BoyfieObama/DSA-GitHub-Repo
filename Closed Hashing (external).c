#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define BUCKET_SIZE 2

int hash(int key);
void initialize();
void insert(int key);
void display();

int main()
{
    initialize();

    insert(10);
    insert(15);
    insert(20);
    insert(7);
    insert(12);
    insert(17);

    display();

    return 0;
}

int hash(int key)
{
    return key % SIZE;
}

void initialize()
{
    char filename[20];

    for (int i = 0; i < SIZE; i++)
    {
        sprintf(filename, "bucket%d.dat", i);
        FILE *fp = fopen(filename, "w");
        fclose(fp);
    }

    FILE *overflow = fopen("overflow.dat", "w");
    fclose(overflow);
}

void insert(int key)
{
    int index = hash(key);
    char filename[20];

    sprintf(filename, "bucket%d.dat", index);

    FILE *fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        return;
    }

    int count = 0;
    int value;

    while (fscanf(fp, "%d", &value) != EOF)
    {
        count++;
    }

    if (count < BUCKET_SIZE)
    {
        fprintf(fp, "%d\n", key);
        fclose(fp);
    }
    else
    {
        fclose(fp);
        FILE *overflow = fopen("overflow.dat", "a");
        if (overflow == NULL)
        {
            return;
        }
        fprintf(overflow, "%d\n", key);
        fclose(overflow);
    }
}

void display()
{
    char filename[20];

    for (int i = 0; i < SIZE; i++)
    {
        sprintf(filename, "bucket%d.dat", i);
        FILE *fp = fopen(filename, "r");

        printf("Bucket %d: ", i);

        if (fp == NULL)
        {
            printf("EMPTY\n");
            continue;
        }

        int value;
        while (fscanf(fp, "%d", &value) != EOF)
        {
            printf("%d ", value);
        }
        printf("\n");
        fclose(fp);
    }

    printf("Overflow: ");
    FILE *overflow = fopen("overflow.dat", "r");

    if (overflow != NULL)
    {
        int value;
        while (fscanf(overflow, "%d", &value) != EOF)
        {
            printf("%d ", value);
        }
        fclose(overflow);
    }
    printf("\n");
}
