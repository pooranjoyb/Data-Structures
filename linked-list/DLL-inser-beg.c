#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert_beg(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void create_node(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    head = temp;
}

int main(){
    create_node(15);
    insert_beg(10);
    insert_beg(12);
    insert_beg(13);
    insert_beg(14);
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    } 
    return 0;
}