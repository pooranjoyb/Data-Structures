#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode()
{
    int x;
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));
    printf("Enter data (-1 for NULL) : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    newNode->data = x;
    printf("Enter the left child of %d : ", newNode->data);
    newNode->left = createNode();

    printf("Enter the right child of %d : ", newNode->data);
    newNode->right = createNode();

    return newNode;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = createNode(1);
    preorder(root);
    return 0;
}