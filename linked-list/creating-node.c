#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(int argc, char const *argv[])
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->link = NULL;

    printf("Data in the node : %d", head->data);
    return 0;
}

