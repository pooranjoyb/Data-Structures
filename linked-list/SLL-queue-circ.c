#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int data)
{

    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if ((f == NULL) && r == NULL)
    {
        f = r = newNode;
        r->next = f;
    }
    else
    {

        r->next = newNode;
        r = newNode;
        newNode->next = f;
    }
}

void dequeue()
{
    struct node *temp = f;
    if ((f == NULL) && r == NULL)
    {
        printf("UNDERFLOW");
    }
    else if (f == r)
    {
        f = r = NULL;
        free(temp);
    }
    f = f->next;
    r->next = f;
    free(temp);
}

void disp()
{
    struct node *temp = f;
    while (f != r)
    {
        printf("%d\t", f->data);
        f = f->next;
    }
}

int main(){
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    dequeue();
    enqueue(15);
    disp();
}
