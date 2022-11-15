#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert_end(int data){
    struct node *temp = head, *newNode;
    newNode = malloc(sizeof(struct node)); 
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; 
}

void delete_end(){
    if (head == NULL)
    {
        printf("List empty");
    }
    else{
        struct node *p = head, *q;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
    
}

void display(){
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    } 
}
void create_node(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    head = temp;
}

int main(){
    create_node(15);
    insert_end(10);
    insert_end(12);
    insert_end(13);
    insert_end(14);
    display();
    printf("\n");
    delete_end();
    display();
    return 0;
}