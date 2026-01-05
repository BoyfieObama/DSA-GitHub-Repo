#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* insert(Node* root, int value);
bool search(Node* root, int value);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nSearch 40: %s", search(root, 40) ? "Found" : "Not Found");
    printf("\nSearch 90: %s\n", search(root, 90) ? "Found" : "Not Found");

    return 0;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int value)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
