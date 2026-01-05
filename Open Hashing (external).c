#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int hash(int key);
void insert(int key);
void delete(int key);
void display();

int main()
{
    insert(10);
    insert(15);
    insert(20);
    insert(7);

    display();

    delete(15);
    display();

    return 0;
}

int hash(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hash(key);
    char filename[20];

    sprintf(filename, "bucket%d.dat", index);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        return;
    }

    fprintf(fp, "%d\n", key);
    fclose(fp);
}

void delete(int key)
{
    int index = hash(key);
    char filename[20];
    char tempname[20];

    sprintf(filename, "bucket%d.dat", index);
    sprintf(tempname, "temp.dat");

    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen(tempname, "w");

    if (fp == NULL || temp == NULL)
    {
        return;
    }

    int value;
    while (fscanf(fp, "%d", &value) != EOF)
    {
        if (value != key)
        {
            fprintf(temp, "%d\n", value);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename(tempname, filename);
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
}
