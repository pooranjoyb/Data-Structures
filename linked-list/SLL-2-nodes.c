//Creating SLL with two nodes

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(int argc, char const *argv[])
{
    struct node *head = NULL, *temp = NULL;
    head = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));

    //first node with its link
    head->data = 10;
    head->link = NULL; 

    //second node with its link
    temp->data = 20;
    temp->link = NULL;

    //connecting head's link to the next node
    head->link = temp;

    //with the head we can access the complete SLL
    printf("Data in the head : %d\n", head->data);
    printf("Data in the temp : %d", (head->link)->data);
    
    // say for the third node we use : ((head->link)->link)->link
    return 0;
}