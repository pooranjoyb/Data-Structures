//traversing & counting number of nodes in the linked-list

// TIME COMPLEXITY for LL : O(n)
// TIME COMPLEXITY for ARRAY : O(n)

#include<stdio.h>
#include<stdlib.h>

void count_of_nodes();

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL; 

void count_of_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("LL is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;        
    }

    printf("Total nodes are : %d", count);
}

int main(void)
{
    struct node *temp = NULL, *temp1 = NULL;
    head = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));
    temp1 = malloc(sizeof(struct node));
    

    //first node with its link
    head->data = 10;
    head->link = NULL; 

    //second node with its link
    temp->data = 20;
    temp->link = NULL;

    //third node with its link
    temp1->data = 30;
    temp1->link = NULL;

    //connecting head's link to the next node temp
    head->link = temp;

    //connecting temp's link to the next node temp1
    temp->link = temp1;

    count_of_nodes();

    return 0;
}
