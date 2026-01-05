#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} Node;

typedef struct 
{
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteFirst(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main() 
{
    List *list = initialize();

    insertFirst(list, 5);
    insertFirst(list, 6);
    insertFirst(list, 2);
    insertLast(list, 7);
    insertPos(list, 10, 2);

    printf("Linked List: ");
    display(list);

    deleteFirst(list);
    deleteLast(list);
    deletePos(list, 1);

    printf("After deleting: ");
    display(list);

    printf("Retrieve index 1: %d\n", retrieve(list, 1));
    printf("Locating 5: %d\n", locate(list, 5));

    empty(list);
    free(list);

    return 0;
}

List* initialize() 
{
    List *L = malloc(sizeof(List));
    if (L == NULL) 
    {
        return NULL;
    }

    L->head = NULL;
    L->count = 0;

    return L;
}

void empty(List *list) 
{
    while (list->head != NULL) 
    {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->count = 0;
}

void insertFirst(List *list, int data) 
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        return;
    }

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) 
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) 
    {
        list->head = newNode;
    } 
    else 
    {
        Node *current = list->head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) 
{
    if (index < 0 || index > list->count) 
    {
        return;
    }

    if (index == 0) 
    {
        insertFirst(list, data);
    } 
    else if (index == list->count) 
    {
        insertLast(list, data);
    } 
    else 
    {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) 
        {
            return;
        }

        newNode->data = data;

        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteFirst(List *list) 
{
    if (list->head == NULL) 
    {
        return;
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) 
    {
        return;
    }

    if (list->head->next == NULL) 
    {
        free(list->head);
        list->head = NULL;
    } 
    else 
    {
        Node *current = list->head;
        while (current->next->next != NULL) 
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index) 
{
    if (index < 0 || index >= list->count) 
    {
        return;
    }

    if (index == 0) 
    {
        deleteFirst(list);
    } 
    else 
    {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->count--;
    }
}

int retrieve(List *list, int index) 
{
    if (index < 0 || index >= list->count) 
    {
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) 
    {
        current = current->next;
    }

    return current->data;
}

int locate(List *list, int data) 
{
    Node *current = list->head;
    int index = 0;

    while (current != NULL) 
    {
        if (current->data == data) 
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

void display(List *list) 
{
    Node *current = list->head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL (count: %d)\n", list->count);
}
