#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

void inorder(struct node *root)
{

    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node *createNode()
{
    struct node *newNode;
    int x;
    newNode = malloc(sizeof(struct node));
    printf("\nEnter data (-1 for NULL ) : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    newNode->data = x;
    printf("\nEnter left child of %d : ", newNode->data);
    newNode->left = createNode();
    printf("\nEnter right child of %d : ", newNode->data);
    newNode->right = createNode();

    return newNode;
}

int main()
{
    struct node *root = NULL;
    root = createNode();
    printf("Inorder");
    inorder(root);
    printf("Postorder");
    postorder(root);
    printf("Preorder");
    preorder(root);
    insert(root, 11);
}