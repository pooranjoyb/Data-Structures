#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

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

void postorder(struct node* root){
    if (root == NULL)
    {
        return ;
    }
    postorder(root->left);
    printf("The smallest node in BST is : %d",root->data);
    exit(1);

}

int main(){
    struct node *root = NULL;
    root = createNode();
    postorder(root);
}