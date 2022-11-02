#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert_mid(int data, int pos)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->prev = newNode->next = NULL;
    newNode->data = data;
    struct node *ptr = head, *q = NULL;
    int i = 1;
    while ((i != pos) && (ptr->next != NULL))
    {
        q = ptr;
        ptr = ptr->next;
        i++;
    }
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    else if(pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        q->next = newNode;
        ptr->prev = newNode;
        newNode->prev = q;
        newNode->next = ptr;
    }
}

void insert_end(int data)
{
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
void display()
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
void create_node(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    head = temp;
}

int main()
{
    create_node(15);
    insert_end(10);
    insert_end(12);
    insert_end(13);
    insert_mid(100, 3);
    display();
    return 0;
}